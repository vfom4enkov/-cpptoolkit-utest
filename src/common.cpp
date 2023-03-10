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

#include <cpptoolkit/test/tool/common.h>

#include <sstream>
#include <string>

namespace cpptoolkit {
namespace test {
namespace tool {

namespace {
std::string format_string(std::string a, std::string b) {
  std::string str = "(";
  str += a;
  str += ") is not equal (";
  str += b;
  str += ")";
  return str;
}

}  // namespace

void ThrowTestFailException(std::string why, std::string file, uint32_t line) {
  std::string where = file + ":" + std::to_string(line);
  throw TestFailException(why.c_str(), where.c_str());
}

std::string FailDetails(std::string actual, std::string expected) {
  return format_string(actual, expected);
}

std::string FailDetails(int64_t actual, int64_t expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(uint64_t actual, uint64_t expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(int32_t actual, int32_t expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(uint32_t actual, uint32_t expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(int16_t actual, int16_t expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(uint16_t actual, uint16_t expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(double actual, double expected) {
    return format_string(std::to_string(actual), std::to_string(expected));
}

std::string FailDetails(char actual, char expected) {
return format_string(
      std::to_string(static_cast<unsigned>(actual)),
      std::to_string(static_cast<unsigned>(expected)));
}

}  // namespace tool
}  // namespace test
}  // namespace cpptoolkit
