cmake_minimum_required(VERSION 3.30)
project(VolLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
find_package(Python3 COMPONENTS Interpreter Development.Module Development.Embed REQUIRED)

# Fetch pybind11
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.13.6
)

# Fetch Boost
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)

# Fetch Eigen
FetchContent_Declare(
    Eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG        3.4.0
)

# Fetch googletest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)

# Include Python library in Boost build
set(BOOST_INCLUDE_LIBRARIES pfr)

# Build Boost as shared library (required for Python module)
set(BUILD_SHARED_LIBS ON)

FetchContent_MakeAvailable(Boost Eigen googletest pybind11)

# Cpp dependencies
add_library(Cpp_Dependencies INTERFACE)

target_link_libraries(Cpp_Dependencies
    INTERFACE
        Boost::pfr
        Eigen3::Eigen
        Python3::Python
)

add_subdirectory(VolLib_Cpp)