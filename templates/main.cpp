/*
    Genericity is implemented in C++ using templates.
    For example, say you want to write a function that adds two ints or two floats, etc.
    Rather than writing multiple functions for each of those data types you can  write the logic
    once if you use templates.
    Templates are evaluated at compile time. While this may increase the time it takes to compile,
    it speeds up execution during runtime.

    Type safe collections can also be written using templates.

    Templates often rely on operator overloads.
    
*/
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Person
{
private:
    string name;
    int age;

public:
    Person(string n = "John", int a = 0) : name(n), age(a) {}
    bool operator<(Person const &p2) const //overloaded operator
    {
        return this->age < p2.age;
    }
    int getAge() const
    {
        return this->age;
    }
    string getName() const
    {
        return this->name;
    }
};

template <class T>                  //indicator that this is a templated function.
T maximus(T const &t1, T const &t2) //T is the type placeholder
{
    //const& is constant reference and is used when the params themselves aren't changed.
    return t1 < t2 ? t2 : t1;
}

int main()
{
    cout << maximus(2, 3) << "\n";
    cout << maximus(23.4, 43.5) << "\n";
    Person p1 = Person("Hamza", 21);
    Person p2 = Person("Haider", 18);
    Person p3 = maximus(p1, p2);
    cout << p3.getName() << "\n";
    return 0;
}