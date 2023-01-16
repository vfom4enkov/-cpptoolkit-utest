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

#ifndef CPPTOOLKIT_TEST_CORE_H_
#define CPPTOOLKIT_TEST_CORE_H_

#include <cpptoolkit/test/tool/BaseFixture.h>
#include <cpptoolkit/test/tool/TestFailException.h>

#include <vector>

namespace cpptoolkit {
namespace test {

/// struct TestsResult Statistic about tests execution
struct TestsResult {

  /// @total_tests Total test coutn
  uint32_t total_tests;

  /// @success_tests Count of success test
  uint32_t success_tests;

  /// @fail_tests Details about fail tests
  std::vector<cpptoolkit::test::tool::TestFailException> fail_tests;
};

/// @brief Test container and runner (this object is singleton)
class Core {
 public:

  /// @brief Add test fuxture to queue
  /// @param fixture Test fixture (test environment)
  void Add(cpptoolkit::test::tool::BaseFixture *fixture);
  
  /// @brief Run all tests and return statistic
  /// @return Tests statistic
  TestsResult RunTests();

  /// @brief Get pointer to instance of test container
  static Core *instance();

 private:
  Core() = default;

 private:
  std::vector<cpptoolkit::test::tool::BaseFixture *> test_list_;
  static Core *instance_;
};

}  // namespace test
}  // namespace cpptoolkit

#endif  // CPPTOOLKIT_TEST_CORE_H_
