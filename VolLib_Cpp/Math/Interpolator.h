#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include <Math/Points2D.h>


namespace vol{
    template<typename Derived>
    class Interpolator{
        public:
        Interpolator() = default;
        Interpolator(const Interpolator&) = default;
        Interpolator& operator=(const Interpolator&) = default;

        Interpolator(Points2D data) : m_data( data ) {}
        Points2D getData(){ return m_data; }
        double operator()(double xnew){
            return (*static_cast<Derived*>(this))(xnew);
        }
        private:
        Points2D m_data;
    };
}
#endif