#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix(int, int);
	Matrix();
	~Matrix();
	Matrix(const Matrix& mat);
	void print();

	friend ostream& operator<<(ostream&, const Matrix&);

	static Matrix createIdentity(int);

private:
	int rows_, cols_;
	double** p;

	void allocSpace();
};
/* PUBLIC MEMBER FUNCTIONS
 ********************************/

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
	allocSpace();
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			p[i][j] = 0;
		}
	}
}

Matrix::Matrix() : rows_(1), cols_(1)
{
	allocSpace();
	p[0][0] = 0;
}

Matrix::~Matrix()
{
	//task 1: delete the 2D array, check the function allocSpace to see how the array is created.
	delete[] p;
	p = NULL;
	
}

//task 2:complete the copy constructor
Matrix::Matrix(const Matrix& mat)
{
	allocSpace();

	for (int r = 0; r < rows_; r++)
	{
		for (int c = 0; c < cols_; c++)
		{
			p[r][c] = mat.p[r][c];
		}
	}

}

/* STATIC CLASS FUNCTIONS
 ********************************/

Matrix Matrix::createIdentity(int size)
{
	Matrix temp(size, size);
	for (int i = 0; i < temp.rows_; ++i) {
		for (int j = 0; j < temp.cols_; ++j) {
			if (i == j) {
				temp.p[i][j] = 1;
			}
			else {
				temp.p[i][j] = 0;
			}
		}
	}
	return temp;
}

/* PRIVATE HELPER FUNCTIONS
 ********************************/

void Matrix::allocSpace()
{
	p = new double* [rows_];
	for (int i = 0; i < rows_; ++i) {
		p[i] = new double[cols_];
	}
}
//Operator Overloading
ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.rows_; ++i) {
		os << m.p[i][0];
		for (int j = 1; j < m.cols_; ++j) {
			os << " " << m.p[i][j];
		}
		os << endl;
	}
	return os;
}
void Matrix::print()
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
		
	}
}
int main()
{
	Matrix m1(3, 2);
	cout << m1;

	//task :
	//create a new matric m2 by calling the function createIdentity  
	Matrix m2 = m1.createIdentity(5);

	//print m2;
	m2.print();

	//task :
	//create a new matrix m3 using the copy constructor from m2
	Matrix m3 = m2;

	//print m3
	m3.print();
}
