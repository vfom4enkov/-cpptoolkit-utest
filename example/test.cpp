#include <cpptoolkit/test/header.h>

TK_TEST_CASE(test_compare_two_numbers) {
  int a = 5;
  int b = 5;
  TK_EQUAL(a, b);
}

TK_TEST_CASE(test_compare_two_doubles) {
  double m = 16.005;
  double n = 16.005;
  TK_EQUAL(m, n);
}

TK_TEST_CASE(test_compare_two_strings) {
  std::string str_1 = "test string";
  std::string str_2 = "test string";
  TK_EQUAL(str_1, str_2);
}

TK_TEST_CASE(test_bool_value) {
  bool val = true;
  TK_CHECK(val);
}

TK_TEST_CASE(test_pointer_is_not_null) {
  int num = 16;
  TK_IS_NOT_NULL(&num);
}

TK_TEST_CASE(test_pointer_in_null) {
  int *num = nullptr;
  TK_IS_NULL(num);
}

