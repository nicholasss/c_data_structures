# cmake files start with required versions
cmake_minimum_required(VERSION 3.20...4.0)

# project 'statement' listing version and languages is nice here
project(Data_Structures
  VERSION 0.0.1
  LANGUAGES C)

# setting c language standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# setting debug option
set(CMAKE_BUILD_TYPE Debug)

# setting compiler flags
set(COMPILER_FLAGS
  -g
  -Wall
  -Wextra
  -Wconversion
  -Wdouble-promotion
  -Wno-unused-parameter
  -Wno-unused-function
  -Wno-sign-conversion
  -Wpedantic
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# libraries
add_library(StaticArray STATIC static_array.c static_array.h)

# add executable
add_executable(TestStaticArray test_static_array.c)

# set target and direct to link with libraries
target_link_libraries(TestStaticArray StaticArray)

# set compiler flags
target_compile_options(TestStaticArray PRIVATE ${COMPILER_FLAGS})
