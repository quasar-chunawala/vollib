#ifndef POINTS3D_H
#define POINTS3D_H


#include <vector>

#include <Math/LinearInterpolator1D.h>
#include <Math/CubicSplineInterpolator.h>

namespace vol{

    class Points3D{
        public:
        Points3D() = default;
        Points3D(const Points3D& other) = default;
        Points3D& operator=(const Points3D& other) = default;
        Points3D(Points3D&& other) = default;
        Points3D& operator=(Points3D&& other) = default;

        /**
         * @brief Construct a new Points3D object.
         * 
         */
        Points3D(const std::vector<double>& xvalues, const std::vector<double>& yvalues, const std::vector<double>& zvalues);

        std::vector<double> getXValues();
        std::vector<double> getYValues();
        std::vector<double> getZValues();
        const std::vector<double> getXValues() const;
        const std::vector<double> getYValues() const;
        const std::vector<double> getZValues() const;

        private:
        std::vector<double> m_xvalues;
        std::vector<double> m_yvalues;
        std::vector<double> m_zvalues;
    };
}

#endif