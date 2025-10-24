cmake_minimum_required(VERSION 4.0)
project(Task_1)

include_directories(include)

# Создаем статическую библиотеку
add_library(task1lib STATIC src/task1lib.cpp)

# Создаем исполняемый файл
add_executable(Task_1
        src/Task_1.cpp)

# Связываем библиотеку с программой
target_link_libraries(Task_1 task1lib)