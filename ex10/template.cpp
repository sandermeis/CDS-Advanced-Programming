//
// c) Prints the string while other thread is waiting 2s
//
// d) Does not work if not using std::ref, passing by value seems OK though

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <vector>

class Channel {
   public:
    Channel(int max_time, int n_iterations):
    _max_time(max_time),
    _n_iterations(n_iterations),
    distr(0., _max_time)
    {

    }

    void start() {
        for (int i = 0; i < 5; ++i) {
            some_threads.push_back(std::thread(&Channel::produce, this));
            some_threads.push_back(std::thread(&Channel::consume, this));
        }
        finish();
    }

   private:
    int _max_time;
    int _n_iterations;
    std::mutex mu;
    std::queue<double> q;
    std::vector<std::thread> some_threads;

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<int> distr;

    // bool some_condition;
    // std::condition_variable cv;

    void finish() {
        for (auto& t : some_threads) {
            t.join();
        }
    }

    void produce() {
        double a = 3.14159;
        q.push(a);
        q.push(a);
        q.push(a);
        while (true) {
            int n = distr(mt);
            std::this_thread::sleep_for(std::chrono::milliseconds(n));
            {
                std::unique_lock<std::mutex> l(mu);
                q.push(a);
                std::cout << "inserted a value" << std::endl
                          << "size: " << q.size() << std::endl;
                // cv.notify_one();
            }
        }
    }

    void consume() {
        while (true) {
            {
                std::unique_lock<std::mutex> l(mu);
                // cv.wait(l, []{ return !q.empty(); });

                q.pop();
                std::cout << "deleted a value" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

int main() {
    Channel c(3000, 10);
    c.start();
    return 0;

}