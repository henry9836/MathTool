#include <math.h>
#include "Matrix.h"

CMatrixCalculator::CMatrixCalculator()
{
	Matrix[4][4], ResultMatrix[4][4];
}

CMatrixCalculator::~CMatrixCalculator()
{
}

void CMatrixCalculator::setValue(int iColumn, int iRow, float fValue)
{
	Matrix[iRow][iColumn] = fValue;
}


/*//Needed to get the determinant
void getCofactor(std::array<std::array<float, 4>, 4> A, std::array<std::array<float, 4>, 4> temp, int p, int q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix 
	for (int iRow = 0; iRow < n; iRow++)
	{
		for (int iCol = 0; iCol < n; iCol++)
		{
			//  Copying into temporary matrix only those element 
			//  which are not in given row and column 
			if (iRow != p && iCol != q)
			{
				temp[i][j++] = A[iRow][iCol];

				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
float Determinant(std::array<std::array<float, 4>, 4> A, int n)
{
	float D = 0; // Initialize result 

	std::array<std::array<float, 4>, 4> temp = { {
		{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
		} }; // To store cofactors 

	int sign = 1;  // To store sign multiplier 

				   // Iterate for each element of first row 
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of A[0][f] 
		getCofactor(A, temp, 0, f, n);
		D += sign * A[0][f] * Determinant(temp, n - 1);

		// terms are to be added with alternate sign 
		sign = -sign;
	}

	return D;
}
float CMatrixCalculator::DeterminantA()
{
	std::array<std::array<float, 4>, 4> A = { {
		{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
		} };
	float D = 0; // Initialize result 
	//To Stop it from looping on itself
	std::copy(&Matrix[0][0], &Matrix[0][0]+4*4, &A[0][0]);

	std::array<std::array<float, 4>, 4> temp = { {
		{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
		} }; // To store cofactors 

	float sign = 1;  // To store sign multiplier 

				   // Iterate for each element of first row 
	for (int f = 0; f < 4; f++)
	{
		// Getting Cofactor of A[0][f] 
		getCofactor(A, temp, 0, f, 4);
		D += sign * A[0][f] * Determinant(temp, 4 - 1);

		// terms are to be added with alternate sign 
		sign = -sign;
	}

	return D;
}*/
void CMatrixCalculator::multiplyMatrix(float fValue)
{
	for (int iRow = 1; iRow < 5; iRow++)
	{	
		for (int iCol = 1; iCol < 5; iCol++)
		{
			ResultMatrix[iRow][iCol] = Matrix[iRow][iCol] * fValue;
		}
	}
	return;
}

float CMatrixCalculator::getResultant(int iColumn, int iRow)
{
	return ResultMatrix[iColumn][iRow];
}
