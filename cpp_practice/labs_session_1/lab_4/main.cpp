#include <iostream>
#include <cmath>
using std::cout;
using std::cin;

double calculateEMI(double p=0.0, double r=0.0, double n=0.0){
    return p*r*(pow(1+r,n)/(pow(1+r,n)-1));
}

int main(){
    double principal, rate, months;
    cin>>principal;
    cin>>rate;
    cin>>months;
    double emi = calculateEMI(principal, rate, months);
    cout<<emi;
    return 0;
}