#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> array2d = {{1,2},{3,4}};
    for(auto row:array2d){
        for(auto element:row){
            cout<<element<<"\n";
        }
    }
    return 0;
}