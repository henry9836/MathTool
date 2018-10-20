#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include "Matrix.h"
#include <windows.h>  
#include <windowsx.h> 

using namespace std;


CMatrixCalculator::CMatrixCalculator() {

}

CMatrixCalculator::~CMatrixCalculator() {
}

float* CMatrixCalculator::MultiplyMatrix(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB)
{
	float* ptr; //to help send array through functions
	ptr = matrixResult;

	if (AB == true) {
		matrixResult[0] = (a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41);
		matrixResult[1] = (a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42);
		matrixResult[2] = (a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43);
		matrixResult[3] = (a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44);

		matrixResult[4] = (a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41);
		matrixResult[5] = (a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42);
		matrixResult[6] = (a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43);
		matrixResult[7] = (a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44);

		matrixResult[8] = (a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41);
		matrixResult[9] = (a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42);
		matrixResult[10] = (a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43);
		matrixResult[11] = (a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44);

		matrixResult[12] = (a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41);
		matrixResult[13] = (a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42);
		matrixResult[14] = (a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43);
		matrixResult[15] = (a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44);
	}

	if (AB == false) {
		matrixResult[0] = (b11 * a11 + b12 * a21 + b13 * a31 + b14 * a41);
		matrixResult[1] = (b11 * a12 + b12 * a22 + b13 * a32 + b14 * a42);
		matrixResult[2] = (b11 * a13 + b12 * a23 + b13 * a33 + b14 * a43);
		matrixResult[3] = (b11 * a14 + b12 * a24 + b13 * a34 + b14 * a44);

		matrixResult[4] = (b21 * a11 + b22 * a21 + b23 * a31 + b24 * a41);
		matrixResult[5] = (b21 * a12 + b22 * a22 + b23 * a32 + b24 * a42);
		matrixResult[6] = (b21 * a13 + b22 * a23 + b23 * a33 + b24 * a43);
		matrixResult[7] = (b21 * a14 + b22 * a24 + b23 * a34 + b24 * a44);

		matrixResult[8] = (b31 * a11 + b32 * a21 + b33 * a31 + b34 * a41);
		matrixResult[9] = (b31 * a12 + b32 * a22 + b33 * a32 + b34 * a42);
		matrixResult[10] = (b31 * a13 + b32 * a23 + b33 * a33 + b34 * a43);
		matrixResult[11] = (b31 * a14 + b32 * a24 + b33 * a34 + b34 * a44);

		matrixResult[12] = (b41 * a11 + b42 * a21 + b43 * a31 + b44 * a41);
		matrixResult[13] = (b41 * a12 + b42 * a22 + b43 * a32 + b44 * a42);
		matrixResult[14] = (b41 * a13 + b42 * a23 + b43 * a33 + b44 * a43);
		matrixResult[15] = (b41 * a14 + b42 * a24 + b43 * a34 + b44 * a44);
	}

	return ptr;
}

float CMatrixCalculator::Det(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44) {
	float result;

	result = a11 * ((a22*((a33*a44) - (a43*a34))) - (a23*((a32*a44) - (a42*a34))) + (a24*((a32*a43) - (a42*a33)))) -
		a12 * ((a21*((a33*a44) - (a43*a34))) - (a23*((a31*a44) - (a41*a34))) + (a24*((a31*a43) - (a41*a33)))) +
		a13 * ((a21*((a32*a44) - (a42*a34))) - (a22*((a31*a44) - (a41*a34))) + (a24*((a31*a42) - (a41*a32)))) -
		a14 * ((a21*((a32*a43) - (a42*a33))) - (a22*((a31*a43) - (a41*a33))) + (a23*((a31*a42) - (a41*a32))));

	return result;
}
