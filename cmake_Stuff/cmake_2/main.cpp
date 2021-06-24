#include <iostream>
#include "functions.h"
int main(){
    std::cout<<"Hello CMake 2!\n";
    float x = 23.4;
    float y = 2.2;
    float result = add(x,y);
    std::cout<<result<<"\n";
    std::cout<<"NICE\n";
    return 0;
}