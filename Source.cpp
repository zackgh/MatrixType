#include <iostream>
#include<string>
#include "matrixType.h"
using namespace std;
int main()
{
	matrixType M1("text.txt");
	matrixType M2("text1.txt");
	matrixType M3("text2.txt");
	cout << "Matrix 1: " << endl << M1 << endl << endl;
	cout << "Matrix 2 :" << endl << M2 << endl << endl;
	cout << "Matrix 3 :" << endl << M3 << endl << endl;
	matrixType M4 = M1 + M3;
	cout << "M1 + M3 = " << endl << M4 << endl << endl;
	matrixType M5 = M1 * M2;
	cout << "M1 * M2 = " << endl << M5 << endl << endl;
	M5 = 2 * M5;
	cout << "M5 = " << endl << M5 << endl << endl;

	// copy test
	cout << "Matrix 1: " << endl << M1 << endl << endl;
	cout << "Matrix 2 :" << endl << M2 << endl << endl;
	M1 = M2;
	cout << "Matrix 1: " << endl << M1 << endl << endl;

	//Test ()
	matrixType M10(M1);
	cout << "Matrix 10: " << endl << M10 << endl << endl;

	system("pause");
	return 0;
}