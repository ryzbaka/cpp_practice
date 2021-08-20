#include <iostream>
using namespace std;

template <class T1, class T2>
T2 summation(T1 a, T2 b){
    return a+
}

template <class T1, class T2>
auto summation2(T1 a, T2 b) -> decltype(a+b){
    return a+b
}

int main(){
    int a = 2;
    int b = 3;
    cout<<summation2(2,2.3)<<"\n";
    cout<<summation2(2.3,2)<<"\n";
    return 0;
}