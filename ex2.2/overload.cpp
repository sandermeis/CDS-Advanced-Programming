//
// Created by Sander Meis on 09/11/2020.
//
//Implement the following overloaded min() functions
// min(int,int)
// min(double,double)
// min(int[],int)
//where the last function returns the minimum of an array of integers with a length specified by the 2nd argument
//
//Write a small program that tests your three implementations
//
//Now try call min() passing a double and an int as argument. Why doesn’t this work?
//
//Fix this problem without using explicit casts

#include <iostream>

int min(int,int);

double min(double,double);

int min(int[],int);

int main(){
    int a = 3;
    int b = 5;
    double c = 3.3;
    double d = 5.5;
    int e[10]={1337, 808, 15, 16, 23, 643, 42, 314, 4, 8};
    std::cout << min(a,b) << std::endl;
    std::cout << min(c,d) << std::endl;
    std::cout << min(e,10) << std::endl;
    return 0;
}

int min(int a,int b){
    if (a>b){
        return b;
    }
    else{
        return a;
    }
}

double min(double a,double b){
    if (a>b){
        return b;
    }
    else{
        return a;
    }
}

int min(int a[],int b){
    int tmp=a[0];
    for(int i=1;i<b;i++){
        if(a[i]<tmp){
            tmp=a[i];
        }
    }
return tmp;
}