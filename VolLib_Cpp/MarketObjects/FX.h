#include <string>
#include <optional>

#include <Core/Enums.h>
#include <MarketObjects/DiscountingCurve.h>

namespace vol{
    struct FX{
        Currency m_underlying;
        Currency m_accounting;
        double m_spotRate;
        DiscountingCurve m_underlyingDFCurve;
        DiscountingCurve m_accountingDFCurve;
    };
}