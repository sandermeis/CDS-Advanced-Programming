//
// Created by Sander Meis on 09/11/2020.
//
// I prefer passing by reference since passing by pointers is a lot more verbose, though the functionality is the same


#include <iostream>

// void order(int& a, int& b);

void ptrorder(int* a, int* b);

void print(int array[]);

void sort(int array[], int n);

int main(){
    int array[10] = {1337, 808, 15, 16, 23, 643, 42, 314, 4, 8};
    print(array);
    sort(array, 10);
    print(array);
    return 0;
}

// void order(int& a, int& b){
//     if(b>a){
//         int tmp;
//         tmp = a;
//         a = b;
//         b = tmp;
//     }
// }

void ptrorder(int* a, int* b){
    if(*b>*a){
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void print(int array[]){
    for (int i=0;i<10;++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void sort(int array[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            //order(array[j], array[j + 1]);
            ptrorder(&array[j], &array[j + 1]);
        }
    }
}