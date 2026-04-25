#include <functional>

#include "Points2D.h"

std::function<double(const Points2D&, double)> linearInterpolator1D = [](
    const Points2D& data,
    double xnew
)->double{
    double result{0.0};
    const std::vector<double>& xValues = data.getXValues();
    const std::vector<double>& yValues = data.getYValues();
    auto it = std::lower_bound(xValues.begin(), xValues.end(), xnew);
    if(it == xValues.begin()){
        // extrapolate
        result = yValues[0];
    }else if(it == xValues.end()){
        result = yValues[yValues.size() - 1];
    }else{
        --it;
        size_t i = std::distance(xValues.begin(), it);
        int t = (xnew - xValues[i]) / (xValues[i+1] - xValues[i]);
        result = (1 - t) * yValues[i] + t * yValues[i + 1];
    }
    return result;
};