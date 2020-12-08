#pragma once

class Point{
   public:
    Point(double X=0,double Y=0,double Z=0):x(X),y(Y),z(Z){};

    const double getX() const {return x;}
    const double getY() const {return y;}
    const double getZ() const {return z;}

    void setX(double X) {x=X;}
    void setY(double Y) {y=Y;}
    void setZ(double Z) {z=Z;}

    void setPos(double X,double Y,double Z){x=X;y=Y;z=Z;}
    
   private:
    double x,y,z;
};