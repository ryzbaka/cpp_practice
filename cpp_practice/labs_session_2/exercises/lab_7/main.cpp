#include <iostream>
using namespace std;

constexpr int add(int a, int b){
    return a+b;
}

int main(){
    int a;
    int b;
    cin>>a>>b;
    cout<<add(a,b)<<"\n"; //result not computed during compile time because dependant on input.
    cout<<add(1,2)<<"\n"; //result computed during compile time since input is constant and so is the expression.
    return 0;
}