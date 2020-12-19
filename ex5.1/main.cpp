//
// e) Do you need to repeat the scientific mode manipulator in front of each floating field?
//
// No
//
// f) Do you need to repeat the setw() manipulator in front of each field?
//
// Yes

#include <iomanip>
#include <iostream>

int main(){
    // input hex
    int input;
    std::cout << "input?:";
    std::cin >> std::hex >> input;
    std::cout << input << std::endl << std::hex << input << std::endl << std::oct << input << std::endl ;

    // input floats
    float f1,f2,f3;
    std::cout << "inputs?:";
    std::cin >> f1 >> f2 >> f3;
    // Scientific
    std::cout << std::scientific << f1 << " " << f2 << " " << f3 << std::endl;
    // Header
    std::cout << std::setw(20) << "ValueA " << std::setw(20) << "ValueB " << std::setw(20) << "ValueC" << std::endl;
    std::cout << std::setfill('-') << std::setw(60) << "" << std::endl;
    // setw() 20 char
    std::cout << std::setfill(' ') << std::setw(20) << f1 << " " << std::setw(20) << f2 << " " << std::setw(20) << f3 << std::endl;
    // Fixed precision, 3 figures, aligned left (e.g. “ 15.253 ”)
    std::cout << std::setw(20) << std::setprecision(3) << std::fixed << std::left << f1 << " " << std::setw(20) << f2 << " " << std::setw(20) << f3 << std::endl;

    return 0;
}