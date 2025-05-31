#pragma once
#ifndef __MATRIX_CLL_H__
#define __MATRIX_CCL_H__
#include "pch.h"

class Matrix
{


private:
	int rows, cols;//矩阵行和列的数量
	double  ** p;
	void InitializeMatrix();//初始化矩阵

public:
	Matrix(int, int);
	Matrix(int, int, double);//预配分空间,矩阵行，列，数值
	virtual ~Matrix();//释放空间
	Matrix& operator=(const Matrix&);//矩阵的复制
	Matrix& operator=(double*);//将数组的值传给矩阵
	Matrix& operator+=(const Matrix&);//矩阵加
	Matrix& operator-=(const Matrix&);//矩阵减
	Matrix& operator*=(const Matrix&);//矩阵乘
	Matrix& operator/=(const Matrix&);//矩阵除
	Matrix operator*(const Matrix& m)const;//矩阵乘法的实现
	Matrix operator/(const Matrix& m)const;//矩阵除法的实现
	static Matrix Solve(const Matrix&, const Matrix&);//求解线性方程组Ax=b
	void Show() const;//矩阵显示
	void swapRows(int, int);
	double det();//求矩阵的行列式
	double Point(int i, int j) const;
	static Matrix inv(Matrix);//矩阵求逆
	static Matrix eye(int);//单位矩阵
	int row() const;
	int col() const;
	static Matrix T(const Matrix& m);//矩阵转置
	Matrix gaussianEliminate();//高斯消元法
	friend std::istream& operator>>(std::istream&, Matrix&);//实现矩阵的输入


};
#endif