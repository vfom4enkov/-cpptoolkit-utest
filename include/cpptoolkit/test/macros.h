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

#ifndef CPPTOOLKIT_TEST_MACROS_H_
#define CPPTOOLKIT_TEST_MACROS_H_

#include <cpptoolkit/test/core.h>
#include <cpptoolkit/test/tool/base_fixture.h>
#include <cpptoolkit/test/tool/common.h>

#include <string>

namespace cpptoolkit {
namespace test {
namespace tool {

/// @brief Mock fixture for tests without fixture
class MockFixture {};

} // namespace tool
} // namespace test
} // namespace cpptoolkit

#define _TK_MACROS_TO_STRINGIFY(str) #str

#define _TK_MACROS_TO_STRING(str) _TK_MACROS_TO_STRINGIFY(str)

#define _TK_MACROS_STRING_CONCATENATION(a, b) a##b
#define _TK_MACROS_STRING_CONCATENATION3(a, b, c) a##b##c

#define __TK_MACROS_THROW(why)                                                \
  cpptoolkit::test::tool::ThrowTestFailException( __func__,                   \
                                                  why,                        \
                                                  __FILE__,                   \
                                                  __LINE__);

#define TK_EQUAL(expected, actual)                                            \
  if (expected != actual) {                                                   \
    std::string why = std::to_string(expected)                                \
            + " is not equal to "                                             \
            + std::to_string(actual);                                         \
    __TK_MACROS_THROW(why);                                                   \
  }

#define TK_CHECK(val)                                                         \
  if (!static_cast<bool>(val)) {                                              \
    std::string why = _TK_MACROS_TO_STRING(val) + " is not true";             \
    __TK_MACROS_THROW(why);                                                   \
  }

#define TK_IS_NULL(ptr)                                                       \
  if (ptr != nullptr) {                                                       \
    std::string why = _TK_MACROS_TO_STRING(ptr) + " is not null";             \
    __TK_MACROS_THROW(why);                                                   \
  }

#define TK_IS_NOT_NULL(ptr)                                                   \
  if (ptr == nullptr) {                                                       \
    std::string why = _TK_MACROS_TO_STRING(ptr) + " is null";                 \
    __TK_MACROS_THROW(why);                                                   \
  }

#define TK_FIXTURE_TEST_CASE(test_name, fixture)                              \
class _TK_MACROS_STRING_CONCATENATION(test_name, _class) :                    \
      public cpptoolkit::test::tool::BaseFixture,                             \
      public fixture {                                                        \
        public:                                                               \
          _TK_MACROS_STRING_CONCATENATION(test_name, _class)() : fixture() {  \
            cpptoolkit::test::Core::instance()->Add(this);                    \
          };                                                                  \
          virtual ~_TK_MACROS_STRING_CONCATENATION(test_name, _class)() {};   \
          void Test() override;                                               \
      } _TK_MACROS_STRING_CONCATENATION3(test_name, _class, _instance);       \
      void _TK_MACROS_STRING_CONCATENATION(test_name, _class)::Test()

#define TK_TEST_CASE(test_name)                                               \
  TK_FIXTURE_TEST_CASE(test_name, cpptoolkit::test::tool::MockFixture)

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

#define TK_CHECK_IS_NULL(ptr) \
  if (ptr != nullptr) {       \
    FAIL_TEST_OUT("pointer is not null")\
    return;\
  }

#endif // CPPTOOLKIT_TEST_MACROS_H_

