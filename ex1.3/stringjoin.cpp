//
// Created by Sander Meis on 11/11/2020.
//
#include <iostream>

// Pointer return type
char* join(const char*, const char*);
char* joinb(const char*, const char*);

int main(){
    // Need to declare so this namespace 'owns' the allocated memory and can delete it.
    // In this case it does not really matter because the program is short.
    char* str3 = join("alpha","bet");
    std::cout << str3 << std::endl;
    delete[] str3;
    char* str4 = joinb("duck","soup");
    std::cout << str4 << std::endl;
    delete[] str4;
    return 0;
}

char* join(const char *str1, const char *str2){
    // Allocate memory on the heap, needs room for str1 + str2 + terminating 0
    char* str3 = new char[1 + strlen(str1)+ strlen(str2)];
    str3[0]='\0';
    strcat(str3, str1);
    strcat(str3, str2);
    // Returns the pointer
    return str3;
}
char* joinb(const char *str1, const char *str2){
    // Allocate memory on the heap, needs room for str1 + space + str2 + terminating 0
    char* str3 = new char[2 + strlen(str1)+ strlen(str2)];
    str3[0]='\0';
    strcat(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);
    // Returns the pointer
    return str3;
}
