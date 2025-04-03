#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct uArray {
  int *data;
  size_t size;
  size_t capacity;
} uArray;

uArray *initUArray(size_t capacity) {
  // initialize array object
  uArray *arr = malloc(sizeof(uArray));
  if (arr == NULL) {
    return NULL;
  }

  // initilize data with capacity
  arr->data = malloc(sizeof(int) * capacity);
  if (arr->data == NULL) {
    free(arr);
    return NULL;
  }

  // set size to 0
  arr->size = 0;
  return arr;
}

// whether the function was successfull or not
bool setNumber(uArray *arr, int index, int number) {
  if (index - 1 > arr->capacity) {
    printf("Unable to set. Index is larger than array capacity of: %zu\n",
           arr->capacity);
    return false;
  }
}

int main(int argc, char *argv[]) {
  printf("Testing uArray.\n");

  int capacity = 10;
  uArray *arr = initUArray(capacity);
  if (arr == NULL) {
    return 1;
  }

  return 0;
}
