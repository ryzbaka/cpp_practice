#include <iostream>
#include <cstring>

class String{
    public:
        String()=default; //using default implementation of constructor
        String(const char* string){
            //parameterized constructor
            std::cout<<"Created!\n";
            this->m_Size = strlen(string); //number of characters not including the \0 terminating character
            this->m_Data = new char[this->m_Size]; //initializing a char array on the heap of size m_Size;
            memcpy(this->m_Data,string,m_Size);//copying all contents except for \0 to m_Data;
        }
        String(const String& other){
            std::cout<<"Copy constructor triggered (String)\n";
            this->m_Size = other.m_Size;
            this->m_Data = new char[this->m_Size]; //to copy a String object we're having to create a temporary value on the heap.
            memcpy(this->m_Data,other.m_Data,this->m_Size);
        }
        String(String&& other){
            std::cout<<"Move constructor called (String)\n";
            //move constructor that accepts an rvalue.
            //We'll have to explicitly type-cast the input character array or string to a String&& rvalue type for this to run otherwise it'll just run the copy constructor since const String& in the copy constructor accepts both l and r values.
            this->m_Size = other.m_Size;
            this->m_Data = other.m_Data; //assigning the heap char* pointer to this->m_Data instead of copying

            other.m_Size=0;
            other.m_Data=nullptr; // to prevent dangling pointer if other gets deleted
        }
        ~String(){
            delete this->m_Data; // deleting character array from the heap when String object is destroyed.
            std::cout<<"Destructor called (String)\n";
        }
        void Print(){
            for(int i=0;i<this->m_Size;i++){
                std::cout<<m_Data[i];
            }
            std::cout<<"\n";
        }
    private:
        int m_Size;
        char *m_Data;
};

class Entity{
    public:
        Entity(const String& name):m_Name(name){
        };

        Entity(String&& name):m_Name((String&&)name){
        }; //constructor that specificly accepts rvalues.

        ~Entity(){
        }
        void printName(){
            this->m_Name.Print();
        }
    private:
        String m_Name;
};

int main(){
    Entity e("Hamza"); //due to implicit constructor call, this is the same as Entity(String("Hamza"))
    e.printName();
    return 0;
    /*
    In the output you'll see

    Created! //this is the implicit constructor being called for creating an anonymouse String object (r value) at line 63.
    Move constructor called (String) //anonymous String object's m_Data's heap pointer to e's m_Name's m_Data pointer instead of having to create a temporary char array on the heap for e's m_Name's m_Data pointer and then copying the values to it.
    Destructor called (String) //destroying the anonymous String object.
    Hamza //output for e.printName() which triggers e.m_Name.Print
    Destructor called (String) //destructor for e's m_Name is called since e itself is also getting destroyed. 
    */
}