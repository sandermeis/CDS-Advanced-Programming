#include <iostream>
#ifndef DIALER_HH
#define DIALER_HH

#include "Button.hh"

class Dialer {
public:

  Dialer() { std::cout << "Dialer Constructor " << this << std::endl ; }
  Dialer(const Dialer&) { std::cout << "Dialer Copy Constructor " << this << std::endl ; }
  ~Dialer() { std::cout << "Dialer Destructor " << this << std::endl ; }

private:

  Button buttons[12] ;

} ;

#endif 
