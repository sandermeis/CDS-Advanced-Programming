#include "Stack.hh"
#include <iostream>

template<class T>
Stack<T>::Stack(T def): s(def) {};

template<class T>
void Stack<T>::push(T c) {
    s.push_back(c);
}

template<class T>
void Stack<T>::inspect() {
    std::cout << "TOP" << std::endl;
    std::cout << "| "
              << "V" << std::endl;
    std::cout << "-----" << std::endl;
    auto it = s.rbegin();
    for (;it!=s.rend();it++) {
        std::cout << "| " << *it << " | "  << std::endl;
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
    
    auto a = s.back();
    s.pop_back();
    return a;
}