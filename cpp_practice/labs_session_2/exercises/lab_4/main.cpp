#include <iostream>
using namespace std;
/*
Alignment is a restriction on which memory positions a value's first byte can be stored. (It is needed to improve performance on processors and to permit use of certain instructions that works only on data with particular alignment, for example SSE need to be aligned to 16 bytes, while AVX to 32 bytes.)
*/

struct alignas(16) x{
    int i; //4 bytes
    int j; //4 bytes
    alignas(4) char c[3]; //3 bytes ->aligned to 4
    short s;// 2 bytes
};

int main(){
    cout<<alignof(x)<<"\n";
    cout<<sizeof(x)<<"\n";
    return 0;
    //when we say something is aligned to n, we mean that it can only be stored on address that are multiples of n.
}