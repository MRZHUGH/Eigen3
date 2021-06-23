#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    //矩阵和向量乘法
    Matrix2d m;
    m << 1, 2,
         3, 4;
    Vector2d u(-1, 1), v(2, 1);
    cout << "Here is m*m:\n" << m*m << endl;
    cout << "Here is m*u:\n" << m*u << endl;
    cout << "Here is u^T*m:\n" << u.transpose()*m << endl;
    cout << "Here is u^T*v:\n" << u.transpose()*v << endl;
    cout << "Here is u*v^T:\n" << u*v.transpose() << endl;
    cout << "Let's multiple m by itself" << endl;
    m = m*m;
    cout << "Now m is: \n" << m << endl;
    
    return 0;

}