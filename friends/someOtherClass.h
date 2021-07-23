#pragma once
#include "someClass.h"
namespace demo {
class SomeOtherClass {
private:
  int _value;

public:
  SomeOtherClass(int x) : _value(x){};
  void getOwnValue();
  void friendValue(SomeClass &obj);
};
} // namespace demo