cmake_minimum_required(VERSION 3.30)
project(VolLib)
# VolLib_Cpp library configuration

add_library(VolLib
    Math/Points2D.cpp
    Math/LinearInterpolator1D.cpp
)

# Set include directories so headers can be found with <Math/Points2D.h>
target_include_directories(VolLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
