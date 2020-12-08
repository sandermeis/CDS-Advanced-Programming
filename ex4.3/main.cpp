// b) Return type should be a string
//
// c) Return type should be a string reference (so chain assignment is possible) and string respectively
//
// i) It is possible because of automatic conversion using the constructor
//
// m) In this case it is implemented that it just returns the original, but it's better to return an error message, this implementation depends a lot on the actual program using it.
//
// n) Can't use operator[] because it accepts only 1 element.

#include <iostream>
#include <cstring>
#include "String.hh"

int main() {
    String s("Hello");
    String s2(" cpp");
    String s3;
    String s4(" world");
    s2 = s3 = s;

    std::cout << s.length() << std::endl;
    std::cout << s.data() << std::endl;
    std::cout << s2.data() << std::endl;
    std::cout << s3.data() << std::endl;
    s += s4;
    std::cout << s.data() << std::endl;
    std::cout << (s+s4).data() << std::endl;
    // Automatically converted by compiler through constructor
    std::cout << (s+" wereld").data() << std::endl;
    // Conversion from String to const char*
    std::cout << std::strlen(s4) << std::endl;
        std::cout << s4.data() << std::endl;
    std::cout << s4(2,4).data() << std::endl;
    // operator[] can only use 1 value
    return 0;
}

String& String::operator+=(const String& other) {
    int newlen = _len + other._len;       // calc new length
    char* newstr = new char[newlen + 1];  // alloc new buffer
    strcpy(newstr, _s);
    strcpy(newstr + _len, other._s);
    if (_s) delete[] _s;
    _s = newstr;
    _len = newlen;
    return *this;
}

String operator+(const String& s1, const String& s2) {
        String result(s1) ; // clone s1 using copy ctor
        result += s2 ;      // append s2
        return result ;     // return new result
}