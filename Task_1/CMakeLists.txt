cmake_minimum_required(VERSION 4.0)
project(Task_1)

# Включаем директорию с заголовками
include_directories(include)

# Создаем статическую библиотеку
add_library(task1lib
        STATIC src/task1lib.cpp
)

# Создаем исполняемый файл для основной программы
add_executable(Task_1
        src/Task_1.cpp
        src/task1lib.cpp
)

# Связываем библиотеку с программой
target_link_libraries(Task_1
        task1lib
)

# Создаем исполняемый файл для тестов
add_executable(Task_1_Tests
        tests/tests.cpp
        src/task1lib.cpp
)

# Включаем директории для тестов
target_include_directories(Task_1_Tests
        PRIVATE include
)

# Подключаем Google Test к тестам
target_link_libraries(Task_1_Tests
        gtest
        gtest_main
)