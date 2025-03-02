cmake_minimum_required(VERSION 3.10)
project(TrianguloTest)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(test_triangulo tests/test_triangulo.cpp triangulo.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(test_triangulo GTest::GTest GTest::Main pthread)

add_test(NAME TrianguloTest COMMAND test_triangulo)
