#include <cpptoolkit/test/header.h>

#include <string>

namespace {
class Fixture {
  public:
    Fixture* This();
    Fixture* Nullptr();
  public:
    int value = 10;
    double d_value = 20.0006;
    std::string str = "Fixture string";
};

Fixture* Fixture::This() {
  return this;
}

Fixture* Fixture::Nullptr() {
  return nullptr;
}

}  // namespace

TK_FIXTURE_TEST_CASE(test_fixture, Fixture) {
  TK_EQUAL(10, value);
  TK_EQUAL(20.0006, d_value);
  TK_EQUAL("Fixture string", str);
  TK_IS_NOT_NULL(This());
  TK_IS_NULL(Nullptr());
}
