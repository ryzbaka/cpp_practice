#include <iostream>
#include <string>
/*
    Local variables go out of scope when the function ends.
    We use free store to make sure this doesn't happen when we don't want it to.
    The 'new' keyword is used to obtain memory from the free store. It allocates memory, runs constructor and returns a pointer.
    The 'delete' keyword is used to call the desctructor and free up memory.
*/
class Resource
{
private:
    std::string name;

public:
    Resource(std::string n) : name(n){};
    ~Resource() { std::cout << "Destroyed: " << this->name << "\n"; };
    std::string getName() const { return name; };
};
int main()
{
    {
        Resource localResource = Resource("local");
        std::string localString = localResource.getName();
    }

    Resource *resource_ptr = new Resource("created with new");
    std::string new_string = resource_ptr->getName();
    delete resource_ptr;
    return 0;
}