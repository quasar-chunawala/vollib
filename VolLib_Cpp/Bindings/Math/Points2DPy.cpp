#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <Math/Points2D.h>
namespace py = pybind11;

void bindPoints2D(py::module_& m)
{
    m.doc() = "volpy Python bindings";

    py::class_<vol::Points2D>(m, "Points2D")

          // Constructors
          .def(py::init<>())
          .def(py::init<const std::vector<double>&, const std::vector<double>&>(),
               py::arg("xvalues"),
               py::arg("yvalues"))

          // Getters — expose the const overloads
          .def("getXValues",
               static_cast<const std::vector<double>(vol::Points2D::*)() const>(
                    &vol::Points2D::getXValues))
          .def("getYValues",
               static_cast<const std::vector<double>(vol::Points2D::*)() const>(
                    &vol::Points2D::getYValues))

          // Interpolator
          .def("setInterpolator",
               &vol::Points2D::setInterpolator,
               py::arg("interpolator"))
          .def("tryGetInterpolator",
               &vol::Points2D::tryGetInterpolator)
          .def("getInterpolator",
               &vol::Points2D::getInterpolator)
          .def("interpolate", 
               &vol::Points2D::interpolate, 
               py::arg("xnew"))
          
          // Dunder reprs for convenience
          .def("__repr__", [](const vol::Points2D& p){
               return "<Points2D with " +
                    std::to_string(p.getXValues().size()) +
                    " points>";
          });
}