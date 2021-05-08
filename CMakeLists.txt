cmake_minimum_required(VERSION 3.20)
project(TestHttpListener)
enable_testing()
#add_subdirectory(${GMOCK_ROOT})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include_directories(${GMOCK_ROOT}/include)
include_directories(${GMOCK_ROOT}/gtest/include)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(./src/Header)

set (CMAKE_CXX_STANDARD 11)
find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)

add_executable(TestHttpListener 
				src/Implement/UnitTestHttpListener.cpp
				src/Implement/HttpListener.cpp
				src/Header/HttpListener.h)
target_link_libraries(TestHttpListener pthread GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)