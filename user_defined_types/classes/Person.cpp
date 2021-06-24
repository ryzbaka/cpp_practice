#include "Person.h"
#include <string>
#include <iostream>

std::string Person::getName() const
{
    return firstName + " " + lastName;
} //function definition.

Person::Person(std::string first, std::string last)
    : firstName(first), lastName(last) //constructor initializer ':' used to assign values.
{
    std::cout << "Constructor called for: " << this->firstName << "\n";
}
Person::Person() //default constructor
{
    this->firstName = "Not";
    this->lastName = "Assigned";
    std::cout << "Constructor called.\n";
}
Person::~Person() //destructor - cannot be overloaded.
{
    std::cout << "Destructor called for: " << this->firstName << "\n";
}
//Constructor and destructors can be used for a design pattern called:
//Resource Acquisition Is Initialization(RAII) which acquires resources
//(opening file, connecting to db) in the constructor and the releasing
//in the destructor.
