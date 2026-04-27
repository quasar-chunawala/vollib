#ifndef LINEARINTERPOLATOR1D_H
#define LINEARINTERPOLATOR1D_H

#include <Math/Interpolator.h>
#include <Math/Points2D.h>

namespace vol{

    struct LinearInterpolator1D : Interpolator<LinearInterpolator1D>{ 
    
        LinearInterpolator1D(Points2D data) : Interpolator<LinearInterpolator1D> { data }{}

        double operator()(double xnew)
        {
            double result{0.0};
            Points2D data = getData();
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
                double t = (xnew - xValues[i]) / (xValues[i+1] - xValues[i]);
                result = (1 - t) * yValues[i] + t * yValues[i + 1];
            }
            return result;
        }
        
    };
    
}
#endif