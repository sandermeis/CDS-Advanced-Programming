#pragma once

#include "Array.hh"
#include <deque>

template<class T>
class Stack {
   public:

    Stack(T);
 
    // Interface
    int nitems() { return s.size(); }
    bool empty() { return (s.size() == 0); }

    // Methods
    void push(T c);
    void inspect();
    T pop();

   private:
    std::deque<T> s;
};

#include "Stack.tpp"