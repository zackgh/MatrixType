#include "matrixType.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//display 
void matrixType::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

//set elemnt 
void matrixType::setElement(int r, int c, int newValue)
{
	matrix[r][c] = newValue;
}


//constructors
matrixType::matrixType(string file)
{
	ifstream data;
	data.open(file);
	data >> rows;
	data >> col;
	matrix = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[col];
	}
	int value;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < col; j++)
		{
			data >> value;
			matrix[i][j] = value;
		}
	
}
matrixType::matrixType(int r, int c)
{
	rows = r;
	col = c;
	matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[col];
	}
	
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
		}

}
//copy constructor
matrixType::matrixType(const matrixType & copy)
{
	rows = copy.rows;
	col = copy.col;
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[col];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < col; j++)
			matrix[i][j] = copy.matrix[i][j];
}

//Deconstructor 
matrixType::~matrixType()
{
	cout << "DONE" << " "<<rows <<" "<< col << endl;
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}



//Overloads -------------------------------------------------------------------------------------------------

// matrixType * matrixType
const matrixType matrixType::operator * (const matrixType & a) const
{
	if (col == a.rows)
	{
		matrixType product(rows, a.col);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < a.col; j++)
				for (int k = 0; k < col; k++)
					product.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
		return product;
	}
	else
	{
		cout << "Matrix dimesnions are not compatable." << endl;
	}
}
//Addition 
matrixType matrixType::operator + (const matrixType & a) const
{
	if (a.rows == rows && a.col == col)
	{
		matrixType sum(rows, col);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < col; j++)
				sum.matrix[i][j] = a.matrix[i][j] + matrix[i][j];
		return sum;
	}
	else
	{
		cout << "Matrix dimensions are not compatiable for addition." << endl;
	}
}
//Subtraction 
matrixType matrixType::operator - (const matrixType & a) const
{
	if (a.rows == rows && a.col == col)
	{
		matrixType sum(rows, col);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < col; j++)
				sum.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
		return sum;
	}
	else
	{
		cout << "Matrix dimensions are not compatiable for subtraction." << endl;
	}
}
//Equals ==
bool matrixType::operator == (const matrixType & a) const
{
	if (a.rows != rows || a.col != col)
		return false;

	for (int i = 0; i<rows; i++)
		for (int j = 0; j < col; j++)
		{
			if (a.matrix[i][j] != matrix[i][j])
			{
				return false;
			}
			else
			{
				return true;
			}
		}
}

//Friends-----------------------------------------------------------------------------------------------------

//  <<  overload
ostream & operator << (ostream & osObject, const matrixType & a)
{
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.col; j++)
			cout << a.matrix[i][j] << " ";
		cout << endl;
	}
	return osObject;
}

//int * matrixType
matrixType & operator * (const int c, matrixType & m)
{
	for (int i = 0; i < m.rows; i++)
		for (int j = 0; j < m.col; j++)
			m.matrix[i][j] = m.matrix[i][j] * c;
	return m;
}

// matrixType * int 
matrixType & operator * (matrixType &m, int c)
{
	matrixType z(m.rows, m.col);
	z = c * m;
	return z; 
}

// set equal to 
matrixType matrixType :: operator = (const matrixType & rightObject)
{
	if (this != &rightObject)
	{
		for (int i = 0; i < rows; i++)
			delete matrix[i];
		delete[] matrix;
		rows = rightObject.rows;
		col = rightObject.col;
		matrix = new int *[rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[col];
		for (int i = 0; i < rightObject.rows; i++)
			for (int j = 0; j < rightObject.col; j++)
				this->matrix[i][j] = rightObject.matrix[i][j];
	}
	return *this;
}

