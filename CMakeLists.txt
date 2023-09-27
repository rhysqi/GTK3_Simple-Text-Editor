# CMake setup configuration
cmake_minimum_required(VERSION 3.2)
project("Simple Text Editor" VERSION 1.0)

# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler arguments
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-strong -flto -H -v")

# Libraries Options
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Adding Executable
add_executable(Program src/SAP.cc)

# Linking libraries
target_link_libraries(Program ${GTK3_LIBRARIES})
