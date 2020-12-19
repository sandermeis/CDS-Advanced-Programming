
#include <iomanip>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream ifs("data1.txt");
    int buf;
    // Loop as long as stream is OK
    if(!ifs.fail()){
        std::cout << "Stream opened successfully" << std::endl;
    }
    while (!ifs.fail()) {
        ifs >> buf;
        // Stop here if we have reached end of file or when you have read an integer with value zero
        if (ifs.eof() || (buf==0)) break;
        std::cout << "just read '" << buf << "'" << std::endl ;
    }
    return 0;
}