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

bool replaceAtIndexDArray(DArray *arr, int num, int index) {
  // check array
  if (arr == nil) {
    printf("[DArray Info] Unable to use nil DArray type.\n");
    return false;
  }

  // check for index within capacity
  if (index > (arr->capacity - 1)) {
    // increase capacity until index fits
    while (index > (arr->capacity - 1)) {
      arr = increaseDArrayCapacity(arr);
    }
  }

  // check for index within size, aka not further than known values
  if (index > (arr->size - 1)) {
    printf(
        "[DArray Info] Unable to set value %d where there is no set value.\n",
        num);
    return false;
  }

  // actually replace the number now
  arr->data[index] = num;
  return true;
}

// =================
// Subtractive Funcs
// =================

int popFromDarray(DArray *arr) {
  // check array
  if (arr == nil) {
    printf("[DArray Info] Unable to use nil DArray type.\n");
    return false;
  }

  // check size
  if (arr->size <= 0) {
    printf("[DArray Info] Unable to pop from empty array.\n");
    return nil;
  }

  // get element
  int popIndex = arr->size - 1;
  int popElement = arr->data[popIndex];

  // clear at index and adjust size
  arr->data[popIndex] = 0;
  arr->size--;

  return popElement;
}

int removeAtIndexDArray(DArray *arr, int index) {
  // check array
  if (arr == nil) {
    printf("[DArray Info] Unable to use nil DArray type.\n");
    return false;
  }

  // check if index is ok, aka not further than end of array nums
  if (index > (arr->size - 1)) {
    printf("[DArray Info] Unable to remove element from invalid index.\n");
    return false;
  }

  // get element
  int popElement = arr->data[index];

  // TODO: check this speciifc section for correctness
  // shift remaining elements over
  int shiftStartingAtIndex = index + 1;
  for (int i = shiftStartingAtIndex; i < (arr->size - 1); i++) {
    arr->data[i] = arr->data[i + 1];
  }

  // set last element to 0
  arr->data[arr->size] = 0;
  arr->size--;

  return popElement;
}
