//
// wc -l example.txt returns 80
// and
// example.txt wc -c example.txt returns 4323
// while actual lines and characters are 81 and 4243 respectively, this is probably because wc also counts new lines
// This algorithm does count "-" as words

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Please only add filename as argument" << std::endl;
        return 1;
    }
    std::ifstream ifs(argv[1]);
    if (!ifs.fail()) {
        std::cout << "Stream opened successfully" << std::endl;
    }

    int numlines = 0;
    int tchars = 0;
    int twords = 0;
    char word[256];
    char line[256];
    while (!ifs.eof()) {
        ifs.getline(line, 256);
        tchars += std::strlen(line);
        std::istringstream ss(line);
        while (ss>> word){
            twords++;
        }
        numlines++;
    }

    std::cout << "Lines: " << numlines << " Words: " << twords << " Chars: " << tchars << std::endl;
    return 0;
}
