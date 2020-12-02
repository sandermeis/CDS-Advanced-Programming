//
//f: generates "duplicate symbol 'min(int, int)'" error because now two instances of min are available and the compiler can't choose
//
//
#include <iostream>
#include "min.hh"
#include "max.hh"

int min(int a,int b);

int main() {
    std::cout << min(1,2) << std::endl;
    std::cout << mylib::min(1,2.2) << std::endl;
    std::cout << mylib::max(1.3,9.9) << std::endl;
    return 0;
}

int min(int a,int b){
    if (a>b){
        return b;
    }
    else{
        return a;
    }
}