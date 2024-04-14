cmake_minimum_required(VERSION 3.26)
set(TARGET_NAME SemestralnyProject)
project(${TARGET_NAME})

project(SemestralnyProject)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        User.h
        User.cpp
        Ride.h
        Ride.cpp
        Vehicle.h
        Vehicle.cpp
        Review.h
        Review.cpp
        Manager.h
        Manager.cpp
)

set(TEST_FILES
        testyUser.cpp
)

set(GTEST_SOURCE_FILES
        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

add_library(tests OBJECT ${TEST_FILES})
add_library(gtest OBJECT ${GTEST_SOURCE_FILES})

find_package(Threads REQUIRED)

include_directories(GoogleTest)
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${TEST_FILES} ${GTEST_SOURCE_FILES})
target_link_libraries(${TARGET_NAME} ${CMAKE_THREAD_LIBS_INIT})

