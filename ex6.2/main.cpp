// d)
//
// It does not look safe, it can give undefined behaviour when going out of bounds.

#include "Array.hh"
#include <iostream>

int main(){
    Array<int> a(10,1);
    a[1]=3;
    std::cout << a[15] << std::endl;
    Array<char> b(10,'o');
    b[1]='f';
    std::cout << b[12] << std::endl;
    Array<int> c=a;
    std::cout << c[17] << std::endl;
    return 0;
}