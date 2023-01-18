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

std::string PrintTestResult(bool result) {
  std::string r("");
  if (result) {
    r += GREEN_COLOR;
    r += "ok";
  } else {
    r += RED_COLOR;
    r += "FAILED";
  }
  r += CLEAR_COLOR;
  return r;
}

class MainObserver : public cpptoolkit::test::Observer {
 public:
  MainObserver() : success_(0), failed_(0){};
  virtual ~MainObserver(){};
  void Test(cpptoolkit::test::TestResult& result) override {
    std::cout << "test " << result.name << " ... "
              << PrintTestResult(result.is_success) << std::endl;
    if (result.is_success) {
      success_++;
    } else {
      std::cout << "\twhy:\t" << result.why << std::endl;
      std::cout << "\twhere:\t" << result.where << std::endl;
      std::cout << std::endl;
      failed_++;
    }
  };
  uint32_t success() { return success_; };
  uint32_t failed() { return failed_; };

 private:
  uint32_t success_;
  uint32_t failed_;
};

int main() {
  cpptoolkit::test::Core* core = cpptoolkit::test::Core::instance();
  if (core == nullptr) {
    std::cerr << "Core is null" << std::endl;
  }

  MainObserver observer;
  try {
    uint32_t test_count = core->count();
    if (test_count == 1) {
      std::cout << "running 1 test" << std::endl;
    } else {
      std::cout << "running " << test_count << " tests" << std::endl;
    }

    core->RunTests(&observer);
    std::cout << std::endl;
    std::cout << "test result: " << observer.success() << " passed; "
              << observer.failed() << " failed;" << std::endl;
    std::cout << std::endl;
  } catch (const std::runtime_error& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  } catch (...) {
    std::cerr << "Error on test" << std::endl;
  }
}

