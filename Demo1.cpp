//参考：https://zhuanlan.zhihu.com/p/111727894

#include <iostream>
#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

#define MATRIX_SIZE 50

int main(int argc, char **argv)
{

    //声明一个2*3的矩阵，eigen中所有的向量矩阵均为Eigen::Matrix，是一个模板类。
    //三个参数分别为数据类型、行数、列数
    Matrix<float, 2, 3> matrix_23;
    //声明一个三维向量， Vector_3d实际上是通过typedef定义的内置类型，本质上仍然是Eigen
    Vector3d v_3d;
    
    //声明一个3*3的矩阵，并初始化为0矩阵
    Matrix3d matrix_33 = Matrix3d::Zero();

    //不确定矩阵大小时，可以使用动态大小的矩阵
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;

    //或更简单的方式
    MatrixXd matrix_x;

    //准备对Eigen矩阵初始化
    //输入数据
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "matrix 2*3 from 1 to 6: \n" << matrix_23 << endl;

    //使用（）访问矩阵中的元素
    cout << "print matrix 2*3: " << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix_23(i, j) << "\t";
        }
        cout << endl;
    }

    //初始化两个三维向量
    v_3d << 3, 2, 1;
    //不能混乘两种类型的矩阵，因此需要显示转换类型： .cast<type>
    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << "[1, 2, 3; 4, 5, 6]*[3, 2, 1] = " << result.transpose() << endl;
    // .transpose()是转置函数
    cout << "not transpose [1, 2, 3; 4, 5, 6]*[3, 2, 1] = " << result << endl;

    Matrix<float, 2, 1> result2 = matrix_23 * v_3d.cast<float>();
    cout << "[1, 2, 3; 4, 5, 6]*[3, 2, 1]" << result2.transpose() << endl;

    //生成一个随机矩阵
    matrix_33 = Matrix3d::Random();
    cout << "random matrix: \n" << matrix_33 << endl;
    cout << "transpose : \n" << matrix_33.transpose() << endl;
    cout << "sum : " << matrix_33.sum() << endl;
    cout << "trace : " << matrix_33.trace() << endl;
    cout << "time 10 : \n" << 10 * matrix_33 << endl;
    cout << "inverse : \n" << matrix_33.inverse() << endl;
    cout << "det : \n" << matrix_33.determinant() << endl;

    //求特征值
    //实对称矩阵可以保证对角化成功
    //SelfAdjointEigenSolver<Matrix3d> 用于求解特征值和特征向量
    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
    cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;

    //练习求解方程
    //求解Matrix_NN * x = v_NN方程
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN
        = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN = matrix_NN * matrix_NN.transpose();
    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t time_stt = clock();

    //直接求逆
    Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
    cout << "time of normal inverse is"
        << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;

    //对于正定矩阵，还可以用cholesky分解来分解方程
    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    cout << "time of ldlt decomposition is "
        << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;


    return 0;
}