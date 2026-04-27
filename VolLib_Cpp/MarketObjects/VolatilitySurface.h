#include <print>
#include <iostream>
#include <vector>

#include <Math/Points2D.h>
#include <Core/Enums.h>
#include <MarketObjects/Asset.h>
#include <MarketObjects/VolatilityCurve.h>

namespace vol{
    struct VolatilitySurface{

        VolatilitySurface() = default;
        VolatilitySurface(const VolatilitySurface& other) = default;
        
        std::vector<VolatilityCurve> m_volatilityCurves;
        std::vector<double> maturities;
        Asset m_asset;
    };
}