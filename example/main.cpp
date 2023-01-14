#include <cpptoolkit/utest/utest.h>
#include <cassert>

void test_f() {
  TK_ASSERT_EQUAL(5, 6);
}

void test_t() {
  TK_ASSERT_TRUE(5 == 6);
}

int main() {
  assert(true);
  test_f();
  test_t();
  std::cout << GREEN_COLOR_START << "Hello!" << GREEN_COLOR_STOP << std::endl;
}
