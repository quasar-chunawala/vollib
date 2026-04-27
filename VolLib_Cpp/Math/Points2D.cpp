#include <stdexcept>
#include <vector>

#include <Math/Points2D.h>

namespace vol{
    Points2D::Points2D(const std::vector<double>& xvalues, const std::vector<double>& yvalues)
    : m_xvalues{ xvalues }
    , m_yvalues{ yvalues }
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

}