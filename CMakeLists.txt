# cmake files start with required versions
cmake_minimum_required(VERSION 3.20...4.0)

# project 'statement' listing version and languages is nice here
project(DS
  VERSION 0.0.1
  LANGUAGES C)

# setting c language standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# libraries
add_library(UnsortedArray STATIC unsorted_array.c unsorted_array.h)

# add executable
add_executable(TestUnsortedArray test_unsorted_array.c)

# set target and direct to link with libraries
target_link_libraries(TestUnsortedArray UnsortedArray)

# set compiler flags
target_compile_options(TestUnsortedArray PRIVATE
  -g3 -Wall -Wextra -Wconversion -Wdouble-promotion
  -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion)
