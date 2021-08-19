/*
    L Values and R Values

    
*/
#include <iostream>
#include <string>

int getValue(){
    return 10;
}

int& getAnotherValue(){
    //return a reference to a static variable which is an l value.
    static int value = 10;
    return value;
}

void printValue1(int x){
    //accepts both lvalues and rvalues
}
void printValue1(int& x){
    //accepts only lvalues.
}
void printValue2(const int& x){
    //accepts both lvalues and rvalues because if an rvalue is provided it will create a temp variable and use the reference to that variable.
}

void printName(std::string &name){
    //l-value only
    std::cout<<name<<" lvalue only.\n";
}
void printName(const std::string &name){
    //both l and r-values
    std::cout<<name<<" lvalue or r value\n";
} //this function will never be called when running printName since we already have more specific overloads of the function for l and r values each.

void printName(std::string &&name){
    //accepts rvalues only, notice the &&
    std::cout<<name<<" rvalue only\n";
}

void printName2(const std::string &name){
    std::cout<<name<<" lvalue or rvalue\n";
}
#include <iostream>

int main(){
    int i = 10;
    // i is a variable with a location in memory
    // 10 is just a value till it is assigned to an l value which is i in this case.
    // we can't do something like 10 = i since 10 is an r value.
    int a = i; // in this case we are assigning an l-value to another l-value.
    //r value can also be something returned from a function as shown below
    a = getValue(); // here getValue() is an r value so we can obviously assign anything to it.

    getAnotherValue() = 19; //this works fine since getAnotherValue is returning an l-value;
    //int& is an l-value reference.

    std::string firstName = "Hamza";
    std::string lastName = "Rizvi";
    std::string fullName = firstName+lastName;
    printName(fullName);
    //here, firstName, lastName and fullName are l-values whereas "Hamza", "Rizvi" and firstName+lastName are r-values.
    //this is because the expression firstName+lastName is being stored somewhere temporarily.
    // printName(firstName+lastName); this won't work since the function expects an lvalue reference
    // const& are hence used quite often since they are compatible with both l-values and r-values when accepting arguments for a function.
    printName2(firstName+lastName); //this will work, since printName2 uses a const reference which is compatiable with both l and r values.

    // a simple rule of thumb is : L-VALUES ARE VALUES THAT ARE ALLOCATED IN MEMORY AS VARIABLES WHEREAS R-VALUES ARE TEMPORARY VALUES. (this rule of thumb is subject to change as I learn more about l and r values)

    // we can create functions that use only lvalues using const reference or lvalue reference (same thing).
    // we can however also create functions that only accept r values using r value references.
    // this is done by using two & as && as a reference symbol (see the last overload of printName).
    printName(firstName+lastName);
}