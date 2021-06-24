#include <string>

class Person
{
private:
    std::string firstName;
    std::string lastName;
    int arbitratyNumber;

public:
    std::string getName() const;                 //adding a const means that it isn't changing any values.
                                                 //function declaration
    Person(std::string first, std::string last); //constructor
    Person();
    ~Person();
};