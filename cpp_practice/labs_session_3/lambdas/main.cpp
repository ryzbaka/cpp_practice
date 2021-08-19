#include <iostream>
#include <vector>
#include <functional> //needed to use std::function


void forEach(std::vector<int> &array,const std::function<void(int)>&func){
    for(int &element:array){
        func(element);
    }
}
// void(*function_ptr)(int) which is a raw function pointer doesn't work with lambda features like captures
// so we use const std::function<return_type(datatype1, datatype2)> &function_name instead.

int main(){
    std::vector<int> a = {1,2,3};

    int x = 32;
    auto lambda = [x](int value){std::cout<<"Value:\t"<<value+x<<"\n";};
    //[] are for captures i.e. when we want to use our own functions in the body of the lambda, this could potentially
    //be used for some pretty sick functional programming where we dynamimcally pass in functions into other functions
    // and so on.
    forEach(a,lambda);
    return 0;
}