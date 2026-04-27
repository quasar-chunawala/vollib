#include <Core/Enums.h>
#include <Math/Points2D.h>

namespace vol{
    struct ForwardCurve{
        double fdf(double t);
        Points2D m_forwardDiscountFactors;
    };
};