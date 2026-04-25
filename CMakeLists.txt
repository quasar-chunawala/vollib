cmake_minimum_required(VERSION 3.30)
project(VolLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Add subdirectories
add_subdirectory(VolLib_Cpp)