cmake_minimum_required(VERSION 3.19)
project(parallel_cmp_c C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
set(CMAKE_C_COMPILER /usr/local/bin/gcc-10)

add_executable(histogram-serial histogram-serial.c)
add_executable(histogram-parallel histogram-parallel.c)
add_executable(random-num random-num.c)

#add_executable(quicksort-serial quicksort-serial.c)
#add_executable(quicksort-parallel quicksort-parallel.c)
#
#add_executable(matmul-serial matmul-serial.c)
#add_executable(matmul-parallel matmul-parallel.c)
#add_executable(random-mat random-mat.c)