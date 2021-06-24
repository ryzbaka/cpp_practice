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
    Person(string name = "John Doe", int age = 0) : name(name), age(age) {}
    string getName() { return this->name; }
    int getAge() { return this->age; }
    ~Person() { cout << "Person destructor called\n"; }
};

class Programmer : public Person
{
private:
    string lang;

public:
    Programmer(string name = "John Doe", int age = 0, string lang = "CPP")
        : Person(name, age), //initializer is used for initializing Person class
          lang(lang)
    {
        cout << "Inherited constructor called.\n";
    }
    string getLang() { return this->lang; }
    ~Programmer() { cout << "Programmer destructor called.\n"; } //called before base destructor.
};

int main()
{
    Programmer p;
    cout << p.getName() << "\n";
    cout << p.getAge() << "\n";
    cout << p.getLang() << "\n";
    return 0;
}