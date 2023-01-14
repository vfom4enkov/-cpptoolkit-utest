#ifndef CPPTOOLKIT_UTEST_MACROS_H_
#define CPPTOOLKIT_UTEST_MACROS_H_

#define RED_COLOR_START "\033[1;31m"
#define GREEN_COLOR_START "\033[1;32m"
#define COLOR_STOP "\033[0m\n"

#define FAIL_TEST_OUT(x) \
  std::cerr << RED_COLOR_START  \
      << "Test:\t" << __func__ << " failed" << std::endl          \
      << "Error:\t" << x << std::endl \
      << "Where:\t" << __FILE__ << ":" << __LINE__ << COLOR_STOP;\

#define TK_CHECK_EQUAL(expected, actual)\
  if (expected != actual) {             \
    FAIL_TEST_OUT(expected << " is not equal to " << actual)\
    return;\
  } 

#define TK_CHECK(val)           \
  if (!static_cast<bool>(val)) {\
    FAIL_TEST_OUT(#val << " is not true")\
    return;\
  }

#define TK_CHECK_IS_NULL(ptr) \
  if (ptr != nullptr) {       \
    FAIL_TEST_OUT("pointer is not null")\
    return;\
  }

#endif // CPPTOOLKIT_UTEST_MACROS_H_

