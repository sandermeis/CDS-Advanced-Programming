//
//
// b) Increases the value of the key by 1 everytime the key (word) appears. So counts words
//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

int main() {
    std::ifstream file("example.txt");
    if (!file.fail()) {
        std::cout << "Stream opened successfully" << std::endl;
    }
    std::map<std::string, int> myMap;

    std::string word;
    while (file >> word) {
        myMap[word] += 1;
    }

for (std::map<std::string, int>::iterator i = myMap.begin(); i!=myMap.end(); i++){
    std::cout << i->second << "x " << i->first << std::endl;
}

    return 0;
}
