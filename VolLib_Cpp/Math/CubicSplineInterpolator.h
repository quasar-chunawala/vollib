#ifndef CUBICSPLINEINTERPOLATOR_H
#define CUBICSPLINEINTERPOLATOR_H


#include <Eigen/Core>

#include <cmath>
#include <limits>
#include <vector>

#include <Math/Interpolator.h>
#include <Math/Points2D.h>
#include <Math/TridiagonalMatrixSolver.h>

namespace vol{

    enum class BoundLType{
        FirstDerivativeBoundaryCondition,
        SecondDerivativeBoundaryCondition,
    };

    enum class BoundRType{
        FirstDerivativeBoundaryCondition,
        SecondDerivativeBoundaryCondition,
    };

    using BoundaryConditions = std::pair<std::pair<BoundLType, double>, std::pair<BoundRType, double>>;
    inline constexpr BoundaryConditions naturalBoundaryConditions {
        { BoundLType::SecondDerivativeBoundaryCondition, 0.0 }, 
        { BoundRType::SecondDerivativeBoundaryCondition, 0.0 } };


    /**
     * @brief An implementation of the piecewise cubic spline algorithm.
     * @details Constructs a spline curve consisting of sub-curves S[0], S[1], ..., S[n]
     * passing through the points (x[0],y[0]), (x[1],y[1]), ..., (x[n], y[n])
     * subject to various boundary conditions.
     *
     * Reference : https://www.deriscope.com/docs/Hagan_West_curves_AMF.pdf
     */
    struct CubicSplineInterpolator : Interpolator<CubicSplineInterpolator>{ 

        CubicSplineInterpolator(
            Points2D data,
            BoundaryConditions boundaryConditions = naturalBoundaryConditions
        )
        : Interpolator<CubicSplineInterpolator>{ data }
        , m_boundaryConditions{ boundaryConditions }
        , a{}, b{}, c{}, d{}, h{}, r{}, A{}
        {
            if(boundaryConditions == naturalBoundaryConditions)
            {
                std::vector<double> xvalues = data.getXValues();    // a= x[0] < x[1] < ... < x[n] = b
                std::vector<double> yvalues = data.getYValues();    // y[0], y[1], ..., y[n]
                h = std::vector<double>(xvalues.size(), 0.0);

                for(auto i{0uz}; i < xvalues.size() - 1; ++i){
                    h[i] = xvalues[i + 1] - xvalues[i];
                }

                // Construct right hand size vector r
                r = Eigen::VectorXd(xvalues.size());

                for(auto i{0u}; i < xvalues.size(); ++i){
                    if(i == 0 || i == xvalues.size() - 1){
                        r(i) = 0.0;
                    }else{
                        r(i) = 3 / h[i] * (yvalues[i + 1] - yvalues[i]) - 3 / h[i - 1] * (yvalues[i] - yvalues[i - 1]);
                    }
                }

                // Construct the tridiagonal matrix A of dimensions (n+1) x (n+1)
                A = Eigen::MatrixXd::Zero(xvalues.size(), xvalues.size());
                for(auto i{0uz}; i < xvalues.size(); ++i){
                    if(i == 0 || i == xvalues.size() - 1)
                        A(i, i) = 1.0;
                    else{
                        A(i, i - 1) = h[i - 1];
                        A(i, i) = 2 * (h[i - 1] + h[i]);
                        A(i, i + 1) = h[i + 1];
                    }
                }

                TridiagonalMatrixSolver solver(A, r);
                c = solver.solve();

                // The coefficients of interest to us are c[1],...,c[n-1]. For, c[0] = c[n] = 0.

                // Construct the vector a, b, d
                b = std::vector<double>(xvalues.size() - 1, 0.0);
                d = std::vector<double>(xvalues.size() - 1, 0.0);
                a = std::vector<double>(xvalues.size() - 1, 0.0);

                for(auto i{0}; i < xvalues.size() - 1; ++i){
                    b[i] = 1 / h[i] * (yvalues[i + 1] - yvalues[i]) - h[i] / 3.0 * (2 * c(i) + c(i + 1));
                    d[i] = (c(i + 1) - c(i)) / (3.0 * h[i]);
                    a[i] = yvalues[i];
                }
            }
        }

        double operator()(double xnew){
            double result{0.0};
            if(m_boundaryConditions == naturalBoundaryConditions)
            {
                Points2D data = getData();
                const std::vector<double>& xValues = data.getXValues();
                const std::vector<double>& yValues = data.getYValues();
                auto it = std::lower_bound(xValues.begin(), xValues.end(), xnew);
                

                if(it == xValues.begin() || it == xValues.end())
                    result = std::numeric_limits<double>::quiet_NaN();
                else{
                    --it;
                    size_t i = std::distance(xValues.begin(), it);
                    result = a[i] + b[i] * (xnew - xValues[i]) + c(i) * pow((xnew - xValues[i]), 2)
                    + d[i] * pow((xnew - xValues[i]), 3);
                }
            }
            
            return result;
        }
        
        BoundaryConditions m_boundaryConditions{ naturalBoundaryConditions };
        Eigen::MatrixXd A;
        std::vector<double> a;
        std::vector<double> b;
        Eigen::VectorXd c;
        std::vector<double> d;
        std::vector<double> h;
        Eigen::VectorXd r;
    };
}

#endif
