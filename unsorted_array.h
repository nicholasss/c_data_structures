#ifndef UNSORTED_ARRAY
#define UNSORTED_ARRAY

#include <stdlib.h>

typedef struct uArray {
  int *data;
  size_t size;
  size_t capacity;
} uArray;

uArray *initUArray(size_t capacity);
void freeUArray(uArray *arr);

bool appendUArray(uArray *arr, int number);
int popUArray(uArray *arr);

bool setIndex(uArray *arr, int index, int number);
int getIndex(uArray *arr, int index);

#endif
