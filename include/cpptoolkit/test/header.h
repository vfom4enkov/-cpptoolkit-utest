/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2023, Vladimir Fomchenkov
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CPPTOOLKIT_TEST_HEADER_H_
#define CPPTOOLKIT_TEST_HEADER_H_

#include <cpptoolkit/test/core.h>
#include <cpptoolkit/test/tool/common.h>

#include <sstream>
#include <string>

namespace cpptoolkit {
namespace test {
namespace tool {

/// @brief Mock fixture for tests without fixture
class MockFixture {};

}  // namespace tool
}  // namespace test
}  // namespace cpptoolkit

#define __TK_MACROS_TO_STRINGIFY(str) #str

#define __TK_MACROS_TO_STRING(str) __TK_MACROS_TO_STRINGIFY(str)

#define __TK_MACROS_STRING_CONCATENATION(a, b) a##b
#define __TK_MACROS_STRING_CONCATENATION3(a, b, c) a##b##c

#define __TK_MACROS_THROW(why) \
  cpptoolkit::test::tool::ThrowTestFailException(why, __FILE__, __LINE__);

#define TK_EQUAL_STR(actual, expected)                                 \
  if (expected != actual) {                                            \
    __TK_MACROS_THROW(                                                 \
        cpptoolkit::test::tool::StrNotEqualMessage(actual, expected)); \
  }

#define TK_EQUAL_VAL(actual, expected)                                 \
  if (expected != actual) {                                            \
    __TK_MACROS_THROW(                                                 \
        cpptoolkit::test::tool::ValNotEqualMessage(actual, expected)); \
  }

#define TK_EQUAL(actual, expected)             \
  if (expected != actual) {                    \
    __TK_MACROS_THROW("values are not equal"); \
  }

#define TK_CHECK(val)                        \
  if (!static_cast<bool>(val)) {             \
    std::string why = "the check is failed"; \
    __TK_MACROS_THROW(why);                  \
  }

#define TK_IS_NULL(ptr)                           \
  if (ptr != nullptr) {                           \
    std::string why = __TK_MACROS_TO_STRING(ptr); \
    why += " is not null";                        \
    __TK_MACROS_THROW(why);                       \
  }

#define TK_IS_NOT_NULL(ptr)                       \
  if (ptr == nullptr) {                           \
    std::string why = __TK_MACROS_TO_STRING(ptr); \
    why += " is null";                            \
    __TK_MACROS_THROW(why);                       \
  }

#define TK_FIXTURE_TEST_CASE(test_name, fixture)                            \
  class __TK_MACROS_STRING_CONCATENATION(test_name, __fixture)              \
      : public fixture {                                                    \
   public:                                                                  \
    void Test();                                                            \
  };                                                                        \
  class __TK_MACROS_STRING_CONCATENATION(test_name, __base_test)            \
      : public cpptoolkit::test::tool::BaseTest {                           \
   public:                                                                  \
    __TK_MACROS_STRING_CONCATENATION(test_name, __base_test)() {            \
      cpptoolkit::test::Core::instance()->Add(this);                        \
    };                                                                      \
    virtual ~__TK_MACROS_STRING_CONCATENATION(test_name, __base_test)(){};  \
    void Run() override {                                                   \
      __TK_MACROS_STRING_CONCATENATION(test_name, __fixture) test_instance; \
      test_instance.Test();                                                 \
    };                                                                      \
    std::string name() override {                                           \
      return std::string(__TK_MACROS_TO_STRING(test_name));                 \
    };                                                                      \
  } __TK_MACROS_STRING_CONCATENATION3(test_name, __base_test, _instance);   \
  void __TK_MACROS_STRING_CONCATENATION(test_name, __fixture)::Test()

#define TK_TEST_CASE(test_name) \
  TK_FIXTURE_TEST_CASE(test_name, cpptoolkit::test::tool::MockFixture)

#endif  // CPPTOOLKIT_TEST_HEADER_H_
