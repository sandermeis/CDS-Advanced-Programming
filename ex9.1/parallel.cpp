//
// c) Prints the string while other thread is waiting 2s
//
// d) Does not work if not using std::ref, passing by value seems OK though

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

void f1(std::vector<std::string>& s) {
    std::cout << s[0] << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << s[1] << std::endl;
}

void f2(std::string& s) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << s << std::endl;
}

int main() {
    std::vector<std::string> s1{"Hello ","World"};
    std::string s2 = "Stop: Hammer time!";
    std::thread t1(f1, std::ref(s1));
    std::thread t2{f2, std::ref(s2)};
    
    t1.join();
    t2.join();
    return 0;
}