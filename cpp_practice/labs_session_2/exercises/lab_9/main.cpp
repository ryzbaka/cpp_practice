#include <iostream>
using namespace std;

constexpr int add(int a, int b){return a+b;}

int main(){
    constexpr int a = add(3,2); //add should also be constexpr
    static_assert(a==5, "Nope."); 
    // the goal of static assert is to test constexpr functions and values during compile time, whereas assert is used for testing functions and values during runtime.
    return 0;
}