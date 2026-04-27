#include <string>
#include <optional>

#include <Core/Enums.h>
#include <MarketObjects/ForwardCurve.h>
#include <MarketObjects/DividendCurve.h>

namespace vol{
    struct Asset{
        std::string m_name;
        double m_spotPrice;
        ForwardCurve m_forwardCurve;
        DividendCurve m_dividendCurve;
    };
}