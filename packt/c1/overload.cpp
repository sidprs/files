#include <iostream>

using namespace std;

#define Square(x) x* x

namespace a {

void a() { std::cout << "a" << std::endl; }
namespace b {

void b() { std::cout << "b" << std::endl; }

}  // namespace b

}  // namespace a

void add(int a, int b) {
  using namespace std;
  cout << a + b << endl;
}
void CreateWindow(const char* title, int x = -1, int y = -1, int width = -1,
                  int height = -1) {
  using namespace std;
  cout << title << endl;
  cout << x << endl;
  cout << y << endl;
  cout << width << endl;
  cout << height << endl;
}

int main() {
  CreateWindow("Notepad", 100, 200);
  void (*pfn)(int, int) = &add;  // & is optional
  (*pfn)(4, 3);

  using namespace a::b;
  a::b::b();

  return 0;
}
