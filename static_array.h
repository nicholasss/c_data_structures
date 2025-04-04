#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <stdbool.h>
#include <stdlib.h>

typedef struct Array {
  int *data;
  size_t size;
  size_t capacity;
} Array;

Array *initArray(size_t capacity);
void freeArray(Array *arr);
void clearArray(Array *arr);

// functions to use as stack
bool appendArray(Array *arr, int number);
int popArray(Array *arr);

// getting and setting
bool setAtIndex(Array *arr, int index, int number);
int getAtIndex(Array *arr, int index);
int removeAtIndex(Array *arr, int index);

void dumpArray(Array *arr);

#endif // STATIC_ARRAY
