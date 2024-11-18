cmake_minimum_required(VERSION 3.10)
project(IHateGui)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include Snap7 header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link Snap7 library directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add the executable
add_executable(IHateGui source/main.cpp
        source/snap7.cpp)

# Link Snap7 and required system libraries
target_link_libraries(IHateGui snap7 ws2_32)
