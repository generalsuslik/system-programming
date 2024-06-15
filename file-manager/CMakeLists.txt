cmake_minimum_required(VERSION 3.13)
project(file-manager)
set(CMAKE_C_STANDARD 11)

set(PROJECT_NAME file-manager)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} ncurses)
