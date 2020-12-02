//
// Created by Sander Meis on 09/11/2020.
//
// Why do you need the const here?
//
// Because the string literals are const by convention
//
// What type of argument should order() take?
//
// Order() takes references to const char pointer
//
// Why can’t you just compare the pointer values to compare the strings?
//
// Because the pointers are not necessarily in order


#include <iostream>
#include <cstring>

void order(const char*& a, const char*& b);

void print(const char* array[]);

void sort(const char* array[], int n);

int main(){
    const char* array[10] = {"D","a","r","t","h","V","a","d","e","r"};
    print(array);
    sort(array, 10);
    print(array);
    return 0;
}

void order(const char*& a, const char*& b){
    if(strcmp(a,b)<0){
        const char* tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
}

void print(const char* array[]){
    for (int i=0;i<10;++i){
        std::cout << array[i];
    }
    std::cout << std::endl;
}

void sort(const char* array[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            order(array[j], array[j + 1]);
        }
    }
}