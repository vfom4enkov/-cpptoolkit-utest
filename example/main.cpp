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

#include <cpptoolkit/test/header.h>

#include <iostream>

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define CLEAR_COLOR "\033[0m"

void PrintError(const cpptoolkit::test::tool::TestFailException& ex) {
  std::cerr << "Function:\t" << RED_COLOR << ex.function() << CLEAR_COLOR
            << std::endl;
  std::cerr << "Why:\t\t" << RED_COLOR << ex.why() << CLEAR_COLOR << std::endl;
  std::cerr << "Where:\t\t" << RED_COLOR << ex.where() << CLEAR_COLOR
            << std::endl;
  std::cerr << std::endl;
}

int main() {
  cpptoolkit::test::Core* core = cpptoolkit::test::Core::instance();
  if (core == nullptr) {
    std::cerr << "Core is null";
  }

  try {
    cpptoolkit::test::TestsResult result = core->RunTests();
    if (result.success_tests == result.total_tests) {
      std::cout << GREEN_COLOR << "[" << result.success_tests << "] "
                << "All tests are passed!" << CLEAR_COLOR << std::endl;
      return 0;
    }

    for (auto it = result.fail_tests.begin(); it != result.fail_tests.end();
         it++) {
      PrintError(*it);
    }

  } catch (const std::runtime_error& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  } catch (...) {
    std::cerr << "Error on test";
  }
}

