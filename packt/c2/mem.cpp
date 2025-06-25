
#include <cstdlib>

void twoD() {
  int *p1 = new int[3];
  int *p2 = new int[3];

  int **pdata = new int *[2];

  pdata[0] = p1;
  pdata[1] = p2;

  // free in same order of alloc
  delete[] p1; /* delete []pData[0] */
  delete[] p2; /* delete []pData[1] */

  delete[] pdata;
}

int main(int argc, char *argv[]) {
  int *p = (int *)malloc(5 * sizeof(int));
  int *c = (int *)calloc(1, sizeof(int));

  int *x = new int;
  *x = 6;
  delete x;

  int *arr = new int[4]{1, 2, 3, 4};
  delete[] arr;

  return 0;
}
