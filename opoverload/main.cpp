#include <iostream>

class A{
    private:
        int x;
    public:
        A(int y):x(y){}
        A(const A &obj){
            x = obj.x;
        }
        ~A(){std::cout<<"Destructor called\n";}
        A& operator=(const A &obj){
            if(this == &obj){
                return *this;
            }
            std::cout<<"Copy assignment operator\n";
            x = obj.x;
            return *this;
        }
        void showX(){
            std::cout<<x<<"\n";
        }
};

int main(){
    A a(23);
    A b(32);
    a.showX();
    a=b;
    a.showX();
}