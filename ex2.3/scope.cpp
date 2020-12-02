//
// Identify which print() functions are called in sub1() and print() and explain why?
// In sub1 using White::print is limited to the scope, this includes the nested recursive print inside print()
//
//
// Is the statement ‘using Black::print’ legal? Explain why?
//
// No, then the compiler does not understand what type of print to use.
//
#include <iostream>

namespace Black {
void print(int k){};
}

namespace White {
void print(int k){};
}

void sub1();

int main(){
    sub1();
    return 0;
}

void sub1() {
    using White::print;  // Local using declaration
    print(5);            // a) Which print() is called?
}

void print(int k) {
    std::cout << k << std::endl;
    if (k > 0) {  
        print(k - 1);  // a) Which print() is called?
    }
}