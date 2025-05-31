//矩阵运算函数
#include<PCH.h>
#include<Matrix.h>
void Matrix::InitializeMatrix() {//初始化矩阵大小
	p = new double* [rows];//分配rows个指针
	for (int i = 0; i < rows; ++i) {
		p[i] = new double[cols];//为p[i]进行动态内存分配，大小为cols
	}
}
//声明行数，列数，值为0的矩阵
Matrix::Matrix(int row_num,int col_num)
{
	rows = row_num;
	cols = col_num;
	InitializeMatrix();
	for (int i = 0; i < rows; i++)
	{
		for(int j=0;j<cols;j++)
		{
			p[i][j] = 0;
		}
	}
}
//声明行数，列数，值的矩阵
 Matrix::Matrix(int row_num,int col_num,double value) 
{
	 rows=row_num;
	 cols=col_num;
	 InitializeMatrix();
	 for (int i = 0; i < rows; i++)
	 {
		 for(int j=0;j<cols;j++)
		 {

			 p[i][j] = value;
		 }
	 }

}
//释放空间
Matrix:: ~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] p[i];
	}
	delete p;
}
//复制矩阵
Matrix& Matrix::operator=(const Matrix& m)
{  //矩阵相等直接返回
	if (this == &m)
	{
		return *this;
	}
	if (rows != m.rows || cols != m.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] p[i];
		}
		delete p;

		
		rows = m.rows;
		cols = m.cols;
		InitializeMatrix();
	}
	//复制
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			p[i][j] = m.p[i][j];
		}
		return *this;
	}


}
//将数组赋给矩阵
Matrix& Matrix::operator=(double* array)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] = *(array + i * cols + j);
		}
	}
	return *this;

}
//矩阵加
Matrix& Matrix::operator+=(const Matrix &m)
{
	for (int i = 0; i < rows; i++)
	{
		for(int j=0;j<cols;j++)
		{
			p[i][j] += m.p[i][j];
		}

	}
	return *this;
}
//矩阵减
Matrix& Matrix::operator-=(const Matrix &m)
{
	for (int i = 0; i < rows; i++)
	{
		for(int j=0;j<cols;j++)
		{
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
}
//矩阵乘法实现
Matrix Matrix::operator*(const Matrix& m)const
{
	Matrix multiply(rows, m.cols, 0.0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			for (int k = 0; k < cols; k++) {
				multiply.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	return multiply;

}
//矩阵除法的实现
/*Matrix Matrix::operator/(const Matrix& m)const
{
	
}*/
//矩阵乘
Matrix& Matrix::operator*=(const Matrix &m)
{
	if (cols != m.rows) {
		throw std::invalid_argument("乘法的矩阵维度不匹配");
	}
	Matrix temp(rows, m.cols);
	for (int i = 0; i < temp.rows; i++) {
		for (int j = 0; j < temp.cols; j++) {
			for (int k = 0; k < cols; k++) {
				temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	return *this;

}
//矩阵除
//Matrix& Matrix::operator/=(const Matrix& m)
//{
	
//}
//矩阵求逆