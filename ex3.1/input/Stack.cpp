#include "Stack.h"

#include <iostream>

// Constructor
Stack::Stack() {
    count=0;
    LEN=80;
    s = new double[LEN];
}

// Specifying an initial size is useful because when you use less than the default initial, memory is wasted, when you use more,
// time is wasted by growing the array
Stack::Stack(int sz) {
    count = 0;
    LEN = sz;
    s = new double[LEN];
}

// Destructor
Stack::~Stack() {
    delete[] s;
}

// Methods
//
// Large increment size: risk that the vector does not use the extra space
// Small increment size: have to assign and copy often
//
// Reasonal increase would be to double it, but it depends a lot on the application of Stack
//
void Stack::push(double c) {
    if (full()) {
        std::cout << "Stack::push() Error: stack is full, assigning extra space" << std::endl;
        grow(LEN); // Grows by amount LEN, so double it
    }
    s[count++] = c;
}

void Stack::inspect() {
    std::cout << "TOP" << std::endl;
    std::cout << "| "
              << "P"
              << " | "
              << "V" << std::endl;
    std::cout << "-------" << std::endl;
    for (int i = count - 1; i >= 0; i--) {
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

void Stack::grow(int delta) {
    double* temp = new double[LEN + delta];
    for (int i = 0; i < LEN; i++) {
        temp[i] = s[i];
    }
    LEN += delta;
    delete[] s;
    this->s = temp;
}