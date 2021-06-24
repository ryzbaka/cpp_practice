#include <iostream>
#include "functions.h"

int main(){
        int result1 = add(2,3);
        float result2 = add(3.4,5.5);
        std::cout<<result1<<"\n";
        std::cout<<result2<<"\n";
       return 0;
}

//run g++ functions_and_headers.cpp functions.cpp to compile and build.