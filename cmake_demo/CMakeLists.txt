cmake_minimum_required(VERSION 3.10)
project(SystemEngine VERSION 1.0)

# Specify modern C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake where to look for header files
include_directories(include)

# Create a static library from our modern C++ logic file
add_library(MathLogic src/logic.cpp)

# Create the final executable from your CP template
add_executable(a.out src/main.cpp)

# Link the modern library into the CP executable
target_link_libraries(a.out MathLogic)
