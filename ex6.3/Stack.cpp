#include "Stack.hh"
#include <iostream>

template<class T>
Stack<T>::Stack(T def): count(0), s(80,def) {};

template<class T>
Stack<T>::Stack(int sz,T def): count(0), s(sz,def) {};

template<class T>
void Stack<T>::push(T c) {
    if (full()) {
        std::cout << "Stack::push() Error: stack is full, assigning extra space" << std::endl;
        s.resize(s.size()+10);  // Grows by 10
    }
    s[count++] = c;
}

template<class T>
void Stack<T>::inspect() {
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

template<class T>
T Stack<T>::pop() {
    if (empty()) {
        std::cout << "Stack::pop() Error: stack is empty" << std::endl;
        return 0;
    }
    return s[--count];
}