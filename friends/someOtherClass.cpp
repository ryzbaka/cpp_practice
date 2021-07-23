#include "someOtherClass.h"
#include "someClass.h"
#include <iostream>
using std::cout;
namespace demo {
void SomeOtherClass::getOwnValue() { cout << _value << "\n"; }
void SomeOtherClass::friendValue(SomeClass &obj) { cout << obj._value << "\n"; }
} // namespace demo