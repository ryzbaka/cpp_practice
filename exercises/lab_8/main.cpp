#include <iostream>
#include <vector>
using namespace std;
using Int32Bit = int;
using IntVector = vector<int>;
using array2d = vector<vector<int>>; 
using functionPointer = void(*)(int &);

void add2(int &a){
    a+=2;
}

int main(){
    //function pointers example
    void (*ptr)(int &);    
    ptr = add2;
    int x = 23;
    ptr(x);
    cout<<x<<"\n";
    //////////////////
    
    IntVector array = {1,2,3};
    functionPointer fptr = add2;
    for(auto &element: array){
        fptr(element);
        cout<<element<<"\n";
    }
    return 0;
}