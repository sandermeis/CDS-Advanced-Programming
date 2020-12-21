// c) I'm not getting any errors as suggested, probably because of using auto

#include <vector>
#include <iostream>
#include <iterator>

template<class T>
bool isPalindrome(std::vector<T> v);

int main(){
    std::vector<int> vect1{1,2,3,4,5,4,3,2,1};
    std::cout << std::boolalpha << "Is it a palindrome?: " << isPalindrome(vect1) << std::endl;
    std::vector<int> vect2{1,2,3,4,5,3,2,1};
    std::cout << std::boolalpha << "Is it a palindrome?: " << isPalindrome(vect2) << std::endl;
    std::vector<char> vect3{'a','b','c','c','b','a'};
    std::cout << std::boolalpha << "Is it a palindrome?: " << isPalindrome(vect3) << std::endl;
    std::vector<char> vect4{'s','a','n','d','e','r'};
    std::cout << std::boolalpha << "Is it a palindrome?: " << isPalindrome(vect4) << std::endl;
           
    return 0;
}

template<class T>
bool isPalindrome(std::vector<T> v){
auto ita = v.begin();
auto itb = v.end();
//v.end() is 1 past, so decrease 1
itb--; 

// run loop until iterators are equal, if it finishes it's a palindrome
while (ita<itb){
    if (*ita!=*itb){
        return false;
    }
    ita++;
    itb--;
} 

return true;
}