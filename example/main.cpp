#include <cpptoolkit/test/macros.h>
#include <cpptoolkit/test/core.h>
#include <cpptoolkit/test/tool/BaseFixture.h>
#include <cpptoolkit/test/tool/TestFailException.h>
#include <cpptoolkit/test/utest.h>

#include <cassert>
#include <cstdio>
#include <memory>

#define MCR(a)           \
  void a();              \
  class _a_a {           \
   public:               \
    void Exec() { a(); } \
  };                     \
  void a()

MCR(my_function) {
  std::cout << "Function: " << __func__ << std::endl;
  std::cout << "File: " << __FILE__ << std::endl;
  std::cout << "Line: " << __LINE__ << std::endl;
}

class Tester {
 public:
  Tester() { std::cout << "this is the Tester constructor" << std::endl; }
  void call() { std::cout << "Hello b!" << std::endl; };
} instnce;

void ThrowFunction() {
  throw cpptoolkit::test::tool::TestFailException("ThrowFunction", "just fail",
                                                  "main.cpp");
}

class MyFixture {
 public:
  MyFixture() { std::cout << "My fixture constructor" << std::endl; };
  ~MyFixture() { std::cout << "My fixture destructor!" << std::endl; };
  void RunTest() {std::cout << "MyFixture Run!" << std::endl;};
};

class CustomFixture : public cpptoolkit::test::tool::BaseFixture,
                      public MyFixture {
 public:
  CustomFixture() : MyFixture(){ std::cout << "CustomFixture constructor" << std::endl;};
  virtual ~CustomFixture() {std::cout << "CustomFixture destructor" << std::endl;};
  void RunTest() override {
    std::cout << "Run test function" << std::endl;
  };
};

std::shared_ptr<cpptoolkit::test::tool::BaseFixture> getFixture() {
  return std::shared_ptr<CustomFixture>(new CustomFixture());
}

int main() {
  cpptoolkit::test::Core *core = cpptoolkit::test::Core::instance();
  if (core == nullptr) {
    std::cerr << "Core is null";
  }

  try {
    cpptoolkit::test::TestsResult result = core->RunTests();
  }
  catch(...) {
    std::cerr << "Error on test";
  }

  // _a_a a;
  // a.Exec();

  // std::shared_ptr<cpptoolkit::test::tool::BaseFixture> fixture = getFixture();
  // fixture->RunTest();

  // try {
  //   ThrowFunction();
  // } catch (const cpptoolkit::test::tool::TestFailException &ex) {
  //   std::cout << "Function:\t" << ex.function() << std::endl;
  //   std::cout << "Why:\t\t" << ex.why() << std::endl;
  //   std::cout << "Where:\t\t" << ex.where() << std::endl;
  // }
}
