#include "someClass.h"
#include "someOtherClass.h"
using namespace demo;
int main() {
  SomeClass obj(21);
  SomeOtherClass obj2(32);
  obj.show();
  obj2.getOwnValue();
  obj2.friendValue(obj);
  return 0;
}