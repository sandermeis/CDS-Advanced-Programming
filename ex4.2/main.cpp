// b), g) Compiler provided copy constructor and destructor will do
// 
// n) You need a default constructor
// 
// u) Cctor is needed to copy grid, else it does not call cctor of calogrid and you get default grid.

#include <iostream>
#include "CaloCell.hh"
#include "CaloGrid.hh"
#include "Calorimeter.hh"
#include "Point.hh"

int main() {
    CaloCell c;

    std::cout << "Cell ID: " << c.getID() << std::endl;
    std::cout << "Cell energy: " << c.getE() << std::endl;

    Point p1;
    p1.setX(1.5);
    std::cout << "Point location: (" << p1.getX() << "," << p1.getY() << "," << p1.getZ() << ")" << std::endl;

    CaloGrid g;
    g.cell(1, 2)->setE(3.54);
    CaloGrid h = g;

    g.cell(2, 2)->setE(1.4);

    std::cout << "Grid g, Cell (1,2) has energy reading: " << g.cell(1, 2)->getE() << std::endl;
    std::cout << "Grid h, Cell (1,2) has energy reading: " << h.cell(1, 2)->getE() << std::endl;
    std::cout << "Grid g, Cell (2,2) has energy reading: " << g.cell(2, 2)->getE() << std::endl;
    std::cout << "Grid h, Cell (2,2) has energy reading: " << h.cell(2, 2)->getE() << std::endl;
    
    const int i = 4;
    const int j = 5;
    std::cout << "const output: " << h.cell(i, j)->getE() << std::endl;
    
    Calorimeter c1(7);
    c1.grid().cell(2, 1)->setE(3.9);
    std::cout << "Calorimeter: " << c1.grid().cell(2, 1)->getE() << std::endl;
    Calorimeter c2(c1);
    std::cout << "Calorimeter: " << c2.grid().cell(2, 1)->getE() << std::endl;
    
    return 0;
}