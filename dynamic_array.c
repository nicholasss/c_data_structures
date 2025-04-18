#include "dynamic_array.h"

// ================
// Management Funcs
// ================

DArray *initDArray() {
  // init struct
  DArray *arr = malloc(sizeof(DArray));
  if (arr == nil) {
    return nil;
  }

  // init the data array
  arr->data = calloc(sizeof(int), initialCapacity);
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

DArray *increaseDArrayCapacity(DArray *arr) {
  // assumes capcity check before calling

  if (arr->data == nil) {
    // failed with nil pointer
    return false;
  }

  // extend capacity of array before adding
  size_t newCapacity = arr->capacity * capacityMultiplier;

  // setting new values
  arr->data = realloc(arr->data, newCapacity);
  arr->capacity = newCapacity;

  return arr;
}

// ==============
// Additive Funcs
// ==============

bool appendDArray(DArray *arr, int num) {
  // check size and capacity
  if (arr->size >= arr->capacity) {
    arr = increaseDArrayCapacity(arr);
  }

  // append the new num
  int i = arr->capacity;
  arr->data[i] = num;

  // increase arr size counter
  arr->size++;

  return false;
}
