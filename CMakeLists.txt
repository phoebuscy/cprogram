cmake_minimum_required(VERSION 3.10)
project(cprogram)

set(CMAKE_CXX_STANDARD 11)

include_directories(common)
include_directories(main)
include_directories(multthread)
include_directories(smartptr)
include_directories(stl)

add_executable(cprogram
        common/commonfunc.cpp
        common/commonfunc.h
        main/maintest.cpp
        main/maintest.h
        multthread/mltthred.cpp
        multthread/mltthred.h
        smartptr/smartptr.h
        smartptr/smartptr.cpp
        stl/stl.cpp
        stl/stl.h)
