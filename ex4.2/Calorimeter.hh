#pragma once
#include "CaloGrid.hh"
#include "Point.hh"

class Calorimeter {
   public:
    Calorimeter(int sz, double X = 0, double Y = 0, double Z = 0) : c(sz, sz), p(X, Y, Z){};

    Calorimeter(const Calorimeter& other):c(other.c),p(other.p){};

    CaloGrid& grid(){return c;}

    const CaloGrid& grid() const {return c;}

    Point& position(){return p;}

    const Point& position() const {return p;}

   private:
    Point p;
    CaloGrid c;
};