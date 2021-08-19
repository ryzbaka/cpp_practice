#include <iostream>

using std::cout;

class Singleton{
    private:
        Singleton(){};
        Singleton(Singleton &obj){};
        Singleton& operator=(const Singleton&);
    public:
        ~Singleton(){cout<<"destructor called\n";}
        static Singleton& getInstance(){
            static Singleton instance;
            return instance;
        }
};

int main(){
    Singleton &ref = Singleton::getInstance();
    cout<<&ref<<"\n";
    Singleton &ref2 = Singleton::getInstance();
    cout<<&ref2<<"\n";
    return 0;
}