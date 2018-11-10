#include "TransformationCalculator.h"

TransformationCalculator::TransformationCalculator()
{
}

TransformationCalculator::~TransformationCalculator() {
}

Matrix TransformationCalculator::Scale_RowColumn(float scalex, float scaley, float scalez, Matrix mat){

	mat.data[0] = scalex; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
	
	mat.data[4] = 0; mat.data[5] = scaley; mat.data[6] = 0; mat.data[7] = 0;
	
	mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = scalez; mat.data[11] = 0;
	
	mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;

	return mat;

}

Matrix TransformationCalculator::Translate_Row(float scalex, float scaley, float scalez, Matrix mat) {

	mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = scalex;

	mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = scaley;

	mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = scalez;

	mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;

	return mat;
}

Matrix TransformationCalculator::Translate_Column(float x, float y, float z, Matrix mat) {

	mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;

	mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;

	mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;

	mat.data[12] = x; mat.data[13] = y; mat.data[14] = z; mat.data[15] = 1;

	return mat;
}

Matrix TransformationCalculator::Rot_Row(float x, float y, float z, float angle, Matrix mat) {

	if (x == 1) {
		y = 0;
		z = 0;
		mat.data[0] = 1.0f; mat.data[1] = 0.0f; mat.data[2] = 0.0f; mat.data[3] = 0.0f;
		mat.data[4] = 0.0f; mat.data[5] = cosf(angle); mat.data[6] = sinf(angle); mat.data[7] = 0.0f;
		mat.data[8] = 0.0f; mat.data[9] = -sinf(angle); mat.data[10] = cosf(angle); mat.data[11] = 0.0f;
		mat.data[12] = 0.0f; mat.data[13] = 0.0f; mat.data[14] = 0.0f; mat.data[15] = 1.0f;
	}
	if (y == 1) {
		z = 0;
		mat.data[0] = cosf(angle); mat.data[1] = 0; mat.data[2] = -sinf(angle); mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = sinf(angle); mat.data[9] = 0; mat.data[10] = cosf(angle); mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;
	}
	if (z == 1) {
		mat.data[0] = cosf(angle); mat.data[1] = sinf(angle); mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = -sinf(angle); mat.data[5] = cosf(angle); mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;
	}

	return mat;
}

Matrix TransformationCalculator::Rot_Column(float x, float y, float z, float angle, Matrix mat) {

	if (x == 1) {
		y = 0;
		z = 0;
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = cosf(angle); mat.data[6] = -sinf(angle); mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = sinf(angle); mat.data[10] = cosf(angle); mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;
	}
	if (y == 1) {
		z = 0;
		mat.data[0] = cosf(angle); mat.data[1] = 0; mat.data[2] = sinf(angle); mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = -sinf(angle); mat.data[9] = 0; mat.data[10] = cosf(angle); mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;
	}
	if (z == 1) {
		mat.data[0] = cosf(angle); mat.data[1] = -sinf(angle); mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = sinf(angle); mat.data[5] = cosf(angle); mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 1;
	}

	return mat;
}

Matrix TransformationCalculator::Proj_Row(float x, float y, float z, float distance, Matrix mat) {

	if (x == 1) {
		y = 0;
		z = 0;
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 1 / distance; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 0; 
	}
	if (y == 1) {
		z = 0;
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 1 / distance; mat.data[14] = 0; mat.data[15] = 0;
	}
	if (z == 1) {
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 1 / distance; mat.data[15] = 0;
	}

	return mat;
}

Matrix TransformationCalculator::Proj_Column(float x, float y, float z, float distance, Matrix mat) {

	if (x == 1) {
		y = 0;
		z = 0;
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 1 / distance;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 0;
	}
	if (y == 1) {
		z = 0;
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 1 / distance;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 0;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 0;
	}
	if (z == 1) {
		mat.data[0] = 1; mat.data[1] = 0; mat.data[2] = 0; mat.data[3] = 0;
		mat.data[4] = 0; mat.data[5] = 1; mat.data[6] = 0; mat.data[7] = 0;
		mat.data[8] = 0; mat.data[9] = 0; mat.data[10] = 1; mat.data[11] = 1 / distance;
		mat.data[12] = 0; mat.data[13] = 0; mat.data[14] = 0; mat.data[15] = 0;
	}

	return mat;
}

