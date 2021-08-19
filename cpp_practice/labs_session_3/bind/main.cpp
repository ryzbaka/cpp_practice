#include <iostream>
#include <functional>
#include <string>

void print(const int& i){
    std::cout<<i<<"\n";
}

void print2(const int& i, std::string s){
    std::cout<<i<<"\t"<<s<<"\n";
}


int main(){
    int i = 5;
    const auto f = std::bind(&print, i);
    f(); //will print 5
    i = 6;
    f(); //will print 5, despite value of i being changed.

    //to track the value of i in the function, we'll have to std::ref.
    const auto f2 = std::bind(&print,std::ref(i));
    f2();
    i = 32;
    f2(); //changed value of i will be reflected.

    // using placeholders.
    std::string s="Hello";
    const auto f3 = std::bind(&print2, std::placeholders::_1,std::ref(s)); //placeholders to be for aruguments we want from the user.
    f3(78); //this will print 78    Hello
    s = "bye";
    f3(23); //this will print 23    bye

    //switching argument positions
    const auto f4 = std::bind(&print2, std::placeholders::_2, std::placeholders::_1);
    f4("flipped",23); //23  flipped

    //swallowing extra arguments
    //if we provide the bind function extra arguments, it'll still work with the arguments it needs to use and just not use the rest.
    f4("ok",45,23,'a',34); //45  ok

    //binds can be passed into std::function objects
    std::function<void(std::string,const int &i)> f5(f4); //arguments are flipped when compared to print2 because we flipped them using placeholder for f4.
    f5("not okay", 34);
    
    //try experimenting with std::bind in tandem with std::function and lambdas with vectors.
    return 0;
}