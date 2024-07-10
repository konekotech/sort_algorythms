cmake_minimum_required(VERSION 3.22)
project(quick_sort C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./libs)

# Include the header files
include_directories(include)

# quick_sort library
add_library(quick_sort SHARED src/lib.c
        src/quick_sort.c
        include/quick_sort.h)

# Executable for testing
add_executable(test_program test/test.c
        src/quick_sort.c
        include/quick_sort.h)

# Link the library to the executable
target_link_libraries(test_program quick_sort)