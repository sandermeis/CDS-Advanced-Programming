//
// Created by Sander Meis on 09/11/2020.
//

#include <iostream>
using namespace std;

int main(){
    // assign pointer type
    char *Pstr;
    // input
    cout << "Please enter your text: \n";
    cin.getline(Pstr, 100);
    int l=0, u=0, d=0, o=0;
    // execute until, \0, which is at end of string
    while (*Pstr != '\0'){
        //ascii is ordered
        if (*Pstr>='a'&&*Pstr<='z'){
            l++;
        } else if (*Pstr>='A'&&*Pstr<='Z'){
            u++;
        } else if (*Pstr>='0'&&*Pstr<='9'){
            d++;
        } else {
            o++;
        }
        // check 1 pointer address further
        Pstr++;
    }
    // display
    cout << "Lower: " << l << "\n";
    cout << "Upper: " << u << "\n";
    cout << "Digit: " << d << "\n";
    cout << "Other: " << o << "\n";

    return 0;
}