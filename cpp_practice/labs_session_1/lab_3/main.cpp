#include <iostream>
#define PI 3.14

using std::cout;

double area(double r){
    // area of circle
    return PI*r*r;
}

double area(double l, double w){
    // area of rectangle
    return l*w;
}

int main(){
    cout<<area(2.0)<<"\n";
    cout<<area(2.0,4.0)<<"\n";
    return 0;
}