#ifndef CPPTOOLKIT_TEST_TEST_FAIL_EXCEPTION_H_
#define CPPTOOLKIT_TEST_TEST_FAIL_EXCEPTION_H_

#include <stdexcept>
#include <string>

namespace cpptoolkit {
namespace test {
namespace tool {

/// @brief Custom exception with data about failed test 
class TestFailException : public std::runtime_error {
 public:

  /// @brief Create custom exception
  /// @param function Name of test function where the test was failed
  /// @param why Short description why the test fail
  /// @param where Path to file name and line number where test fail
  TestFailException(const char* function, const char* why, const char* where)
      : std::runtime_error(why),
        function_(function),
        why_(why),
        where_(where){};

  /// @brief Get test function where test fail 
  const std::string& function() const { return function_; };
  
  /// @brief Get fail description
  const std::string& why() const { return why_; };
  
  /// @brief Get path to file and line number where test fail
  const std::string& where() const { return where_; };

 private:
  const std::string function_;
  const std::string why_;
  const std::string where_;
};

} // namespace tool
} // namespace test
} // namespace cpptoolkit

#endif  // CPPTOOLKIT_TEST_TEST_FAIL_EXCEPTION_H_

