#include<iostream>
#include<string>
using namespace std;
#pragma once
class Matrix
{
private:
	int* data;
	int rows;
	int cols;
	int getSingleIndex(int, int);
	
public:
	
	Matrix(); //+
	Matrix(int, int);  //+
	Matrix(int, int, int*);  //+
	Matrix(Matrix&);  //+
	~Matrix();  //+
	int getRows(); //+
	int getCols(); //+
	int* getData(); //+
	void setValue(int, int, int); //+
	int size(); //+
	Matrix& operator =(Matrix&); //+
	operator string(); //+
	friend ostream& operator << (ostream&, Matrix&); //+
	friend istream& operator >> (istream&, Matrix&); //+
	friend Matrix& operator + (Matrix&, Matrix&); //+
	friend Matrix& operator * (Matrix&, Matrix&); //+
	friend Matrix& operator - (Matrix&, Matrix&); //+
	Matrix& operator += (Matrix&); //+
	Matrix& operator++();  //+
	Matrix& operator--();  //+
	Matrix& operator++(int);  //+
	Matrix& operator--(int);  //+

};

