#include <iostream>
#include <string>

int main(){
    std::cout<<"Enter something:"<<"\n";
    std::string something;
    std::cin>>something;
    std::cout<<"hello"<<something<<"\n";
    std::string name = "Hamza Ali Rizvi";
    std::cout<<name<<"\n";
    std::cout<<"Length of string is: "<<name.length()<<"\n";
    std::cout<<name.substr(0,2)<<"\n"; // substring (start index, endindex+1)
    std::cout<<name.find("Al")<<"\n";
    std::cout<<name.find("g")<<"\n";//sub-string is not found it returns string::npos(string::pos 
    //is static member with value as the highest possible for the size_t data structure).
    std::cout<<name.at(0)<<"\n";
    return 0;
    //https://en.cppreference.com/w/cpp/string/basic_string
}