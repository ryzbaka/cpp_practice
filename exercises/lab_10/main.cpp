#include <iostream>
using namespace std;

//plain enums
enum flowers{
    lotus,
    rose
};
enum cars{
    ferrari,
    nissan
};

//scoped enum
enum class FileError{
    FileNotFound,
    ok
};

enum class NetworkError{
    ConnectionFailed,
    ok
};

int main(){
    //PLAIN ENUM DEMO
    flowers f1 = flowers::lotus;
    cars c1 = cars::ferrari;
    if(c1==f1){ // this is bad since the enums are implicitly getting converted to their integer values without any regard to the enum type.
        cout<<"this is bad.\n";
    }
    //also in plain enums we can say that an enum value is local to the enum type.
    //example: cars enum in this program cannot have a value called lotus.
    
    //SCOPED ENUM DEMO
    FileError fe = FileError::ok;
    NetworkError ne = NetworkError::ok;
    //~ same enum value ok can be used by two different enum types

    // if(fe==ne){
    //     cout<<"bad\n";
    // }  -  no implicit conversion to int so this will give an error
    return 0;
}