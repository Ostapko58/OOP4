#include <sstream>
#include <algorithm>
#include "Matrix.h"


Matrix::Matrix()
{
	this->data = new int[20];
	this->rows = 5;
	this->cols = 4;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			data[getSingleIndex(i, j)] = 0;
		}
	}
}

Matrix::Matrix(int rows, int cols)
{
	this->data = new int[rows * cols];
	this->rows = rows;
	this->cols = cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			data[getSingleIndex(i, j)] = 0;
		}
	}
}

Matrix::Matrix(int rows, int cols, int* data)
{
	this->data = data;
	this->rows = rows;
	this->cols = cols;
}

Matrix::Matrix(Matrix& o)
{
	data = new int[o.cols * o.rows];
	copy(o.data, o.data + o.size() + 1, data);
	//this->data = o.data;
	this->rows = o.rows;
	this->cols = o.cols;
}

Matrix::~Matrix()
{
	cout << this << endl;
	delete[] data;
}

int Matrix::getRows()
{
	return this->rows;
}

int Matrix::getCols()
{
	return this->cols;
}

int* Matrix::getData()
{
	return this->data;
}

void Matrix::setValue(int row, int col,int value)
{
	this->data[getSingleIndex(row, col)] = value;
}

int Matrix::size()
{
	return this->cols*this->rows;
}

Matrix& Matrix::operator=(Matrix& o)
{
	delete[] data;
	data = new int[o.cols * o.rows];
	for (int i = 0; i < o.cols * o.rows; i++)
	{
		data[i] = o.data[i];
	}
	this->rows = o.rows;
	this->cols = o.cols;
	return *this;
}

Matrix::operator string()
{
	stringstream stream;

	for (int i = 0; i < this->rows; i++) {
	for (int j = 0; j < this->cols; j++) {
		stream << this->data[getSingleIndex(i, j)] << '\t';
	}
	stream << '\n';
}
	return stream.str();

}



int Matrix::getSingleIndex(int row, int col)
{
	return (row * cols) + col;
}

ostream& operator<<(ostream& out,  Matrix& o)
{
	for (int i = 0; i < o.rows; i++)
	{
		for (int j = 0; j < o.cols; j++) {
			out << o.data[o.getSingleIndex(i,j)] << "\t";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matrix& o)
{
	for (int i = 0; i < o.rows; i++)
	{
		for (int j = 0; j < o.cols; j++) {
			printf("data[%i][%i] : ",i, j); in >> o.data[o.getSingleIndex(i, j)];
		}
	}
	return in;
}

Matrix& operator+(Matrix& m1, Matrix& m2)
{
	Matrix *a = new Matrix(m1.rows,m1.cols);
	for (int i = 0; i < a->rows*a->cols; i++)
	{
		a->data[i] = m1.data[i] + m2.data[i];
	}
	return *a;
}

Matrix& operator*(Matrix& m1, Matrix& m2)
{
	if (m1.cols!=m2.rows)
	{
		cout << "Incorrect data" << endl;
		exit(EXIT_FAILURE);
	}
	Matrix *res = new Matrix(m1.rows, m2.cols);
	for (int row = 0; row < m1.rows; row++) {
		for (int col = 0; col< m2.cols; col++) {
			for (int inner = 0; inner < m1.cols; inner++) {
				res->data[res->getSingleIndex(row,col)] += m1.data[m1.getSingleIndex(row,inner)] * m2.data[m2.getSingleIndex(inner,col)];
			}
		}
	}
	return *res;
}

Matrix& operator-(Matrix& m1, Matrix& m2)
{
	Matrix *a =new Matrix(m1.rows, m1.cols);
	for (int i = 0; i < a->rows * a->cols; i++)
	{
		a->data[i] = m1.data[i] - m2.data[i];
	}
	return *a;
}

Matrix& Matrix::operator+=(Matrix& m)
{
	for (int i = 0; i < this->cols*this->rows; i++)
	{
		this->data[i] += m.data[i];
	}
	return *this;
}

Matrix& Matrix::operator--()
{
	//delete[] data;
	int* tmp = new int[size() - cols];
	for(int i =0;i<this->size()-cols;i++){
		tmp[i] = data[i];
	}
	delete[] data;
	data = tmp;
	rows--;
	return *this;
}

Matrix& Matrix::operator++(int)
{
	Matrix *tmp = new Matrix(*this);

	int newCols = cols + 1;
	int* tmp2 = new int[size() + rows];
	for (int i = 0,j=0; i < size()+rows; i++)
	{
		if ((i+1)%newCols==0)
		{
			tmp2[i] = 0;
		}
		else tmp2[i] = data[j++];
	}
	//delete[] data;
	cols++ ;
	data = tmp2;
	return *tmp;
}

Matrix& Matrix::operator--(int)
{
	Matrix *tmp = new Matrix(*this);
	int newCols = cols - 1;
	int* tmp2 = new int[size() - rows];
	for (int i = 0, j = 0; i < size(); i++)
	{
		if (((i+1)%cols==0))
		{
			continue;
		}
		else tmp2[j++] = this->data[i];
	}
	
	delete[] data;
	cols--;
	data = tmp2;
	return *tmp;
}

Matrix& Matrix::operator++()
{
	//delete[] data;
	int* tmp = new int[size() + cols];
	/*for (int i = 0; i < this->size(); i++) {
		tmp[i] = data[i];
	}*/
	copy(data,data+size()+1, tmp);
	for (int i = 0; i < cols; i++)
	{
		tmp[size() + i] = 0;
	}
	delete[] data;
	data = tmp;
	rows++;
	return *this;
}
