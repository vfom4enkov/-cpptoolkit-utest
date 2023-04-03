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

#ifndef CPPTOOLKIT_TEST_RUN_ALL_MACROS_H_
#define CPPTOOLKIT_TEST_RUN_ALL_MACROS_H_

#define TK_GET_READY_FOR_TESTS                                            \
  const std::string RED = "\033[1;31m";                                   \
  const std::string GREEN = "\033[1;32m";                                 \
  const std::string CLEAR = "\033[0m";                                    \
                                                                          \
  void PrintTest(const cpptoolkit::test::TestResult& test) {              \
    std::cout << (test.is_success ? GREEN + "   OK  " : RED + " FAILED")  \
              << CLEAR << "\t test: " << test.name << std::endl;          \
    if (!test.is_success) {                                               \
      std::cout << "\twhy:\t" << test.why << std::endl;                   \
      std::cout << "\twhere:\t" << test.where << std::endl;               \
      std::cout << std::endl;                                             \
    }                                                                     \
  }                                                                       \
                                                                          \
  int Run() {                                                             \
    cpptoolkit::test::Core* core = cpptoolkit::test::Core::instance();    \
    if (core == nullptr) {                                                \
      return 2;                                                           \
    }                                                                     \
                                                                          \
    int res = 0;                                                          \
    try {                                                                 \
      std::cout << "running " << core->count() << " test"                 \
                << (core->count() == 1 ? "s" : "") << std::endl;          \
                                                                          \
      uint32_t success = 0;                                               \
      uint32_t failed = 0;                                                \
      std::vector<cpptoolkit::test::TestResult> tests = core->RunTests(); \
      for (const cpptoolkit::test::TestResult& test : tests) {            \
        PrintTest(test);                                                  \
        if (test.is_success) {                                            \
          success++;                                                      \
        } else {                                                          \
          res = 1;                                                        \
          failed++;                                                       \
        }                                                                 \
      }                                                                   \
      std::cout << std::endl;                                             \
      std::cout << "test result: " << success << " passed; " << failed    \
                << " failed;" << std::endl;                               \
      std::cout << std::endl;                                             \
      return res;                                                         \
    } catch (const std::runtime_error& ex) {                              \
      std::cerr << "Error: " << ex.what() << std::endl;                   \
      return 3;                                                           \
    } catch (...) {                                                       \
      return 4;                                                           \
    }                                                                     \
  }

#endif  // CPPTOOLKIT_TEST_RUN_ALL_MACROS_H_
