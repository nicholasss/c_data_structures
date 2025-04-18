#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// library definitions
#define nil NULL

#define initialCapacity 8
#define capacityMultiplier 2

// ================
// Data Struct Type
// ================

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} DArray;

// ================
// Management Funcs
// ================

// creates a dynamic array
DArray *initDArray();

// free the array
void freeDArray(DArray *arr);

// clear the array for reuse
void clearDArray(DArray *arr);

// increases the capacity of the array
DArray *increaseDArrayCapacity(DArray *arr);

// ==============
// Additive Funcs
// ==============

// appending to the array
bool appendDArray(DArray *arr, int num);

// replace item in array
bool replaceAtIndexDArray(DArray *arr, int num, int index);

// =================
// Subtractive Funcs
// =================

// pop from last index
int popFromDArray(DArray *arr);

// pops from specific index, shifts elements
int removeAtIndexDArray(DArray *arr, int index);

// ============
// Access Funcs
// ============

// peeks at element at index, does not remove
int peekAtIndexDArray(DArray *arr, int index);

// dump all contents of array to console
void dumpDArray(DArray *arr);

#endif // DYNAMIC_ARRAY
