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

#include <cpptoolkit/test/core.h>

namespace cpptoolkit {
namespace test {

Core *Core::instance_ = nullptr;

Core *Core::instance() {
  if (instance_ == nullptr) {
    instance_ = new Core();
  }
  return instance_;
}

void Core::Add(cpptoolkit::test::tool::BaseFixture *fixture) {
  test_list_.push_back(fixture);
}

uint32_t Core::count() { return test_list_.size(); }

void Core::RunTests(Observer *observer) {
  for (uint32_t i = 0; i < test_list_.size(); i++) {
    cpptoolkit::test::tool::BaseFixture *fixture = test_list_[i];
    TestResult result;
    result.name = fixture->name();
    try {
      fixture->Test();
      result.is_success = true;
    } catch (const cpptoolkit::test::tool::TestFailException &ex) {
      result.is_success = false;
      result.where = ex.where();
      result.why = ex.why();
    }

    if (observer != nullptr) {
      observer->Test(result);
    }
  }
}

}  // namespace test
}  // namespace cpptoolkit
