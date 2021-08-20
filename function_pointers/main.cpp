#include <iostream>
#include <vector>
/*
 In functional programming, functions are treated as first-class citizens,
 meaning that they can be bound to names (including local identifiers),
 passed as arguments, and returned from other functions,
 just as any other data type can. This allows programs to be written in a declarative and composable style,
 where small functions are combined in a modular manner.
*/

//functions for basic demo.
void HelloWorld(int a){
    std::cout<<"Hello world\t"<<a<<"\n";
}
void HelloWorld(){
    std::cout<<"Hello world\n";
}

//functions for vectors demo.
void printValue(int &value){
    std::cout<<value<<"\n";
}
void forEach(std::vector<int> &array,void (*f)(int&)){
    for(int &element:array){
        f(element);
    }
}
int main(){
    //auto function = HelloWorld;//auto cannot deduce the type if the function is overloaded.
    //function();
    
    //function pointer type ->      returnType(*pointerName)(datatype1,datatype2,...) = functionName;

    void(*function2)(void) =HelloWorld;
    function2();

    void(*function)(int) = HelloWorld;
    function(2);
    
    //Application for vectors
    std::vector<int> numbers = {1,2,3,4,5};
    forEach(numbers,printValue);
    
    //anonymous functions - lambdas
    forEach(numbers,[](int &x){
        std::cout<<"Value:\t"<<x<<"\n";       
    });
}