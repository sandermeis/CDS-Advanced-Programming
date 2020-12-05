// Why doesn’t the initialization belong to the class declaration?
// 
// The declaration is used in all classes

#include <iostream>

class Counter{
    public:
    Counter();
    ~Counter();
    static int getCounter();

    private:
    static int count;
};

int main() {
    Counter a;
    Counter b;
    std::cout << "there are now " << Counter::getCounter() << " Counter objects" << std::endl;
    if (true) {
        Counter c;
        std::cout << " and now " << Counter::getCounter() << std::endl;
    }
    std::cout << " and now " << Counter::getCounter() << std::endl;
    return 0;
}

int Counter::count=0;

Counter::Counter(){
    count++;
}

Counter::~Counter(){
    count--;
}

int Counter::getCounter(){
    return count;
}
