#ifndef CPPTOOLKIT_TEST_MACROS_H_
#define CPPTOOLKIT_TEST_MACROS_H_

#include <cpptoolkit/test/core.h>
#include <cpptoolkit/test/tool/common.h>

#include <string>

namespace cpptoolkit {
namespace test {
namespace tool {

/// @brief Mock fixture for tests without fixture
class MockFixture {};

}  // namespace tool
}  // namespace test
}  // namespace cpptoolkit

#define _TK_MACROS_TO_STRINGIFY(str) #str

#define _TK_MACROS_TO_STRING(str) _TK_MACROS_TO_STRINGIFY(str)

#define _TK_MACROS_STRING_CONCATENATION(a, b) a##b
#define _TK_MACROS_STRING_CONCATENATION3(a, b, c) a##b##c

#define __TK_MACROS_THROW(why)                                            \
  cpptoolkit::test::tool::ThrowTestFailException(__func__, why, __FILE__, \
                                                 __LINE__);

#define TK_EQUAL(expected, actual)                                     \
  if (expected != actual) {                                            \
    std::string why = "Values are not equal!";                         \
    __TK_MACROS_THROW(why);                                            \
  }

#define TK_CHECK(val)                                             \
  if (!static_cast<bool>(val)) {                                  \
    std::string why = "The check is failed";                      \
    __TK_MACROS_THROW(why);                                       \
  }

#define TK_IS_NULL(ptr)                                           \
  if (ptr != nullptr) {                                           \
    std::string why = _TK_MACROS_TO_STRING(ptr);                  \
    why += " is not null";                                        \
    __TK_MACROS_THROW(why);                                       \
  }

#define TK_IS_NOT_NULL(ptr)                                   \
  if (ptr == nullptr) {                                       \
    std::string why = _TK_MACROS_TO_STRING(ptr);              \
    why += " is null";                                        \
    __TK_MACROS_THROW(why);                                   \
  }

#define TK_FIXTURE_TEST_CASE(test_name, fixture)                       \
  class _TK_MACROS_STRING_CONCATENATION(test_name, _class)             \
      : public cpptoolkit::test::tool::BaseFixture, public fixture {   \
   public:                                                             \
    _TK_MACROS_STRING_CONCATENATION(test_name, _class)() : fixture() { \
      cpptoolkit::test::Core::instance()->Add(this);                   \
    };                                                                 \
    virtual ~_TK_MACROS_STRING_CONCATENATION(test_name, _class)(){};   \
    void Test() override;                                              \
  } _TK_MACROS_STRING_CONCATENATION3(test_name, _class, _instance);    \
  void _TK_MACROS_STRING_CONCATENATION(test_name, _class)::Test()

#define TK_TEST_CASE(test_name) \
  TK_FIXTURE_TEST_CASE(test_name, cpptoolkit::test::tool::MockFixture)

#endif // CPPTOOLKIT_TEST_MACROS_H_

