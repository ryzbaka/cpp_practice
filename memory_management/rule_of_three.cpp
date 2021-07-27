// RULE OF THREE
/*
    If you're going to have a pointer to the free store (heap), keep it in an
   object so that we can use member functions to manage it. For example, the
   destructor of the object can `delete` the pointer so that memory gets cleaned
   up automatically when the object goes out of scope. Another issue that we can
   face when doin manual memory management is running into errors when copying
   pointers. Copy constructors can be used to work our way around such issues.
   The copy assignment operator not only initializes the new object with the
   values of the old object whose copy you're making

    The object acts a "handle" for the free store pointer.
    https://en.cppreference.com/w/cpp/language/rule_of_three

    Our goal is to prevent memory leaks. A memory leak occurs when we lose our
   ability to free up memory space because we have to lost access to the pointer
   pointing to that memory space.

   We use destructors to free up space. We use copy constructors to prevent the
   calling of delete on a pointer that has already been deleted by creating a
   fresh copy. We use copy assignment operators to prevent memory leakage by
   loss of access(because of overwrite) to old pointer value before it could be
   deleted.
*/

#include <iostream>
#include <string>
using std::cout;
using std::string;

class Resource {
private:
  std::string name;

public:
  Resource(std::string n) : name(n) {
    cout << "Constructing resource: " << n << "\n";
  };
  ~Resource() { std::cout << "Destroyed: " << this->name << "\n"; };
  std::string getName() const { return name; };
};

class Person {
private:
  string firstName;
  string lastName;
  int age;
  Resource *pResource;

public:
  Person(string first, string last, int num)
      : firstName(first), lastName(last), age(num), pResource(nullptr) {}

  Person(Person const &anotherPerson) // copy constructor
      : firstName(anotherPerson.getFirst()), lastName(anotherPerson.getLast()),
        age(anotherPerson.getAge()) {
    pResource = new Resource(anotherPerson.pResource->getName());
  }

  ~Person() { delete pResource; }; // destructor
  string getName() const { return firstName + " " + lastName; }
  int getAge() const { return age; }
  string getFirst() const { return firstName; }
  string getLast() const { return lastName; }
  void setFirstName(string first) {
    cout << "changed first name to:\t" << first << "\n";
    firstName = first;
  }
  void addResource() {
    delete pResource; // free up memory at address that pResource is pointing
                      // to. delete trigger the destructor.
    pResource = new Resource("Resource for: " + this->getName());
  }
  Person &operator=(Person const &anotherPerson) { // copy assignment operator
    if (this == &anotherPerson) {
      return *this;
    }
    delete pResource;
    pResource = new Resource(anotherPerson.pResource->getName());
    return *this;
  }
};

int main() {
  Person p1("Ethan", "Klein", 36);
  p1.addResource();
  p1.setFirstName("Hila");
  p1.addResource();
  Person p2 = p1; // copy constructor;
  Person p3("Hamza", "Ali", 21);
  p3.addResource();
  p3 = p2;
  p3 = p3; // this would cause error if there was no check if other value is
           // same as current value in copy assignment operator because we would
           // be trying to use a deleted pResource.
  return 0;
}