#ifndef SQUARE_HH
#define SQUARE_HH

#include "Shape.hh"
#include <math.h>

class Square: public Shape {
public:

  // Constructor, destructor
  Square(double size) : _size(size) {} ;
  virtual ~Square() {} ;

  // Implementation of abstract interface
  virtual double surface() const { return _size * _size ; }
  virtual double circumference() const { return 4 * _size ; }
  virtual const char* shapeName() const { return "Square";}
private:

  double _size ;

} ;

class Circle: public Shape {
public:

  // Constructor, destructor
  Circle(int radius) : _radius(radius) {} ;
  virtual ~Circle() {} ;

  // Implementation of abstract interface
  virtual double surface() const { return M_PI * _radius * _radius ; }
  virtual double circumference() const { return 2 * M_PI * _radius ; }
  virtual const char* shapeName() const { return "Circle";}
private:

  int _radius ;

} ;
#endif
