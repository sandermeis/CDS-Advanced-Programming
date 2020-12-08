#pragma once

class CaloCell{
   public:
    CaloCell(int i_ID=0,double i_energy=0):ID(i_ID),energy(i_energy){};
    const int getID() const {return ID;}
    const double getE() const {return energy;}

    void setID(int newID){ID=newID;}
    void setE(double newE){energy=newE;}
   private:
    int ID;
    double energy;
};