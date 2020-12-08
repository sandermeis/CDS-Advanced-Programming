// b) It does not compile, Cable is defined twice, this is fixed using #pragma once
//
// c) The member objects are initialized first, then the constructor of the class itself is called (inside out)
//
// d) They behave as completely different objects
// 
// e) The default constructors are called
//
// f) Need to member initialize so that the copy constructor is called


#include "Telephone.hh"
// #include "Chassis.hh"

int main(){
    Telephone telly;
    std::cout << "printerino" << std::endl;
    Telephone telly2 = telly;
    std::cout << "printerino" << std::endl;
    return 0;
}