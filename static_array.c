#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "static_array.h"

Array *initArray(size_t capacity) {
  // initialize array object
  Array *arr = malloc(sizeof(Array));
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

void freeArray(Array *arr) {
  free(arr->data);
  free(arr);
}

bool appendArray(Array *arr, int number) {
  if (arr->size >= arr->capacity) {
    printf("Unable to append to full array.\n");
    return false;
  }

  int index = (int)arr->size;
  arr->data[index] = number;
  arr->size += 1;
  return true;
}

int popArray(Array *arr) {
  if (arr->size == 0) {
    printf("Unable to pop from empty array.\n");
    return -1;
  }

  int index = (int)arr->size - 1;
  int number = arr->data[index];

  arr->size -= 1;
  arr->data[index] = 0;
  return number;
}

// whether the function was successfull or not
// this function should be an internal function
bool setIndex(Array *arr, int index, int number) {
  if ((size_t)index > arr->capacity) {
    printf("Unable to set. Index is larger than array capacity of: %zu\n",
           arr->capacity);
    return false;
  }

  arr->data[index] = number;
  arr->size += 1;
  return true;
}

// will return null if the index is not valid
int getIndex(Array *arr, int index) {
  // is the number larger than capacity or lower than 0?
  if ((size_t)index > arr->capacity || index < 0) {
    return -1;
  }

  return arr->data[index];
}

void dumpArray(Array *arr) {
  for (int i = 0; i <= arr->capacity - 1; i++) {
    printf("index: %d -> %d\n", i, arr->data[i]);
  }
}
