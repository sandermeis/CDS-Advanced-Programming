//
//
// Only order specialization is needed

#include <iostream>
template<class T>
void order(T& a, T& b);

template<class T>
void display(T array[], int n);

template<class T>
void sort(T array[], int n);

int main(){
    int array[10] = {1337, 808, 15, 16, 23, 643, 42, 314, 4, 8};
    display(array, 10);
    sort(array, 10);
    display(array, 10);
    float array2[10] = {1337.5, 808.3, 15.2, 16.8, 23.0, 643.2, 42.1, 3.14, 4.0, 8.3};
    display(array2, 10);
    sort(array2, 10);
    display(array2, 10);
    const char* array3[10] = {"D","a","r","t","h","V","a","d","e","r"};
    display(array3, 10);
    sort(array3, 10);
    display(array3, 10);
    return 0;
}

template<class T>
void order(T& a, T& b){
    if(b>a){
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
}

template<>
void order(const char*& a, const char*& b){
    if(strcmp(a,b)<0){
        const char* tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
}

template<class T>
void display(T array[], int n){
    for (int i=0;i<n;++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
void sort(T array[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            order(array[j], array[j + 1]);
        }
    }
}