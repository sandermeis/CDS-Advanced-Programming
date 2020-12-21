#pragma once

#include "Array.hh"

template<class T>
class Stack {
   public:

    Stack(T);
    Stack(int, T);
 

    // Interface
    int nitems() { return count; }
    bool full() { return (count == s.size()); }
    bool empty() { return (count == 0); }

    // Methods
    void push(T c);
    void inspect();
    T pop();

   private:
    Array<T> s;
    int count;
};

#include "Stack.tpp"