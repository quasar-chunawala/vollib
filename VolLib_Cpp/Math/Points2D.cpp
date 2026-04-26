#include <stdexcept>
#include <vector>

#include <Math/Points2D.h>

namespace vol{
    Points2D::Points2D(const std::vector<double>& xvalues, const std::vector<double>& yvalues)
    : m_xvalues{ xvalues }
    , m_yvalues{ yvalues }
    , m_interpolator{}
    {}

    std::vector<double> Points2D::getXValues(){
        return m_xvalues;
    }

    std::vector<double> Points2D::getYValues(){
        return m_yvalues;
    }

    const std::vector<double> Points2D::getXValues() const{
        return m_xvalues;
    }

    const std::vector<double> Points2D::getYValues() const{
        return m_yvalues;
    }

    void Points2D::setInterpolator(const std::function<double(const Points2D&, double)>& interpolator){
        m_interpolator = interpolator;
    }

    std::optional<std::function<double(const Points2D&, double)>> Points2D::tryGetInterpolator(){
        return m_interpolator;
    }

    std::function<double(const Points2D&, double)> Points2D::getInterpolator(){
        if(m_interpolator.has_value())
            return *m_interpolator;

        throw std::logic_error("Interpolator not found!");
    }

    double Points2D::interpolate(double xnew){
        auto interpolator = getInterpolator();
        return interpolator(*this, xnew);
    }
}