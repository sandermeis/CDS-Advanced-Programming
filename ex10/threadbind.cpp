#include <pybind11/pybind11.h>

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <vector>

namespace py = pybind11;

class Channel {
   public:
    Channel(int max_time, int n_iterations, int prod, int cons) :
    _max_time(max_time),
    _n_iterations(n_iterations),
    distr(0.,
    _max_time),
    finished(false),
    n_producers(prod),
    n_consumers(cons){}

    void start() {
        iter=0;
        emp=false;
        for (int i = 0; i < n_producers; ++i) {
            threads.push_back(std::thread(&Channel::produce, this));
        }
        for (int i = 0; i < n_consumers; ++i) {
            threads.push_back(std::thread(&Channel::consume, this));
        }
        finish();
    }

   private:
    // Parameters
    int _max_time;
    int _n_iterations;
    int n_producers;
    int n_consumers;
    std::queue<double> q;
    int iter;

    // Multithreading
    std::mutex mu;
    std::vector<std::thread> threads;
    std::condition_variable cv;
    bool finished;
    bool emp;

    // Randoms
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<int> distr;

    void finish() {
        for (auto& t : threads) {
            t.join();
        }
    }

    void produce() {
        double a = 3.14159;
        while (iter<_n_iterations) {
            int n = distr(mt);
            {
                std::unique_lock<std::mutex> l(mu);
                q.push(a);
                std::cout << "Thread " << std::this_thread::get_id() << " ins a value, size: " << q.size() << ", iteration " << iter << std::endl;
                iter++;
                cv.notify_one();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(n));
        }
        finished=true;
    }

    void consume() {
        while (!(finished && emp)) {
            {              
                std::unique_lock<std::mutex> l(mu);
                cv.wait(l, [this] { if (!finished) return !q.empty(); else return true;}); // false=wait
                if (finished && emp) {break;}
                q.pop();
                emp=q.empty();
                std::cout << "Thread " << std::this_thread::get_id() << " del a value, size: " << q.size() << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

PYBIND11_MODULE(threadbind, m) {
    m.doc() = "pybind11 threadbind plugin";  // optional module docstring

    py::class_<Channel>(m, "Channel")
            .def(py::init<int, int, int, int>())
            .def("start", &Channel::start);
}