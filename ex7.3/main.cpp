// list 10000 0m0.013s
// vect 10000 0m0.018s
// list 100000 0m0.051s
// vect 100000 0m0.361s
// So for small containers it does not realy matter a lot,
// for large containers it is significant

#include <iterator>
#include <list>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> li;
    for(int i=0;i<10000;i++){
        li.push_back(i);
    }
    auto it = li.begin();
    while(it!=li.end()){
        it = li.erase(it);
        if(it!=li.end()) {
            it++;
            it++;
        }
    }

    return 0;
}