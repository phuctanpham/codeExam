# name: Pham Tan Phuc
# id: 25730134
# dob: 240290
# class: IT002.F21.CN1.CNTT
cmake_minimum_required(VERSION 3.10)
project(cDates)

set(CMAKE_CXX_STANDARD 17)

add_executable(date_app
    main.cpp
    # --- Cac file cua lop cDate & cDates ---
    cDate_constructor.cpp
    cDate_destructor.cpp
    cDate_utils.cpp
    cDate_input.cpp
    cDate_output.cpp
    cDate_add.cpp
    cDate_subtract.cpp
    cDate_difference.cpp
    cDate_increment.cpp
    cDate_decrement.cpp
    cDate_compare.cpp
    cDate_weekday.cpp
    cDates_constructor.cpp
    cDates_destructor.cpp
    cDates_assign.cpp
    cDates_input.cpp
    cDates_output.cpp
    cDates_max.cpp
    cDates_min.cpp
    cDates_sort.cpp
    # --- Cac file cua lop cAccount ---
    cAccount_constructor.cpp
    cAccount_destructor.cpp
    cAccount_input.cpp
    cAccount_output.cpp
    cAccount_calculateInterest.cpp
)