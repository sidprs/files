#include <iostream>

void Print(int *ptr) {
  using namespace std;
  cout << *ptr << endl;
  *ptr = 3400;
}

int main() {
  using namespace std;
  const float PI = 3.14159f;
  int arr[] = {1, 2, 3, 4};

  int *beg = std::begin(arr);
  int *end = std::end(arr);

  while (beg != end) {
    std::cout << *beg << " ";
    ++beg;
  }
  int x = 0;
  // Print(&x);
  cout << "main -> x " << x << endl;

  return 0;
}
