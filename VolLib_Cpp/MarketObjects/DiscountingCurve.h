#include <Core/Enums.h>
#include <Math/Points2D.h>

namespace vol{
    struct DiscountingCurve{
        double df(double t);
        Points2D m_discountFactors;
    };
};