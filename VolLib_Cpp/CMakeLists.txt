cmake_minimum_required(VERSION 3.30)
project(VolLib)

# VolLib_Cpp library configuration
add_library(VolLib STATIC
    Math/Points2D.cpp
)

set_target_properties(VolLib PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Set include directories so headers can be found with <Math/Points2D.h>
target_include_directories(VolLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set library output name to vollib.so (lowercase, matching BOOST_PYTHON_MODULE name)
set_target_properties(VolLib PROPERTIES
    OUTPUT_NAME VolLib
    PREFIX ""
)

# Link external dependencies
target_link_libraries(VolLib PUBLIC Cpp_Dependencies)

# Separate shared library just for Python bindings
pybind11_add_module(volpy
    Bindings/Bindings.cpp
    Bindings/Math/Points2DPy.cpp
    Bindings/Math/LinearInterpolator1DPy.cpp
)

# Link 
target_link_libraries(volpy
    PRIVATE
        VolLib                   # link VolLib static library
)

target_include_directories(volpy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Bindings
)
