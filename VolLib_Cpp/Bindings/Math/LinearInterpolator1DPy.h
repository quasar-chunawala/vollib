#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <Math/Points2D.h>
#include <Math/LinearInterpolator1D.h>

namespace py = pybind11;

void bindLinearInterpolator1D(py::module_& m);