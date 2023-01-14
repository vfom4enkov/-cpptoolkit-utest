#include <cpptoolkit/utest/utest.h>
#include <cpptoolkit/utest/macros.h>
#include <cassert>

#define MCR(a)    \
void a();         \
class _a_a {      \
  public:         \
    void Exec() { \
      a();        \
    }             \
};                \
void a()

MCR(my_function) {
  std::cout << "Function: " << __func__ << std::endl;
  std::cout << "File: " << __FILE__ << std::endl;
  std::cout << "Line: " << __LINE__ << std::endl;
}

int main() {
  _a_a item;
  item.Exec();
}

