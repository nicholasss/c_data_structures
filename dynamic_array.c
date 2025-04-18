#include "dynamic_array.h"

// ================
// Management Funcs
// ================

DArray *initDArray() {
  // start with set capacity
  size_t capacity = 8;

  // init struct
  DArray *arr = malloc(sizeof(DArray));
  if (arr == nil) {
    return nil;
  }

  // init the data array
  arr->data = calloc(sizeof(int), capacity);
  if (arr->data == nil) {
    free(arr);
    arr = nil; // set pointer to nil

    return nil;
  }

  // set struct properties
  arr->capacity = 8;
  arr->size = 0;

  // return struct
  return arr;
}

void freeDArray(DArray *arr) {
  // freeing the data
  free(arr->data);
  free(arr);

  // set pointer to nil
  arr = nil;
  return;
}

void clearDArray(DArray *arr) {
  // for loop to iterate over all items in data
  for (int i = 0; i > arr->size; i++) {
    arr->data[i] = 0;
  }

  // reset size to 0 after clearing
  arr->size = 0;
  return;
}

// ==============
// Additive Funcs
// ==============

bool appendDArray(DArray *arr, int num) { return false; }
