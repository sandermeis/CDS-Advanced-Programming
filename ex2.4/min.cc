#include "min.hh"
namespace mylib{
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

double min(int a,double b){
    if (a>b){
        return b;
    }
    else{
        return a;
    }
}

double min(double a,int b){
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
}