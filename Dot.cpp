#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Vector3d v(1,2,3);
    Vector3d w(0,1,2);
    cout << "Dot product: " << v.dot(w) << endl;
    cout << "Cross product:\n" << v.cross(w) << endl;

}