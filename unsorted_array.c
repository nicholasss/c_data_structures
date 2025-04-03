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

  // set capacity to num
  arr->capacity = capacity;

  // set size to 0
  arr->size = 0;
  return arr;
}

// whether the function was successfull or not
bool setNumber(uArray *arr, int index, int number) {
  if ((size_t)index > arr->capacity) {
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
  if ((size_t)index > arr->capacity || index < 0) {
    return -1;
  }

  return arr->data[index];
}

void freeuArray(uArray *arr) {
  free(arr->data);
  free(arr);
}

int main(int argc, char *argv[]) {
  printf("Testing uArray.\n");

  int capacity = 10;
  uArray *arr = initUArray(capacity);
  if (arr == NULL) {
    return EXIT_FAILURE;
  }

  setNumber(arr, 0, 1);
  setNumber(arr, 1, 2);

  int two = getNumber(arr, 1);
  if (two == -1) {
    printf("Failure\n");
    return EXIT_FAILURE;
  }
  printf("number should be 2, is: %d\n", two);

  // freed
  freeuArray(arr);
  arr = NULL;

  return EXIT_SUCCESS;
}
