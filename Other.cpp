#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{

    Matrix3d m;
    m << 1, 2, 3,
         1, 2, 1,
         0, 2, 4;
    cout << "Here is m.determinant(): " << m.determinant() << endl;
    cout << "Here is m.sum(): " << m.sum() << endl;
    cout << "Here is m.prod(): " << m.prod() << endl;
    cout << "Here is m.mean(): " << m.mean() << endl;
    cout << "Here is m.minCoeff(): " << m.minCoeff() << endl;
    cout << "Here is m.maxCoeff(): " << m.maxCoeff() << endl;
    cout << "Here is m.trace(): " << m.trace() << endl;

    return 0;
}