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
  arr->data = calloc(capacity, sizeof(int));
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
  if (index > arr->capacity) {
    printf("Unable to set. Index is larger than array capacity of: %zu\n",
           arr->capacity);
    return false;
  }

  arr->data[index] = number;
  return true;
}

// will return null if the index is not valid
int getNumber(uArray *arr, int index) {
  // is the number larger than capacity or lower than 0?
  if (index > arr->capacity || index < 0) {
    return NULL;
  }

  return arr->data[index];
}

int main(int argc, char *argv[]) {
  printf("Testing uArray.\n");

  int capacity = 10;
  uArray *arr = initUArray(capacity);
  if (arr == NULL) {
    return EXIT_FAILURE;
  }

  return 0;
}
