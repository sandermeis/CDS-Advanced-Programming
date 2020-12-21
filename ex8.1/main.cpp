// 
// c) No duplicates are allowed in set, you cant have the same person twice as subordinate
// 
// f) yes
//
// l) no, because manager is also an employee

#include "Employee.hh"
#include <set>

int main(){
    Employee edwin("Edwin Chow",5000);
    edwin.businessCard();
    edwin.salary();
    
    std::set<Employee*> subordinates;
    subordinates.insert(&edwin);
    Manager frank("Frank Filthaut",8000,subordinates);
    frank.businessCard();
    frank.salary();

    std::cout << std::endl << std::endl << std::endl;

    std::set<Employee*> emptyset;
    Manager frank2("Frank",8000,emptyset);
    Employee ivo("Ivo",2000);
    Employee wouter("Wouter",2200);
    Manager stan("Stan",5500,emptyset);
    Manager jo("Jo",5600,emptyset);
    stan.addSubordinate(wouter);
    stan.addSubordinate(ivo);
    frank2.addSubordinate(jo);
    frank2.addSubordinate(stan);
    frank2.businessCard();
    jo.businessCard();
    stan.businessCard();
    ivo.businessCard();
    wouter.businessCard();
    return 0;
}