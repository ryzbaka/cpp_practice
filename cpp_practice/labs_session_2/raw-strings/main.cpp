#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "C:\files\notes.txt";
    cout<<s<<"\n";
    string rawString = R"(C:\files\notes.txt)";
    cout<<rawString<<"\n";
    return 0;
}