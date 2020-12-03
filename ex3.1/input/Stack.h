#ifndef H_STACK
#define H_STACK

class Stack {
   public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Interface
    int nitems() { return count; }
    bool full() { return (count == LEN); }
    bool empty() { return (count == 0); }

    // Methods
    void push(double c);
    void inspect();
    double pop();

   private:
    // Implementation
    static const int LEN = 80;  // default stack length
    double s[LEN];
    int count;

    void init() { count = 0; }
};

#endif