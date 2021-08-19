#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        Person(string n="Unnamed", int a=0):name(n), age(a){};
        Person(const Person &p2):name(p2.getName()), age(p2.getAge()){};
        ~Person(){};
        string getName() const{
            return this->name;
        }
        int getAge() const{
            return this->age;
        }
        void setName(string s){
            this->name=s;
        }
        void setAge(int a){
            this->age=a;
        }
        Person &operator=(const Person &anotherPerson){
            if(this==&anotherPerson){
                return *this;
            }
            this->name = anotherPerson.getName();
            this->age = anotherPerson.getAge();
            return *this;
        }
};

int main(){
    Person p1;
    Person p2(p1);
    p1.setName("Hamza");
    cout<<p1.getName()<<"\n";
    cout<<p2.getName()<<"\n";
    p2 = p1;
    cout<<p2.getName()<<"\n";
    return 0;
}