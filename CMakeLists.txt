cmake_minimum_required(VERSION 3.10)
project(modern-c++)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILE modern-c++/factory.cpp modern-c++/singleton.cpp modern-c++/singleton.h modern-c++/bridge.h modern-c++/Observer.cpp modern-c++/Observer.h)
add_executable(modern-c++ ${SOURCE_FILE})

