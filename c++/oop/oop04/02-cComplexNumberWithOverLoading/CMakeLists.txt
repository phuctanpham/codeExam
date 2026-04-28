# name: Pham Tan Phuc
# id: 25730134
# dob: 240290
# class: IT002.F21.CN1.CNTT
cmake_minimum_required(VERSION 3.10)
project(cComplexes)

set(CMAKE_CXX_STANDARD 17)

add_executable(complex_app
    main.cpp
    cComplex_constructor.cpp
    cComplex_destructor.cpp
    cComplex_modulus.cpp
    cComplex_input.cpp
    cComplex_output.cpp
    cComplex_add.cpp
    cComplex_subtract.cpp
    cComplex_multiply.cpp
    cComplex_divide.cpp
    cComplex_compare.cpp
    cComplexes_constructor.cpp
    cComplexes_destructor.cpp
    cComplexes_assign.cpp
    cComplexes_input.cpp
    cComplexes_output.cpp
    cComplexes_sum.cpp
    cComplexes_max.cpp
    cComplexes_min.cpp
    cComplexes_sort.cpp
)