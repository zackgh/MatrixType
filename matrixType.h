#pragma once
#include<string>

using namespace std;
class matrixType
{
private:
	int rows;
	int col;
	int ** matrix;
public:
	//display 
	void display();

	//set element
	void setElement(int, int, int);


	//Overloads 
	const matrixType operator * (const matrixType & a)const; // multiplication overload 
	matrixType operator + (const matrixType & a)const; // addition overload 
	matrixType operator - (const matrixType & a)const; // subtraction overload 
	bool operator == (const matrixType & a) const; // == overload
	matrixType operator = (const matrixType & rightObject); // set equal to 
	//Friends 
	friend std::ostream & operator << (std::ostream &, const matrixType &); //insertion operator ovetrload
	friend matrixType & operator * (const int, matrixType & m); //int * matrixType
	friend matrixType & operator * (matrixType & m, int c); //int * matrixType
	//Constructors
	matrixType(int,int); //given dimensions 
	matrixType(string); //from file
	matrixType(const matrixType & copy); //copy constructor 
	~matrixType();	//Deconstructor 
};
