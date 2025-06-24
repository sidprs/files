#include <iostream>

using namespace std;

int main() {
  int *p1, *p2, p3;

  int x = 10;
  cout << &x << endl;
  // & is the address of the variable
  int *ptr = &x;

  cout << *ptr << endl;
  cout << ptr << endl;

  void *ptr2 = &x;

  int z = 10;
  int *val = &z;
  *val = 3;

  cout << "z " << z << endl;

  int *ptrz = nullptr;

  *ptrz = 10;  // error;
               // function ptr

  //----------------
  //
  // reference does not take memory
  //

  int refrent = 10;
  int &reference = refrent;

  return 0;
}
