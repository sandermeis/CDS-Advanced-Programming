#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <vector>

std::random_device d;
std::mt19937 mt(d());
int t_max = 3000;
std::uniform_int_distribution<> distr(0., t_max);


std::mutex m;
std::condition_variable cv;
std::queue<double> q;

void some_producer() {
    double a = 3.14159;
    q.push(a);q.push(a);q.push(a);
    while (true) {
        int n = distr(mt);
        std::this_thread::sleep_for(std::chrono::milliseconds(n));
        {
            std::unique_lock<std::mutex> l(m);
            q.push(a);
            std::cout << "inserted a value" << std::endl
                      << "size: " << q.size() << std::endl;
            cv.notify_one();
        }
    }
}

void some_consumer() {
    while (true) {
        {
            std::unique_lock<std::mutex> l(m);
            cv.wait(l, []{ return !q.empty(); });

            q.pop();
            std::cout << "deleted a value" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    std::thread t1(some_producer);
    std::thread t2(some_consumer);

    t1.join();
    t2.join();
    return 0;
}