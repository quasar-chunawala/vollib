#include <print>
#include <iostream>

#include <Math/Points2D.h>
#include <Core/Enums.h>
#include <MarketObjects/Asset.h>

namespace vol{
    struct VolatilityCurve{

        VolatilityCurve() = default;
        VolatilityCurve(const VolatilityCurve& other) = default;
        
        Points2D m_curve;
        MoneynessConvention m_moneynessConvention;
        Asset m_asset;
    };
}