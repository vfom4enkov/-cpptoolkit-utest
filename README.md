# C++ test
Unit test tool for C++ projects

## Step 1 - Add the tests to your project
Dowload (or clone) the tool and add the lines to your CMakeLists.txt:
```
add_subdirectory("{path_to_cpptoolkit-test}")
...
target_link_libraries({your-project-name} cpptoolkit-test)
```

## Step 2 - Create unit tests
Include the header to _test_.cpp file:
```
#include <cpptoolkit/test/header.h>
```
Add unit test functions:
* **TK_TEST_CASE(test_method)**
* **TK_FIXTURE_TEST_CASE(test_method_with_fixture, Fixture)**

Where _Fixture_ - custom class

Check results of the unit tests:
* **TK_CHECK(val)** // val - bool value or expression
* **TK_EQUAL_STR(expected, actual)** // expected == actual for strings
* **TK_EQUAL_VAL(expected, actual)** // expected == actual for base types (int, char, double ...)
* **TK_EQUAL(expected, actual)** // expected == actual for other types
* **TK_IS_NULL(ptr)** // ptr == nullptr
* **TK_IS_NOT_NULL(ptr)** // ptr != nullptr

For example:
```cpp
#include <cpptoolkit/test/header.h>

TK_TEST_CASE(test_compare_sum_of_two_numbers) {
  // arrange
  int a = 3;
  int b = 7;

  // act
  int actual = a + b;

  // assert
  TK_EQUAL(10, actual);
}
```

## Step 3 - Run unit test
The simplest way to run unit tests and print result to command line, is - add these lines to your main.cpp file:
```cpp
#include <cpptoolkit/test/header.h>

#include <iostream>

int main() {
  auto* core = cpptoolkit::test::Core::instance();
  auto tests = core->RunTests();
  for (const auto& test : tests) {
    std::cout << test.name << "\t" << (test.is_success ? "OK" : "FAILED")
              << std::endl;
    if (!test.is_success) {
      std::cout << "Where: " << test.where << std::endl;
      std::cout << "Why: " << test.why << std::endl;
    }
  }
}
```

## Step 4 - Check **example** folder for more details
View examples to get more info aboud test with fixture or get statistic about test execution

