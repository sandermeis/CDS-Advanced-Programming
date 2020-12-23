// a) Sometimes gives "Parallel World!"
// Sometimes "Hello Parallel World!"

#include <iostream>
#include <string>
#include <thread>



void f1() {
    std::cout << "Hello ";
}

void f2(const std::string& s) {
    std::cout << s << std::endl;
}

int main() {
    std::thread t1(f1);
    std::thread t2{f2, "Parallel World!"};
    

    
    t1.join();
    t2.join();
    return 0;
}