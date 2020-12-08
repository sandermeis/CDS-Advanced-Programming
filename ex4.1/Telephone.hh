#ifndef TELEPHONE_HH
#define TELEPHONE_HH

#include "Cable.hh"
#include "Dialer.hh"
#include "Handset.hh"
#include "Housing.hh"

class Telephone {
   public:
    Telephone(){
        std::cout << "Telephone Constructor " << this << std::endl;
    }

    Telephone(const Telephone& other):cable(other.cable),housing(other.housing),dialer(other.dialer),handset(other.handset) {
        std::cout << "Telephone Copy Constructor " << this << std::endl;
    }

    ~Telephone() {
        std::cout << "Telephone Destructor " << this << std::endl;
    }

   private:
    Cable cable;
    Housing housing;
    Dialer dialer;
    Handset handset;
};

#endif
