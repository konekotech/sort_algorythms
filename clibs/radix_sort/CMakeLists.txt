cmake_minimum_required(VERSION 3.22)
project(radix_sort C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./libs)

# Include the header files
include_directories(include)

# Optimization flags for release builds
set(CMAKE_C_FLAGS_RELEASE "-O3")

# radix_sort library
add_library(radix_sort SHARED src/lib.c
        src/radix_sort.c
        include/radix_sort.h)

# Executable for testing
add_executable(test_program test/test.c
        src/radix_sort.c
        include/radix_sort.h)

# Link the library to the executable
target_link_libraries(test_program radix_sort)