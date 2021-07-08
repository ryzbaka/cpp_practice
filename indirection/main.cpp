/*
A reference is an alias for something else.
You can only set what it refers to once you declare it.
Once you have your reference, anything done to it is being done
to the target.
References cannot change their target once set.

A pointer is also an alias for something else albeit with
a more flexibility.
A pointer doesn't *have* to point to something, it can point to null.
The target for a pointer can be changed.
*/
#include <iostream>

using std::cout;

int main()
{
    //pointers
    int A = 23;
    int *pA = &A;
    cout << pA << "\n";  //address of A
    cout << *pA << "\n"; // value stored at that address
    cout << &pA << "\n"; //address of pointer pA
    int *pB = nullptr;   //use this instead of null which is just a macro for 0.
    cout << &pB << "\n";
    // cout << *pB << "\n";
    //const with indirection
    //const is a way to commit to a compiler that some value won't be changed.
    //const& or constant reference is used in function params for when you want to avoid copying data but also don't want changes to propogate to the original variable.
    //const& also allows you to pass in literals into the function
    int *const ptr = &A;  //the pointer itself is constant and its target cannot be changed (changing *ptr=4 is okay but ptr = &somethingElse is not).
    int const *ptr2 = &A; //indicating that the target is constant and that this pointer cannot be used to change its value weather or not the target itself is const or not (ptr2 = &somethingElse is okay but *ptr2 = 4 is not).
    return 0;
}