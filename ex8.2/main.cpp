// 
// d) It is in reverse order (because we don't print manually), 
// and it treats all employees like employees.
//    
// g) Yes, now manager cards are properly printed
//
//

#include "Employee.hh"
#include <set>

void printAllCards(std::set<Employee *>::iterator,std::set<Employee *>::iterator);

int main(){

    std::set<Employee*> empset;
    Manager frank2("Frank",8000,empset);
    Employee ivo("Ivo",2000);
    Employee wouter("Wouter",2200);
    Manager stan("Stan",5500,empset);
    Manager jo("Jo",5600,empset);

    empset.insert(&frank2);
    empset.insert(&ivo);
    empset.insert(&wouter);
    empset.insert(&stan);
    empset.insert(&jo);

    stan.addSubordinate(wouter);
    stan.addSubordinate(ivo);
    frank2.addSubordinate(jo);
    frank2.addSubordinate(stan);

    // Begin
    std::set<Employee *>::iterator b = empset.begin();
    // End
    std::set<Employee *>::iterator e = empset.end();
    printAllCards(b,e);

    return 0;
}

void printAllCards(std::set<Employee *>::iterator b,std::set<Employee *>::iterator e){
    for(;b!=e;b++){
        (*b)->businessCard();
    }
};