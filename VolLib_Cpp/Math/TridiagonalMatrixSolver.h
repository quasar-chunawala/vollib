#include <Eigen/Core>
#include <Eigen/Dense>

namespace vol {
    
    struct TridiagonalMatrixSolver{

        Eigen::MatrixXd m_A;
        Eigen::VectorXd m_b;

        TridiagonalMatrixSolver(Eigen::MatrixXd A, Eigen::VectorXd b) : m_A{ A }, m_b{ b } {}

        Eigen::VectorXd solve(){
            Eigen::MatrixXd A_hat(m_A.rows(), m_A.cols() + 1);
            A_hat << m_A, m_b;  // Augmented matrix [M | r]

            double k {1 / A_hat(0, 0)};
            A_hat.row(0) *= k;
            

            // forward sweep
            for(auto j{1uz}; j < A_hat.rows(); ++j){
                k = A_hat(j, j) - A_hat(j, j - 1) * A_hat(j - 1, j);
                A_hat.row(j) *= k;
                A_hat.row(j) -= A_hat.row(j-1) * A_hat(j-1, j);
            }

            // reverse sweep
            for(auto j{A_hat.rows() - 2}; j>=0; --j){
                k = A_hat(j, j + 1);
                A_hat.row(j) -= k * A_hat.row(j + 1);
            }

            Eigen::VectorXd solutionVector = A_hat.col(A_hat.cols() - 1);
            return solutionVector;
        }
    };
}