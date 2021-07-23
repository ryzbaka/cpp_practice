#pragma once
namespace demo {
class SomeClass {
  friend class SomeOtherClass;

private:
  int _value;

public:
  SomeClass(int x) : _value(x){};
  void show();
};
} // namespace demo