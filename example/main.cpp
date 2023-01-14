#include <cpptoolkit/utest/utest.h>
#include <cpptoolkit/utest/macros.h>
#include <cassert>

void test_f() {
  TK_TEST_EQUAL(5, 6);
}

void test_t() {
  TK_TEST_TRUE(5 == 6);
}

void test_d() {
  TK_TEST_FALSE(true)
}

void test_null() {
  int d = 5;
  TK_TEST_IS_NULL(&d);
}

int main() {
  // test_f();
  // test_t();
  // test_d();
  test_null();
  std::cout << GREEN_COLOR_START << "Hello!" << COLOR_STOP << std::endl;
}

