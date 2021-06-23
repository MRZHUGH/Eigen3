#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

int main()
{
    MatrixXd m = MatrixXd::Random(3, 3);
    //定义3x3的随机矩阵m，各元素取值范围是[-1，1]
    m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
    //"MatrixXd::Constant(3,3,1.2)"定义各元素为1.2的3-by-3常数矩阵，m的取值范围变为[10，110]
    cout << "m =" << endl << m << endl;
    VectorXd v(3);//定义维度为3的列向量v
    v << 1, 2, 3;//赋值于v
    cout << "m * v =" << endl << m * v << endl;
    //矩阵的转置，共轭，逆
    MatrixXcf a = MatrixXcf::Random(2, 2);
    cout << "Here is the matrix a\n" << a << endl;
    cout << "Here is the matrix a^T\n" << a.transpose() << endl;
    cout << "Here is the matrix a^H\n" << a.conjugate() << endl;
    cout << "Here is the matrix a^{-1}\n" << a.inverse() << endl;

    return 0; 

}

