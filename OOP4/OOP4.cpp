#include<iostream>
#include"Matrix.h"
using namespace std;

int main() {
	/*int* aas = new int[4];
	for (int i = 0; i < 4; i++)
	{
		aas[i] = i;
	}
	Matrix a(3,2);
	Matrix b;
	Matrix c(2, 2, aas);
	Matrix x(a);
	cout << a << endl;
	cout << "~~~" << endl;
	cout << b << endl;
	cout << "~~~" << endl;
	cout << c << endl;
	cout << "~~~" << endl;
	cout << x << endl;
	cout << "~~~" << endl;
	string sda = (string)c;
	cout << sda << endl;*/


	/*int* aas = new int[4];
	for (int i = 0; i < 4; i++)
	{
		aas[i] = i;
	}
	Matrix c(2, 2, aas);
	Matrix a;
	cout << a << endl;
	a = c;
	cout << a << endl;
	cout << c << endl;
	c.setValue(1, 1, 15);
	string as = (string)c;
	cout << c << endl;
	cout << as << endl;
	cin >> a;
	cout << a << endl;*/

	int* aas = new int[4];
	for (int i = 0; i < 4; i++)
	{
		aas[i] = i;
	}

	int* aas2 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		aas2[i] = i;
	}
	Matrix c(2, 2, aas);
	Matrix d(2, 2, aas2);
	Matrix pl = c + d;
	Matrix min = c - d;
	cout << pl << endl;
	cout << min << endl;
	c += d;
	cout << c << endl;

	/*int* aas = new int[12];
	for (int i = 0; i < 12; i++)
	{
		aas[i] = i;
	}

	int* aas2 = new int[6];
	for (int i = 0; i < 6; i++)
	{
		aas2[i] = i;
	}

	Matrix a(4, 3, aas);
	Matrix b(3, 2, aas2);
	Matrix prod = a * b;
	cout << prod << endl;

	cout << a << endl;
	cout << b << endl;*/


	/*int* aas = new int[12];
	for (int i = 0; i < 12; i++)
	{
		aas[i] = i;
	}
	Matrix a(4, 3, aas);
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << a-- << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << --a << endl;
	cout << a << endl;*/
	
	return 0;
}