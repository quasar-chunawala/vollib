#ifndef POINTS2D_H
#define POINTS2D_H


#include <vector>

#include <Math/LinearInterpolator1D.h>
#include <Math/CubicSplineInterpolator.h>

namespace vol{

    class Points2D{
        public:
        Points2D() = default;
        Points2D(const Points2D& other) = default;
        Points2D& operator=(const Points2D& other) = default;
        Points2D(Points2D&& other) = default;
        Points2D& operator=(Points2D&& other) = default;

        /**
         * @brief Construct a new Points2D object.
         * 
         * @param xvalues Nodes x[0], x[1], ..., x[N-1]
         * @param yvalues Function values y[0], y[1], ..., y[N-1]
         */
        Points2D(const std::vector<double>& xvalues, const std::vector<double>& yvalues);

        std::vector<double> getXValues();
        std::vector<double> getYValues();
        const std::vector<double> getXValues() const;
        const std::vector<double> getYValues() const;

        private:
        std::vector<double> m_xvalues;
        std::vector<double> m_yvalues;
    };
}

#endif