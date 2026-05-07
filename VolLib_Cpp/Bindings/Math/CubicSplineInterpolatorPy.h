#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <Math/Points2D.h>
#include <Math/CubicSplineInterpolator.h>

namespace py = pybind11;

void bindCubicSplineInterpolator(py::module_& m);