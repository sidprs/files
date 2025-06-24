#include <iostream>

int main() {
  using namespace std;

  int x = 10;
  int &ref = x;
  int y = 30;
  ref = y;

  // int& ref = nullptr does not work

  cout << "x :" << x << endl;
  cout << "ref :" << ref << endl;
  cout << "&x :" << &x << endl;
  cout << "&ref :" << &ref << endl;

  return 0;
}
