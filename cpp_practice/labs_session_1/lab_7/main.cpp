// A singleton class is one that can only ever be instantiated once.
#include <iostream>
#include <cassert>
using std::cout;

class Singleton{
    private:
        int value;
        Singleton(int x=0):value(x){}; //constructor
        Singleton(Singleton &obj){};   //copy constructor
        void operator=(Singleton&obj); //copy assignment operator
        static Singleton* instance;     //the single static instance associated with the singleton class;
        //privated so that delete keyword cannot be called on instance directly.
        ~Singleton(){                  //destructor
            cout<<"Singleton destructor called.\n";
        }
    public:

        void setValue(int x){          //setter
            assert(instance!=nullptr && "Trying to access instance that has been destroyed.");
            this->value = x;
        }

        int getValue() const{           //getter
            assert(instance!=nullptr && "Trying to access instance that has been destroyed.");
            return this->value;
        }

        static Singleton& getInstance(){ //changed to reference so there is no chance of deletion using the delete keyword.
            if(instance==nullptr){
                instance = new Singleton();
            }
            return *instance;
        }
        static void destroyInstance(){
            if(instance){
                delete instance;
                instance = nullptr;
            }
        }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton &ref1 = Singleton::getInstance();
    Singleton &ref2 = Singleton::getInstance();
    ref1.setValue(23);
    cout<<ref2.getValue()<<"\n";
    // ref1.~Singleton(); 
    // The class destructor does not do anything except print "Singleton destructor called".
    // destructor has been made private so that it can only be triggered from the destroyInstance code block,
    // otherwise it raises an error during compile time.
    Singleton::destroyInstance();
    cout<<ref2.getValue()<<"\n"; //will cause instance!=nullptr assertion to fail -> program terminated.
    return 0;
}


//create a static vector that keeps track of all the references, push back when running getInstance before returning. 