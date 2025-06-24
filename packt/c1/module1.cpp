#include <limits.h>
#include <sys/types.h>

#include <climits>
#include <iostream>

int foo(int x) { return x++; }

int Factorial(int x) {
  int result = 1;
  for (int i = 0; i < x; ++i) {
    result *= i;
  }
  return result;
}

int main(int argc, char *argv[]) {
  std::cout << "sizes " << std::endl;
  std::cout << "sizes char " << sizeof(char) << std::endl;
  std::cout << "sizes uint " << sizeof(uint) << std::endl;
  std::cout << "sizes double " << std::endl;

  char buff[256];

  std::cin >> buff;
  // buff, number of char you want to read , and delimiter so cin to stop
  // reading
  std::cin.getline(buff, 64, '\n');

  // array
  int arr1[4];
  int arr2[4]{0, 1, 2, 3};
  arr1[0] = foo(3);

  // TODO

  char a1 = 'a';
  int *p1 = new int{};
  char *p2 = new char[8]{};  // defaults the values in the car
  // copy initialization

  return 0;
}

// function  <return type> <name> (<param>)
//  vexxing parses

/*
 *
 *
 *
 *
 *
 */
