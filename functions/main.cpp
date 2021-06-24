#include <iostream>
#include "Utilities.h"

using std::cout;

int main()
{
    bool result = isPrime(42);
    result ? cout << "The number is prime" : cout << "the number is not prime";
    return 0;
}