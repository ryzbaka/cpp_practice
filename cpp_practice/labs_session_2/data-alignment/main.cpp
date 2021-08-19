#include <iostream>
using namespace std;

struct Block{
    int i;
    char c;
};

int main(){
    cout<<alignof(int)<<"\n";
    cout<<alignof(char)<<"\n";
    Block b;
    b.i=23;
    b.c='c';
    cout<<alignof(b)<<"\n";
    cout<<sizeof(b)<<"\n";
    return 0;
}

