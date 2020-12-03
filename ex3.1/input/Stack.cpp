#include <iostream>
#include "Stack.h"

// Constructor
Stack::Stack(){
    Stack::init();
}

// Desstructor
Stack::~Stack(){
}

// Methods
void Stack::push(double c) {
    if (full()) {
        std::cout << "Stack::push() Error: stack is full" << std::endl;
        return;
    }
    s[count++] = c;
}

void Stack::inspect() {

    std::cout << "TOP" << std::endl;
    std::cout << "| " << "P" << " | " << "V" << std::endl;
    std::cout << "-------" << std::endl;
    for (int i = count-1;i>=0;i--) {
        std::cout << "| " << i << " | " << s[i] << std::endl;
    }
    std::cout << "-------" << std::endl;
    std::cout << "BOTTOM" << std::endl;
}

double Stack::pop() {
    if (empty()) {
        std::cout << "Stack::pop() Error: stack is empty" << std::endl;
        return 0;
    }
    return s[--count];
}
