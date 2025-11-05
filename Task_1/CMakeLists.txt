cmake_minimum_required(VERSION 4.0)
project(Task_1)

include_directories(include)

#основная программа
add_executable(Task_1
        src/Task_1.cpp
        src/task1lib.cpp)

#тесты
add_executable(Task_1_Tests
        tests/test.cpp
        src/task1lib.cpp
)

#заголовки
target_include_directories(Task_1_Tests PRIVATE Task_1/include)
target_link_libraries(Task_1_Tests gtest gtest_main)