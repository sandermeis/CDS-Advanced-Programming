#include <iostream>
#ifndef DIALER_HH
#define DIALER_HH

#include "Button.hh"

class Dialer {
   public:
    Dialer() : buttons(new Button[12]) {
        std::cout << "Dialer Constructor " << this << std::endl;
    }
    Dialer(const Dialer& other) : buttons(new Button[12]) {
        std::cout << "Dialer Copy Constructor " << this << std::endl;
        for (int i = 0; i < 12; i++) {
            buttons[i] = other.buttons[i];
        }
    }
    ~Dialer() {
        std::cout << "Dialer Destructor " << this << std::endl;
        // Deletes array so no memory leak
        delete[] buttons;
    }

   private:
    Button* buttons;
};

#endif