Matrix TransformationCalculator::Multiply_m(Matrix matA, Matrix matB, Matrix r_Mat)
{
	for (int iY = 0; iY < 4; iY++)
	{
		for (int iX = 0; iX < 4; iX++)
		{
			if (iY == 0 && iX == 0)
			{
				r_Mat.data[0] = ((matA.data[iX] * matB.data[iX]) + (matA.data[iX + 1] * matB.data[iX + 4]) + (matA.data[iX + 2] * matB.data[iX + 8]) + (matA.data[iX + 3] * matB.data[iX + 12]));
			}
			if (iY == 0 && iX == 1)
			{
				r_Mat.data[1] = ((matA.data[iX - 1] * matB.data[iX]) + (matA.data[iX] * matB.data[iX + 4]) + (matA.data[iX + 1] * matB.data[iX + 8]) + (matA.data[iX + 2] * matB.data[iX + 12]));
			}
			if (iY == 0 && iX == 2)
			{
				r_Mat.data[2] = ((matA.data[iX - 2] * matB.data[iX]) + (matA.data[iX - 1] * matB.data[iX + 4]) + (matA.data[iX] * matB.data[iX + 8]) + (matA.data[iX + 1] * matB.data[iX + 12]));
			}
			if (iY == 0 && iX == 3)
			{
				r_Mat.data[3] = ((matA.data[iX - 3] * matB.data[iX]) + (matA.data[iX - 2] * matB.data[iX + 4]) + (matA.data[iX - 1] * matB.data[iX + 8]) + (matA.data[iX] * matB.data[iX + 12]));
			}



			if (iY == 1 && iX == 0)
			{
				r_Mat.data[4] = ((matA.data[iX + 4] * matB.data[iX]) + (matA.data[iX + 5] * matB.data[iX + 4]) + (matA.data[iX + 6] * matB.data[iX + 8]) + (matA.data[iX + 7] * matB.data[iX + 12]));
			}

			if (iY == 1 && iX == 1)
			{
				r_Mat.data[5] = ((matA.data[iX + 3] * matB.data[iX]) + (matA.data[iX + 4] * matB.data[iX + 4]) + (matA.data[iX + 5] * matB.data[iX + 8]) + (matA.data[iX + 6] * matB.data[iX + 12]));
			}

			if (iY == 1 && iX == 2)
			{
				r_Mat.data[6] = ((matA.data[iX + 2] * matB.data[iX]) + (matA.data[iX + 3] * matB.data[iX + 4]) + (matA.data[iX + 4] * matB.data[iX + 5]) + (matA.data[iX + 5] * matB.data[iX + 12]));
			}

			if (iY == 1 && iX == 3)
			{
				r_Mat.data[7] = ((matA.data[iX + 1] * matB.data[iX]) + (matA.data[iX + 2] * matB.data[iX + 4]) + (matA.data[iX + 3] * matB.data[iX + 8]) + (matA.data[iX + 4] * matB.data[iX + 12]));
			}



			if (iY == 2 && iX == 0)
			{
				r_Mat.data[8] = ((matA.data[iX + 8] * matB.data[iX]) + (matA.data[iX + 9] * matB.data[iX + 4]) + (matA.data[iX + 10] * matB.data[iX + 8]) + (matA.data[iX + 11] * matB.data[iX + 12]));
			}
			if (iY == 2 && iX == 1)
			{
				r_Mat.data[9] = ((matA.data[iX + 7] * matB.data[iX]) + (matA.data[iX + 8] * matB.data[iX + 4]) + (matA.data[iX + 9] * matB.data[iX + 8]) + (matA.data[iX + 10] * matB.data[iX + 12]));
			}
			if (iY == 2 && iX == 2)
			{
				r_Mat.data[10] = ((matA.data[iX + 6] * matB.data[iX]) + (matA.data[iX + 7] * matB.data[iX + 4]) + (matA.data[iX + 8] * matB.data[iX + 8]) + (matA.data[iX + 9] * matB.data[iX + 12]));
			}
			if (iY == 2 && iX == 3)
			{
				r_Mat.data[11] = ((matA.data[iX + 5] * matB.data[iX]) + (matA.data[iX + 6] * matB.data[iX + 4]) + (matA.data[iX + 7] * matB.data[iX + 8]) + (matA.data[iX + 8] * matB.data[iX + 12]));
			}



			if (iY == 3 && iX == 0)
			{
				r_Mat.data[12] = ((matA.data[iX + 12] * matB.data[iX]) + (matA.data[iX + 13] * matB.data[iX + 4]) + (matA.data[iX + 14] * matB.data[iX + 8]) + (matA.data[iX + 15] * matB.data[iX + 12]));
			}

			if (iY == 3 && iX == 1)
			{
				r_Mat.data[13] = ((matA.data[iX + 11] * matB.data[iX]) + (matA.data[iX + 12] * matB.data[iX + 4]) + (matA.data[iX + 13] * matB.data[iX + 8]) + (matA.data[iX + 14] * matB.data[iX + 12]));
			}
			if (iY == 3 && iX == 2)
			{
				r_Mat.data[14] = ((matA.data[iX + 10] * matB.data[iX]) + (matA.data[iX + 11] * matB.data[iX + 4]) + (matA.data[iX + 12] * matB.data[iX + 8]) + (matA.data[iX + 13] * matB.data[iX + 12]));
			}
			if (iY == 3 && iX == 3)
			{
				r_Mat.data[15] = ((matA.data[iX + 9] * matB.data[iX]) + (matA.data[iX + 10] * matB.data[iX + 4]) + (matA.data[iX + 11] * matB.data[iX + 8]) + (matA.data[iX + 12] * matB.data[iX + 12]));
			}
		}
	}
	return r_Mat;
}