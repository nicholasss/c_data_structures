#include "unsorted_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // testing unsorted array with 10
  size_t capacity = (size_t)10;
  uArray *array = initUArray(capacity);

  // adding ten items
  for (int i = 0; i < 10; i++) {
    bool ok = appendUArray(array, i + 1);

    if (!ok) {
      printf("ERROR Unable to append to array.\n");
      return EXIT_FAILURE;
    }
  }

  // prints whole array
  dumpUArray(array);

  // removing ten items
  for (int i = 0; i < 10; i++) {
    int num = popUArray(array);
    printf("num popped: %d\n", num);
  }

  freeUArray(array);

  return EXIT_SUCCESS;
}
