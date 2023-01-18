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
Include the header to .cpp file:
```
#include <cpptoolkit/test/header.h>
```
Add unit test functions:
* **TK_TEST_CASE(test_method)**
* **TK_FIXTURE_TEST_CASE(test_method_with_fixture, Fixture)**

Where _Fixture_ - custom class

Check results of the unit tests:
* **TK_CHECK(val)** // val - bool value or expression
* **TK_EQUAL(expected, actual)** // expected == actual
* **TK_IS_NULL(ptr)** // ptr == nullptr
* **TK_IS_NOT_NULL(ptr)** // ptr != nullptr

For example:
```cpp
#include <cpptoolkit/test/header.h>

TK_TEST_CASE(test_compare_two_numbers) {
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
#include <cpptoolkit/test/run_all_macros.h>

TK_GET_READY_FOR_TESTS

int main() {
  Run();
}
```

## Step 4 - Check **example** folder for more details
View examples to get more info aboud test with fixture or get statistic about test execution
