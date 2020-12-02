#include "max.hh"
namespace mylib{
int max(int a,int b){
    if (a<b){
        return b;
    }
    else{
        return a;
    }
}

double max(double a,double b){
    if (a<b){
        return b;
    }
    else{
        return a;
    }
}

double max(int a,double b){
    if (a<b){
        return b;
    }
    else{
        return a;
    }
}

double max(double a,int b){
    if (a<b){
        return b;
    }
    else{
        return a;
    }
}

int max(int a[],int b){

    int tmp=a[0];
    for(int i=1;i<b;i++){
        if(a[i]>tmp){
            tmp=a[i];
        }
    }
return tmp;
}
}