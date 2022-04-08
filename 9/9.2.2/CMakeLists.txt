# cmake所需的最低版本
cmake_minimum_required(VERSION 3.13)
# naming项目
project(9.2.2)
set(CMAKE_C_STANDARD 11)
# 添加从hello.c编译的可执行文件
add_executable(main main.c)