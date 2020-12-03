//
// Do you understand what happens?
//
// The stack fills to 80, then the memory is full and no more values can be added.
//

#include <iostream>
#include "input/Stack.h"

int main() {
    Stack s;

    // Write doubles into Stack
    int i;
    for (i = 0; i < 100; i++) {
        //std::cout << "pushing value " << i * i << " in stack" << std::endl;
        s.push(i * i);
    }

    s.inspect();

    // Count doubles in fifo
    std::cout << s.nitems() << " values in stack" << std::endl;

    // Read doubles back from fifo
    while (!s.empty()) {
        double val = s.pop();
        //std::cout << "popping value " << val << " from stack" << std::endl;
    }
    s.inspect();
    return 0;
}