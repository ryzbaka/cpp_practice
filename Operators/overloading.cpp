#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Person
{
private:
    string firstName;
    string lastName;
    int age;

public:
    Person(string firstName = "John", string lastName = "Doe", int age = 0)
        : firstName(firstName), lastName(lastName), age(age){};
    string getName() const
    {
        return this->firstName + " " + this->lastName;
    }
    int getAge() const
    {
        return this->age;
    }
    bool operator<(Person const &p) const //member operator overloading
    {
        //const& means constant reference and indicates the the function or overloaded operator
        //cannot change the value that is being passed in by reference.
        //the second const is for indicating that the function or overloaded operator will not change
        //any existing member values in the object itself.
        //These steps are taken for improving performance.

        //this overloaded operator is for the case: p1<p2
        return this->age < p.age;
    }
    bool operator<(int i) const
    {
        //this overloaded operator is for the case: p1<int
        return this->age < i;
    }
};

bool operator<(int i, Person const &p) //free overloaded operator
{
    //used for case : int<p
    return i < p.getAge();
}

int main(int argc, char **argv)
{
    Person p1("Richard", "Bachman", 32), p2("Hamza", "Ali", 21);
    cout << p1.getName() << "\n";
    cout << p2.getName() << "\n";
    bool result1 = p1 < p2; //false
    bool result2 = 18 < p2; //true
    bool result3 = p1 < 29; //false
    cout << result1 << "\n";
    cout << result2 << "\n";
    cout << result3 << "\n";
    cout << "Number of arguments provided :" << argc - 1 << "\n";
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            cout << "Argument" << i << ":" << argv[i];
        }
    }
    return 0;
}