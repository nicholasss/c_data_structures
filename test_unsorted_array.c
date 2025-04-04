#include "unsorted_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  size_t capacity = (size_t)10;
  uArray *array = initUArray(capacity);

  bool success = appendUArray(array, 1);
  if (!success) {
    printf("failure.\n");
  } else {
    printf("appended successfuly.\n");
  }

  dumpUArray(array);

  int num = popUArray(array);

  freeUArray(array);

  return EXIT_SUCCESS;
}
