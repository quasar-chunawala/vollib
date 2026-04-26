#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>


#include <Bindings/Math/Points2DPy.h>
#include <Bindings/Math/LinearInterpolator1DPy.h>

namespace py = pybind11;

PYBIND11_MODULE(volpy, m)
{
    m.doc() = "vollib Python bindings";

    // ── Submodules mirror your C++ namespace structure ─────────────────────
    auto math          = m.def_submodule("math",          "Mathematical primitives");

    // ── Register bindings into their submodule ─────────────────────────────
    bindPoints2D(math);
    bindLinearInterpolator1D(math);
}