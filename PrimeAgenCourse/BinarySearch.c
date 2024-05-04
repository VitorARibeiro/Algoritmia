#include <stdio.h>

int BinarySearch(int *Array, int key, int Lo, int Hi) {

  int m = (Lo + Hi) / 2;

  int v = Array[m];

  if (Hi < Lo)
    return 0;
  if (v == key)
    return 1;
  else if (key > v)
    return BinarySearch(Array, key, m + 1, Hi);
  else
    return BinarySearch(Array, key, Lo, m - 1);

  return 0; // not found
}

int main() {

  int Array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = 5;

  if (BinarySearch(Array, key, 0, 9))
    printf("Encontrou");

  return 0;
}
