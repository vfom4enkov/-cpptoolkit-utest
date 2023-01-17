#include <cpptoolkit/test/header.h>

TK_TEST_CASE(test_compare_two_numbers_fail) {
  int a = 5;
  int b = 6;
  TK_EQUAL(a, b);
}

TK_TEST_CASE(test_compare_two_doubles_fail) {
  double m = 16.005;
  double n = 16.0009;
  TK_EQUAL(m, n);
}

TK_TEST_CASE(test_compare_two_strings_fail) {
  std::string str_1 = "test string";
  std::string str_2 = "test string!";
  TK_EQUAL(str_1, str_2);
}

TK_TEST_CASE(test_bool_value_fail) {
  bool val = false;
  TK_CHECK(val);
}

TK_TEST_CASE(test_pointer_is_not_null_fail) {
  int *num = nullptr;
  TK_IS_NOT_NULL(num);
}

TK_TEST_CASE(test_pointer_in_null_fail) {
  int num = 0xffff;
  TK_IS_NULL(&num);
}

