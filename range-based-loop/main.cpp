#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> array ={1,2,3,4};
    for(int &element:array){
        cout<<element<<"\n";
        cout<<&element<<"\n";
    }
    cout<<"\n\n\n\n";
    for(int &element:array){
        cout<<element<<"\n";
        cout<<&element<<"\n";
    }
   cout<<"\n\n\n\n"; 
    for(int element:array){
        cout<<element<<"\n";
        cout<<&element<<"\n";
    }
    return 0;
}