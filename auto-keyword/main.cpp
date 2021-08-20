#include <iostream>
#include <typeinfo>

using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base constructor called.\n";
        }
};

void plusTwo(int x){
    cout<<x+2;
}

auto plusTwo(double x){
    double a = x+2;
    cout <<a<<"\n";
    return a;
}
// void plusTwo(auto x){
//     cout<<x+w;
// }  auto keyword doesn't work as function arguments.

int main(){
    auto x = 20;
    auto y = 34.5;
    auto z = Base();

    cout<<typeid(x).name()<<"\n";
    cout<<typeid(y).name()<<"\n";
    cout<<typeid(z).name()<<"\n";

    int a = 23;
    int &aref = a;
    // aref is now an alias of a;
    auto something = a;
    aref = 11;
    cout<< a << "\n";
    something = 12;
    cout<< a<< "\n";
    
    auto result = plusTwo(y);
    cout<< result <<"\n";
    
    // auto v = 10, y=10.0; not valid
    auto v = 10, *v_ptr = &v; // is valid since auto simply gets replaced with int during compile time.

    auto truthValue = false;
    cout<< typeid(truthValue).name()<<"\n";
    return 0;
}
