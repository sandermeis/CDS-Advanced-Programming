#include <chrono>
#include <condition_variable>
#include <deque>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Channel {
   public:
    Channel() {
        start();
    }

    void add() {
        while (true) {
            int num = std::rand() % 100;
            {
                std::unique_lock<std::mutex> locker(mu);
                cond.wait(locker, [this]() { return buffer_.size() < size_; });
                buffer_.push_back(num);
                std::cout << "Produced: " << num << std::endl;
            }
            cond.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    int remove() {
        while (true) {
            {
                std::unique_lock<std::mutex> locker(mu);
                cond.wait(locker, [this]() { return buffer_.size() > 0; });
                int num = buffer_.back();
                buffer_.pop_back();
                std::cout << "Consumed: " << num << std::endl;
            }
            cond.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
        }
    }

    void start() {
        some_threads.push_back(std::thread(&Channel::add, this));
        some_threads.push_back(std::thread(&Channel::remove, this));
        finish();
    }

    void finish() {
        for (auto& t : some_threads) {
            t.join();
        }
    }

   private:
    std::mutex mu;
    std::condition_variable cond;
    std::vector<std::thread> some_threads;

    std::deque<int> buffer_;
    const unsigned int size_ = 10;
};

int main() {
    Channel b;

    return 0;
}