#include <iostream>
#include "Person.h"

int main()
{
    Person p1("Hamza", "Ali");
    Person p2("Haider", "Ali");
    Person p3;
    std::string name1 = p1.getName();
    std::string name2 = p2.getName();

    std::cout << "Name of person 1 is: " << name1 << "\n";
    std::cout << "Name of person 2 is: " << name2 << "\n";
    return 0;
}