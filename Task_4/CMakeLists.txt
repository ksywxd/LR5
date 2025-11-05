cmake_minimum_required(VERSION 4.0)
project(Task_4)

include_directories(include)

#основная программа
add_executable(Task_4
        src/Task_4.cpp
        src/testfunc.cpp)

#тесты
add_executable(Task_4_Tests
        tests/test.cpp
        src/testfunc.cpp
)

#заголовки
target_include_directories(Task_4_Tests PRIVATE Task_4/include)
target_link_libraries(Task_4_Tests gtest gtest_main)