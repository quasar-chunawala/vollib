#include <print>
#include <format>
#include <iostream>

#include <Math/Points3D.h>
#include <Core/Enums.h>
#include <MarketObjects/FX.h>

namespace vol{
    struct FXOptionQuotes{
        // (Price, StrikeConvention, Maturity) cube
        Points3D m_marketQuotes;
        std::vector<MoneynessConvention> m_moneynessConventions;
        std::vector<OptionQuoteConvention> m_optionQuoteConventions;
        std::vector<OptionType> m_optionTypes;
        FX m_fxPair;
    };
}