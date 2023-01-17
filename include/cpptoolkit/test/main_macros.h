#ifndef CPPTOOLKIT_TEST_MAIN_MACROS_H_
#define CPPTOOLKIT_TEST_MAIN_MACROS_H_

#include <cpptoolkit/test/header.h>

#include <iostream>

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define CLEAR_COLOR "\033[0m"

#define RUN_MAIN_MACROS                                                        \
  void PrintError(const cpptoolkit::test::tool::TestFailException& ex) {       \
    std::cerr << "Function:\t" << RED_COLOR << ex.function() << CLEAR_COLOR    \
              << std::endl;                                                    \
    std::cerr << "Why:\t\t" << RED_COLOR << ex.why() << CLEAR_COLOR            \
              << std::endl;                                                    \
    std::cerr << "Where:\t\t" << RED_COLOR << ex.where() << CLEAR_COLOR        \
              << std::endl;                                                    \
    std::cerr << std::endl;                                                    \
  }                                                                            \
                                                                               \
  int main() {                                                                 \
    cpptoolkit::test::Core* core = cpptoolkit::test::Core::instance();         \
    if (core == nullptr) {                                                     \
      std::cerr << "Core is null";                                             \
    }                                                                          \
                                                                               \
    try {                                                                      \
      cpptoolkit::test::TestsResult result = core->RunTests();                 \
      if (result.success_tests == result.total_tests) {                        \
        std::cout << GREEN_COLOR << "[" << result.success_tests << "] "        \
                  << "All tests passed!" << CLEAR_COLOR << std::endl;          \
        return 0;                                                              \
      }                                                                        \
                                                                               \
      for (auto it = result.fail_tests.begin(); it != result.fail_tests.end(); \
           it++) {                                                             \
        PrintError(*it);                                                       \
      }                                                                        \
                                                                               \
    } catch (const std::runtime_error& ex) {                                   \
      std::cerr << "Error: " << ex.what() << std::endl;                        \
    } catch (...) {                                                            \
      std::cerr << "Error on test";                                            \
    }                                                                          \
  }

#endif  // CPPTOOLKIT_TEST_MAIN_MACROS_H_
