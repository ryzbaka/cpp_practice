#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream indata;
    indata.open(R"(.\notes.txt)");
    if(!indata){
        cerr<<"Unable to open file.\n";
    }else{
        string line;
        while(getline(indata,line)){
            cout<<line<<"\n";
        }
    }
    return 0;
}