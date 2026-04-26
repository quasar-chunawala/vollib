#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <Math/Points2D.h>
namespace py = pybind11;

void bindPoints2D(py::module_& m);