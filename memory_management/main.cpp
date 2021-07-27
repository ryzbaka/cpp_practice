#include <iostream>
#include <string>
/*
    Local variables go out of scope when the function ends.
    We use free store to make sure this doesn't happen when we don't want it to.
    The 'new' keyword is used to obtain memory from the free store. It allocates
   memory, runs constructor and returns a pointer. The 'delete' keyword is used
   to call the destructor and free up memory. The free store is for longer
   lived variables.
*/
class Resource {
private:
  std::string name;

public:
  Resource(std::string n) : name(n){};
  ~Resource() { std::cout << "Destroyed: " << this->name << "\n"; };
  std::string getName() const { return name; };
};
int main() {
  {
    Resource localResource =
        Resource("local"); // local variable stored on the stack.
    std::string localString = localResource.getName();
  }

  Resource *resource_ptr =
      new Resource("created with new"); // objects created with the new keyword
                                        // are stored in the free store (heap).
  std::string new_string = resource_ptr->getName();
  delete resource_ptr;
  resource_ptr =
      nullptr; // common practice of setting pointer to nullptr after deleting,
               // since null pointer exceptions are easier to catch.
  // RULE OF THREE
  /*
      If you're going to have a pointer to the free store (heap), keep it in an
     object so that we can use member functions to manage it. For example, the
     destructor of the object can `delete` the pointer so that memory gets
     cleaned up automatically when the object goes out of scope. Another issue
     that we can face when doin manual memory management is running into errors
     when copying pointers. Copy constructors can be used to work our way around
     such issues. The copy assignment operator not only initializes the new
     object with the values of the old object whose copy you're making

  */
  // RULE OF FIVE
  /*
      In a scenario where an expensive resource is stored in an object that is
     about to go out of scope, we can move the resource to another object rather
     than deleting and creating again. We can do this using a move constructor
     and a move assignment operator.
  */
  return 0;
}