#include <iostream>

void swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

void Print(int* ptr) {
  using namespace std;
  cout << *ptr << endl;
}

int main() {
  using namespace std;

  int x = 10;
  int& ref = x;
  int y = 30;
  ref = y;

  // int& ref = nullptr does not work

  cout << "x :" << x << endl;
  cout << "ref :" << ref << endl;
  cout << "&x :" << &x << endl;
  cout << "&ref :" << &ref << endl;

  return 0;
}
