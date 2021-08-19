#include <iostream>
using namespace std;

void f(int x){
    cout<<"Integer!\n";
}

void f(int *x){
    cout<<"Pointer!\n";
}

int main(){
    auto x= nullptr;
    auto y= NULL;
    f(x);
    f(y);
}