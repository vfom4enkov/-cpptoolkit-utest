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

namespace {

enum class TestEnum {
  kValidData = 0,
  kInvalidData = 1,
};

} // namespace

TK_TEST_CASE(test_compare_two_numbers_fail) {
  int a = 5;
  int b = 6;
  TK_EQUAL(a, b);
}

TK_TEST_CASE(test_compare_two_doubles_fail) {
  double m = 16.005;
  double n = 16.0009;
  TK_EQUAL(m, n);
}

TK_TEST_CASE(test_compare_two_enums_fail) {
  TestEnum a = TestEnum::kInvalidData;
  TK_EQUAL(a, TestEnum::kValidData);
}

TK_TEST_CASE(test_compare_two_strings_fail) {
  std::string str_1 = "test string";
  std::string str_2 = "test string!";
  TK_EQUAL(str_1, str_2);
}

TK_TEST_CASE(test_bool_value_fail) {
  bool val = false;
  TK_CHECK(val);
}

TK_TEST_CASE(test_pointer_is_not_null_fail) {
  int *num = nullptr;
  TK_IS_NOT_NULL(num);
}

TK_TEST_CASE(test_pointer_in_null_fail) {
  int num = 0xffff;
  TK_IS_NULL(&num);
}

