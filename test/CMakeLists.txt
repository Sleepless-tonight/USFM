# cmake所需的最低版本
cmake_minimum_required(VERSION 3.13)
# naming项目
project(test)

# 指定编译器
# CMAKE_C_FLAGS_DEBUG            ----  C 编译器
# CMAKE_CXX_FLAGS_DEBUG        ----  C++ 编译器
# -g：只是编译器，在编译的时候，产生调试信息。
# -Wall：生成所有警告信息。一下是具体的选项，可以单独使用
set(CMAKE_C_STANDARD 11)

# 使用包PkgConfig检测GTK +头文件/库文件
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
# 配置加载native依赖
# CMake使用GTK +，告诉编译器在哪里查找头文件
# 和链接器在哪里查找库文件
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# 将其他标志添加到编译器
add_definitions(${GTK3_CFLAGS_OTHER})

# 添加从hello.c编译的可执行文件
add_executable(test main.c)

# 链接库
target_link_libraries(test ${GTK3_LIBRARIES})
