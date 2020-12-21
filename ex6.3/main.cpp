//
//
// d) Explicit copy constructor and destructors are not needed anymore

#include <iostream>
#include "Stack.hh"

int main() {
    Stack<double> s(80, 0);

    // Write doubles into Stack
    int i;
    for (i = 0; i < 10; i++) {
        //std::cout << "pushing value " << i * i << " in stack" << std::endl;
        s.push(i * i);
    }
    
    Stack<double> sclone=s;

    std::cout << "Inspecting s" << std::endl;
    s.inspect();
    std::cout << "Inspecting sclone" << std::endl;
    sclone.inspect();

    // Read doubles back from stack
    while (!s.empty()) {
        double val = s.pop();
        //std::cout << "popping value " << val << " from stack" << std::endl;
    }
    std::cout << "Inspecting s" << std::endl;
    s.inspect();
    std::cout << "Inspecting sclone" << std::endl;
    sclone.inspect();

    for (int i = 0; i < 5; i++) {
       s.push(100 * i);
    }

    std::cout << "Inspecting s" << std::endl;
    s.inspect();
    std::cout << "Inspecting sclone" << std::endl;
    sclone.inspect();

    return 0;
}