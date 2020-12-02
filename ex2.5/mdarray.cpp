//
//
//

#include <iostream>

double* multiply(double ivec[], int N, double mtx[][3]);

void print(double ivec[],int N);

int main(){
    int N = 4;
    double ivec[] = {1,2,3,4};
    double mtx[4][3] = {{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
    double* res = multiply(ivec, N, mtx);
    print(res,N);
    delete[] res;
    return 0;
}

double* multiply(double ivec[], int N, double mtx[][3]){
    double* res = new double[3];
    for(int j=0;j<3;j++){
    for(int i=0;i<N;++i){
        res[j]+=ivec[i]*mtx[i][j];
    }
}
return res;
}

void print(double ivec[],int N){
for(auto i=0;i<3;i++){
    std::cout << ivec[i] << " ";
}
    std::cout << std::endl;
}
