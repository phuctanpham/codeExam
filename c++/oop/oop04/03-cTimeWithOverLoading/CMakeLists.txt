# name: Pham Tan Phuc
# id: 25730134
# dob: 240290
# class: IT002.F21.CN1.CNTT
cmake_minimum_required(VERSION 3.10)
project(cTimes)

set(CMAKE_CXX_STANDARD 17)

add_executable(time_app
    main.cpp
    cTime_constructor.cpp
    cTime_destructor.cpp
    cTime_normalize.cpp
    cTime_input.cpp
    cTime_output.cpp
    cTime_add.cpp
    cTime_subtract.cpp
    cTime_addTime.cpp
    cTime_increment.cpp
    cTime_decrement.cpp
    cTime_compare.cpp
    cTime_difference.cpp
    cTimes_constructor.cpp
    cTimes_destructor.cpp
    cTimes_assign.cpp
    cTimes_input.cpp
    cTimes_output.cpp
    cTimes_sum.cpp
    cTimes_max.cpp
    cTimes_min.cpp
    cTimes_sort.cpp
)
