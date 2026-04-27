namespace vol{
    enum class OptionType{
        Call,
        put
    };

    enum class MoneynessConvention{
        Strike,
        Delta,
        LogMoneyness
    };

    enum class OptionQuoteConvention{
        Price,
        ImpliedVolatility
    };

    enum class Currency{
        USD,
        GBP
    };
}