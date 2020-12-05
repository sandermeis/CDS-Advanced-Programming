#ifndef H_STACK
#define H_STACK

class Stack {
   public:
    // Constructor
    Stack();
    Stack(int sz);
    Stack(const Stack& sclone);
    // Destructor
    ~Stack();

    // Interface
    int nitems() { return count; }
    bool full() { return (count == LEN); }
    bool empty() { return (count == 0); }

    // Methods
    void init(double sz);
    void push(double c);
    void inspect();
    double pop();
    void grow(int delta);

   private:
    double* s;
    int LEN;  // default stack length
    int count;
};

#endif