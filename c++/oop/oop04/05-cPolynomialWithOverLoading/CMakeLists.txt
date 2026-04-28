# name: Pham Tan Phuc
# id: 25730134
# dob: 240290
# class: IT002.F21.CN1.CNTT
cmake_minimum_required(VERSION 3.10)
project(cPolynomials)

set(CMAKE_CXX_STANDARD 17)

add_executable(poly_app
    main.cpp
    # --- Cac file cua lop cPolynomial ---
    cPolynomial_constructor.cpp
    cPolynomial_destructor.cpp
    cPolynomial_assign.cpp
    cPolynomial_input.cpp
    cPolynomial_output.cpp
    cPolynomial_add.cpp
    cPolynomial_subtract.cpp
    cPolynomial_multiply.cpp
    cPolynomial_evaluate.cpp
    cPolynomial_compare.cpp
    # --- Cac file cua lop cPolynomials ---
    cPolynomials_constructor.cpp
    cPolynomials_destructor.cpp
    cPolynomials_assign.cpp
    cPolynomials_input.cpp
    cPolynomials_output.cpp
    cPolynomials_max.cpp
    cPolynomials_min.cpp
    cPolynomials_sort.cpp
)