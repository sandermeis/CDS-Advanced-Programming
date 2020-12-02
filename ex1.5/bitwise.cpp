//
// Created by Sander Meis on 12/11/2020.
//
// What are the advantages of base-16 over base-10 in computing?
// A computer only uses base 2, base 16 can be represented by 4 bits, base 10 cant be represented by a whole number of bits


// 4 bytes to represent integer, so 4*8=32 bits
// base 32 can be represented by 2^5=32 so 5 bits, thus we need 32//5=7 32 bit characters.

#include <iostream>
#include <cmath>
#include <iterator>
#include <algorithm>

unsigned int len(unsigned int n){
    return n ? len(n/10)+1 : 0;
}

int main(){
    // Lookup table
    const char* table = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    unsigned int input;
    std::cout << "Please enter integer: " << std::endl;
    std::cin >> input;
    short int temp[6];
    for (int i=0;i<7;++i){
        // Compare with 11111 (=31)
        temp[i]=(31 & input);
        // Bit shift 5 places
        input=input>>5;
    }
    // Reverse
    std::reverse(std::begin(temp), std::end(temp));
    std::cout << "32 bit representation: " << std::endl;
    // Simple print loop
    for (auto i:temp){
    std::cout << table[i];
    }
    std::cout << "\n";

    return 0;
}