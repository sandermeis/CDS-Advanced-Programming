#ifndef EMPLOYEE_HH
#define EMPLOYEE_HH

#include <iostream>
#include <set>
#include <string>
#include <iomanip>

class Employee {
   public:
    // Constructor
    Employee(const char* name, double salary) : _name(name), _salary(salary) {}

    // Accessors
    const char* name() const { return _name.c_str(); }
    double salary() const { return _salary; }

    // Print functions
    void virtual businessCard(std::ostream& os = std::cout) const {
        os << "   +------------------+  " << std::endl
           << "   |  HEF Corporation |  " << std::endl
           << "   +------------------+  " << std::endl
           << "   " << name() << std::endl;
    }

   private:
    std::string _name;
    double _salary;
};

class Manager : public Employee {
   public:
   Manager(const char* name, double salary,std::set<Employee*> subordinates):
   Employee(name,salary),
    _subordinates(subordinates){};

    void addSubordinate(Employee& empl){
      _subordinates.insert(&empl);
    }

    const std::set<Employee*>& listOfSubordinates() const{
      return _subordinates;
    }

    void businessCard(std::ostream& os = std::cout) const {
      Employee::businessCard();
        os << "   +------------------+  " << std::endl
           << "   |     Employees    |  " << std::endl
           << "   +------------------+  " << std::endl;
        for(auto it = listOfSubordinates().begin();it!=listOfSubordinates().end();it++){
        os << "   " << (*it)->name() << std::endl;
        }
        os << std::endl << std::endl;
    }

   private:
    std::set<Employee*> _subordinates;
};

#endif
