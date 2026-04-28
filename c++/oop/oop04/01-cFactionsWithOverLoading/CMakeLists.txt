# name: Pham Tan Phuc
# id: 25730134
# dob: 240290
# class: IT002.F21.CN1.CNTT
cmake_minimum_required(VERSION 3.10)
project(cFraction)

set(CMAKE_CXX_STANDARD 17)

add_executable(fraction_app
    main.cpp
    cFraction_constructor.cpp
    cFraction_destructor.cpp
    cFraction_simplify.cpp
    cFraction_input.cpp
    cFraction_output.cpp
    cFraction_add.cpp
    cFraction_subtract.cpp
    cFraction_multiply.cpp
    cFraction_divide.cpp
    cFraction_compare.cpp
    cFractions_constructor.cpp
    cFractions_destructor.cpp
    cFractions_input.cpp
    cFractions_output.cpp
    cFractions_sum.cpp
    cFractions_max.cpp
    cFractions_min.cpp
    cFractions_sort.cpp
)
