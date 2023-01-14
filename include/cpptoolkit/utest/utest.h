#ifndef CPPTOOLKIT_UTEST_UTEST_H_
#define CPPTOOLKIT_UTEST_UTEST_H_

#include <iostream>

#define RED_COLOR_START "\033[1;31m"
#define RED_COLOR_STOP "\033[0m\n"

#define GREEN_COLOR_START "\033[1;32m"
#define GREEN_COLOR_STOP "\033[0m\n"

#define TK_ASSERT_EQUAL(expected, actual)   \
  if (expected != actual) {                 \
    std::cerr << RED_COLOR_START << "Test: " << __func__ << " failed" << std::endl  \
      << "Error: " << expected << " is not equal to " << actual << std::endl        \
      << "[" << __LINE__ << "]" << __FILE__ << RED_COLOR_STOP;                      \
  }       \
  return; \

#define TK_ASSERT_TRUE(val)     \
  if (!static_cast<bool>(val)) { \
    std::cerr << RED_COLOR_START << "Test: " << __func__ << " failed" << std::endl  \
      << "Error: " << #val << " is not true" << std::endl                           \
      << "[" << __LINE__ << "]" << __FILE__ << RED_COLOR_STOP;                      \
  }       \
  return; \

#endif // CPPTOOLKIT_UTEST_UTEST_H_

