cmake_minimum_required(VERSION 2.8)
project(Eigen3)
# c++ 版本
set(CMAKE_CXX_STANDARD 14)
find_package(Eigen3 REQUIRED)
include_directories(${Eigen3_INCLUDE_DIR})
add_executable(Dense Dense.cpp)
add_executable(Eigen Eigen.cpp)
add_executable(Dot Dot.cpp)
add_executable(Multiply Multiply.cpp)
add_executable(Other Other.cpp)
add_executable(Demo1 Demo1.cpp)
add_executable(Demo2 Demo2.cpp)

# eigen库只有头文件没有链接库，不需要target_link_libraries命令

