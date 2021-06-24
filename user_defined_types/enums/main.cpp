#include <iostream>
using std::cout;

enum Status
{
    Pending = 2,
    Approved,
    Cancelled
};

enum class FileError
{
    notfound = 3,
    ok
};

enum class NetworkError
{
    disconnected,
    ok
};
/*
FileError and NetworkError are both scoped enums or (enum class) that allow underlying types other than int,
can have non unique names and use fully qualified names.
*/

int main()
{
    Status s = Pending;
    FileError fe = FileError::notfound;
    NetworkError ne = NetworkError::disconnected;
    return 0;
}

//#pragma once prevents repasting of code