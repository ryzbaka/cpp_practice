//Inline functions and macros in C++
//Inline functions bypass the overhead of control switching 
//and is generally used for smaller functions whose execution
//time is significantly smaller than the control switching time.
//They do however, increase the size of compiled binary files.
#include <iostream>
using std::cout;
inline int getTwo(){
    return 2;
}
//MACROS act as an alias for a certain piece of code
#define FIVE 5
int main(){
    int x =getTwo();
    cout<<x<<"\n";
    cout<<FIVE<<"\n";
    return 0;
}