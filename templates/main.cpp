/*
    Genericity is implemented in C++ using templates.
    For example, say you want to write a function that adds two ints or two floats, etc.
    Rather than writing multiple functions for each of those data types you can  write the logic
    once if you use templates.
    Templates are evaluated at compile time. While this may increase the time it takes to compile,
    it speeds up execution during runtime.

    Type safe collections can also be written using templates.

    Templates often rely on operator overloads.

    Template specialization: Sometimes a template won't work for some class. To write template logic specific to that
    class we use template specialization. 
*/
#include <iostream>
#include <string>
using std::cout;
using std::string;

template <class T>
class Accum
{ //template class
private:
    T total;

public:
    Accum(T start) : total(start){};
    T operator+=(T const &t)
    {
        return this->total = total + t;
    }
    T operator+=(Accum const &a)
    {
        return this->total += a.getTotal();
    }
    T getTotal() const
    {
        return this->total;
    }
};

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

template <>
class Accum<Person>
{ //template class specialized to the Person class
private:
    int total;

public:
    Accum(int start) : total(start){};
    int operator+=(Person const &t)
    {
        return this->total = total + t.getAge();
    }
    int operator+=(Accum<Person> const &a)
    {
        return this->total += a.getTotal();
    }
    int getTotal() const
    {
        return this->total;
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
    //Template functions demo
    cout << maximus(2, 3) << "\n";
    cout << maximus(23.4, 43.5) << "\n";
    Person p1 = Person("Hamza", 21);
    Person p2 = Person("Haider", 18);
    Person p3 = maximus(p1, p2);
    cout << p3.getName() << "\n";

    //Template Class demo
    Accum<int> a1 = Accum<int>(0);
    a1 += 1;
    a1 += 23;
    int result = a1.getTotal();
    cout << result << "\n";
    Accum<int> a2 = Accum<int>(24);
    a1 += a2;
    cout << a1.getTotal() << "\n";

    //Template Specialization Demo
    Person p = Person("", 0);
    Accum<Person> people = Accum<Person>(p.getAge());
    people += p1;
    people += p2;
    cout << people.getTotal() << "\n";
    Accum<Person> people2 = Accum<Person>(p1.getAge());
    people2 += p2;
    people += people2;
    cout << people.getTotal() << "\n";
    return 0;
}