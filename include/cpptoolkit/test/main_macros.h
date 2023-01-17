#ifndef CPPTOOLKIT_TEST_MAIN_MACROS_H_
#define CPPTOOLKIT_TEST_MAIN_MACROS_H_

#include <cpptoolkit/test/header.h>

#include <iostream>

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define CLEAR_COLOR "\033[0m"

#define RUN_MAIN_MACROS                                                 \
  std::string PrintTestResult(bool result) {                            \
    std::string r("");                                                  \
    if (result) {                                                       \
      r += GREEN_COLOR;                                                 \
      r += "ok";                                                        \
    } else {                                                            \
      r += RED_COLOR;                                                   \
      r += "FAILED";                                                    \
    }                                                                   \
    r += CLEAR_COLOR;                                                   \
    return r;                                                           \
  }                                                                     \
                                                                        \
  class MainObserver : public cpptoolkit::test::Observer {              \
   public:                                                              \
    MainObserver() : success_(0), failed_(0){};                         \
    virtual ~MainObserver(){};                                          \
    void Test(cpptoolkit::test::TestResult& result) override {          \
      std::cout << "test " << result.name << " ... "                    \
                << PrintTestResult(result.is_success) << std::endl;     \
      if (result.is_success) {                                          \
        success_++;                                                     \
      } else {                                                          \
        std::cout << "\twhy:\t" << result.why << std::endl;             \
        std::cout << "\twhere:\t" << result.where << std::endl;         \
        std::cout << std::endl;                                         \
        failed_++;                                                      \
      }                                                                 \
    };                                                                  \
    uint32_t success() { return success_; };                            \
    uint32_t failed() { return failed_; };                              \
                                                                        \
   private:                                                             \
    uint32_t success_;                                                  \
    uint32_t failed_;                                                   \
  };                                                                    \
                                                                        \
  int main() {                                                          \
    cpptoolkit::test::Core* core = cpptoolkit::test::Core::instance();  \
    if (core == nullptr) {                                              \
      std::cerr << "Core is null" << std::endl;                         \
    }                                                                   \
                                                                        \
    MainObserver observer;                                              \
    try {                                                               \
      uint32_t test_count = core->count();                              \
      if (test_count == 1) {                                            \
        std::cout << "running 1 test" << std::endl;                     \
      } else {                                                          \
        std::cout << "running " << test_count << " tests" << std::endl; \
      }                                                                 \
                                                                        \
      core->RunTests(&observer);                                        \
      std::cout << "test result: " << observer.success() << " passed; " \
                << observer.failed() << " failed;" << std::endl;        \
    } catch (const std::runtime_error& ex) {                            \
      std::cerr << "Error: " << ex.what() << std::endl;                 \
    } catch (...) {                                                     \
      std::cerr << "Error on test" << std::endl;                        \
    }                                                                   \
  }

#endif  // CPPTOOLKIT_TEST_MAIN_MACROS_H_
