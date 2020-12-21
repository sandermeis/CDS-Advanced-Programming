//
// f) object of abstract class type "Square" is not allowed: -- pure virtual function "Shape::shapeName" has no overrider
//


#include <iostream>
#include <list>
#include "Square.hh"

void listShapes(std::list<Shape*> l);

int main() {
    Square s(5);
    std::cout << "Surface area: " << s.surface() << std::endl
              << "Circumference: " << s.circumference() << std::endl;

    Circle s2(3);
    std::cout << "Surface area: " << s2.surface() << std::endl
              << "Circumference: " << s2.circumference() << std::endl;
    Square s3(3);
    Circle s4(4);

    std::list<Shape*> li;
    li.push_back(&s);
    li.push_back(&s2);
    li.push_back(&s3);
    li.push_back(&s4);

    listShapes(li);
    return 0;
}

void listShapes(std::list<Shape*> l) {
    for (auto i : l) {
        std::cout << "Shape name: " << i->shapeName() << std::endl
                  << "Surface area: " << i->surface() << std::endl
                  << "Circumference: " << i->circumference() << std::endl;
    }
}