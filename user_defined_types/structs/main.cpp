#include <iostream>
#include <string>

using std::cout;
using std::string; //better alternative to using namepace std;

struct Person
//structs can have member functions, constructors, destructors, etc.
//should not include functions but still can. Theory: probably included in c++ for backwards
//compatibility.
{
private:
    //unlike class, default is public (not private)
    string name;
    int age;

public:
    Person(string name = "John Doe", int age = 0) : name(name), age(age)
    {
    }
    string getName()
    {
        return this->name;
    }
};
int main()
{
    Person p;
    cout << p.getName() << "\n";
    return 0;
}