cmake_minimum_required(VERSION 4.0)
project(Task_5)

include_directories(include)

#основная программа
add_executable(Task_5
        src/Task_5.cpp
        src/testfunc.cpp)

#тесты
add_executable(Task_5_Tests
        tests/test.cpp
        src/testfunc.cpp
)

#заголовки
target_include_directories(Task_5_Tests PRIVATE Task_5/include)
target_link_libraries(Task_5_Tests gtest gtest_main)