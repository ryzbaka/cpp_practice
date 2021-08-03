#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Resource
{
private:
    std::string name;

public:
    Resource(std::string s) : name(s){};
    std::string getName()
    {
        return name;
    };
};

class Person
{
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::shared_ptr<Resource> pResource;

public:
    Person(std::string first, std::string last, int age) : firstName(first), lastName(last), age(age){};
    std::string getName() const
    {
        return firstName + lastName;
    }
    void addResource()
    {
        pResource.reset();
        pResource = std::make_shared<Resource>("Resource for " + this->getName());
    }
    int getAge()
    {
        return age;
    }
};

int Dummy(Person x)
{
    return x.getAge();
}

int main()
{
    Person hamza("Hamza", "Ali", 21);
    hamza.addResource();
    hamza.addResource();
    //without smart pointers, the above two operations would cause memory leak
    //because the previous resource wouldn't have been deleted and pResouce
    //would point to a new resource which would make it impossible to delete
    //the old resource.
    Person haider = hamza;
    //there are now two refs to the same resource, one from hamza and the other
    //from haider.
    int x = Dummy(haider);
    //since object was passed by value, there are now three references to the
    //same resource will the function ends after which there will be two till
    //the end of main.
}