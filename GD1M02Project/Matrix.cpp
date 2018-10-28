//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: Matrix.cpp
// Description	: Matrix Calculations
// Author		: Henry Oliver
// Mail			: henry.oliver@mediadesign.school.nz
//

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

	result = (a11 * ((a22*((a33*a44) - (a43*a34))) - (a23*((a32*a44) - (a42*a34))) + (a24*((a32*a43) - (a42*a33)))) -
		a12 * ((a21*((a33*a44) - (a43*a34))) - (a23*((a31*a44) - (a41*a34))) + (a24*((a31*a43) - (a41*a33)))) +
		a13 * ((a21*((a32*a44) - (a42*a34))) - (a22*((a31*a44) - (a41*a34))) + (a24*((a31*a42) - (a41*a32)))) -
		a14 * ((a21*((a32*a43) - (a42*a33))) - (a22*((a31*a43) - (a41*a33))) + (a23*((a31*a42) - (a41*a32)))));

	return result;
}

float* CMatrixCalculator::Addition_AB(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB)
{
	float* ptrm; //to help send array through functions
	ptrm = matrixResult;


	if (AB == true) {
		matrixResult[0] = (a11 + b11);		matrixResult[1] = (a12 + b12);		matrixResult[2] = (a13 + b13);		matrixResult[3] = (a14 + b14);
		matrixResult[4] = (a21 + b21);		matrixResult[5] = (a22 + b22);		matrixResult[6] = (a23 + b23);		matrixResult[7] = (a24 + b24);
		matrixResult[8] = (a31 + b31);		matrixResult[9] = (a32 + b32);		matrixResult[10] = (a33 + b33);		matrixResult[11] = (a34 + b34);
		matrixResult[12] = (a41 + b41);		matrixResult[13] = (a42 + b42);		matrixResult[14] = (a43 + b43);		matrixResult[15] = (a44 + b44);
	}
	else {

	}

	return ptrm;
}

float* CMatrixCalculator::Subtraction_AB(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB)
{
	float* ptrm; //to help send array through functions
	ptrm = matrixResult;


	if (AB == true) {
		matrixResult[0] = (a11 - b11);		matrixResult[1] = (a12 - b12);		matrixResult[2] = (a13 - b13);		matrixResult[3] = (a14 - b14);
		matrixResult[4] = (a21 - b21);		matrixResult[5] = (a22 - b22);		matrixResult[6] = (a23 - b23);		matrixResult[7] = (a24 - b24);
		matrixResult[8] = (a31 - b31);		matrixResult[9] = (a32 - b32);		matrixResult[10] = (a33 - b33);		matrixResult[11] = (a34 - b34);
		matrixResult[12] = (a41 - b41);		matrixResult[13] = (a42 - b42);		matrixResult[14] = (a43 - b43);		matrixResult[15] = (a44 - b44);
	}
	else {

	}

	return ptrm;
}

float* CMatrixCalculator::Multiply_by(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB, float mult) {
	
	float* ptr; //to help send array through functions
	ptr = matrixResult;

	if (AB == true) {
		matrixResult[0] = a11 * mult; 	matrixResult[1] = a12 * mult; 	matrixResult[2] = a13 * mult; 	matrixResult[3] = a14 * mult;
		matrixResult[4] = a21 * mult;		matrixResult[5] = a22 * mult;		 matrixResult[6] = a23 * mult;	matrixResult[7] = a24 * mult;
		matrixResult[8] = a31 * mult;		matrixResult[9] = a32 * mult;	matrixResult[10] = a33 * mult;	matrixResult[11] = a34 * mult;
		matrixResult[12] = a41 * mult;	matrixResult[13] = a42 * mult;	matrixResult[14] = a43 * mult;	matrixResult[15] = a44 * mult;
	}
	else {
		matrixResult[0] = b11 * mult; 	matrixResult[1] = b12 * mult; 	matrixResult[2] = b13 * mult; 	matrixResult[3] = b14 * mult;
		matrixResult[4] = b21 * mult;		matrixResult[5] = b22 * mult;		 matrixResult[6] = b23 * mult;	matrixResult[7] = b24 * mult;
		matrixResult[8] = b31 * mult;		matrixResult[9] = b32 * mult;	matrixResult[10] = b33 * mult;	matrixResult[11] = b34 * mult;
		matrixResult[12] = b41 * mult;	matrixResult[13] = b42 * mult;	matrixResult[14] = b43 * mult;	matrixResult[15] = b44 * mult;
	}
	return ptr;
}

float* CMatrixCalculator::Inverse(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool A) {

	float* ptr; //to help send array through functions
	ptr = matrixResult;

	if (A == true) {
		float Det_A = CMatrixCalculator::Det(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44);

		matrixResult[0] = (1 / Det_A)*(a22 * ((a33*a44) - (a43*a34)) - a23 * ((a32*a44) - (a42*a34)) + a24 * ((a32*a43) - (a42*a33)));
		matrixResult[1] = (-1 / Det_A) * (a12 * ((a33*a44) - (a43*a34)) - a13 * ((a32*a44) - (a42*a34)) + a14 * ((a32*a43) - (a42*a33)));
		matrixResult[2] = (1 / Det_A)*(a12 * ((a23*a44) - (a43*a24)) - a13 * ((a22*a44) - (a42*a24)) + a14 * ((a22*a43) - (a42*a23)));
		matrixResult[3] = (-1 / Det_A)* (a12 * ((a23*a34) - (a33*a24)) - a13 * ((a22*a34) - (a32*a24)) + a14 * ((a22*a33) - (a32*a23)));

		matrixResult[4] = (-1 / Det_A)* (a21 * ((a33*a44) - (a43*a34)) - a23 * ((a31*a44) - (a41*a34)) + a24 * ((a31*a43) - (a41*a33)));
		matrixResult[5] = (1 / Det_A)*(a11 * ((a33*a44) - (a43*a34)) - a13 * ((a31*a44) - (a41*a34)) + a14 * ((a31*a43) - (a41*a33)));
		matrixResult[6] = (-1 / Det_A)* (a11 * ((a23*a44) - (a43*a24)) - a13 * ((a21*a44) - (a41*a24)) + a14 * ((a21*a43) - (a41*a23)));
		matrixResult[7] = (1 / Det_A)*(a11 * ((a23*a34) - (a33*a24)) - a13 * ((a21*a34) - (a31*a24)) + a14 * ((a21*a33) - (a31*a23)));

		matrixResult[8] = (1 / Det_A)*(a21 * ((a32*a44) - (a42*a34)) - a22 * ((a31*a44) - (a41*a34)) + a24 * ((a31*a42) - (a41*a32)));
		matrixResult[9] = (-1 / Det_A)* (a11 * ((a32*a44) - (a42*a34)) - a12 * ((a31*a44) - (a41*a34)) + a14 * ((a31*a42) - (a41*a32)));
		matrixResult[10] = (1 / Det_A)*(a11 * ((a22*a44) - (a42*a24)) - a12 * ((a21*a44) - (a41*a24)) + a14 * ((a21*a42) - (a41*a22)));
		matrixResult[11] = (-1 / Det_A)* (a11 * ((a22*a34) - (a32*a24)) - a12 * ((a21*a34) - (a31*a24)) + a14 * ((a21*a32) - (a31*a22)));

		matrixResult[12] = (-1 / Det_A)* (a21 * ((a32*a43) - (a42*a33)) - a22 * ((a31*a43) - (a41*a33)) + a23 * ((a31*a42) - (a41*a32)));
		matrixResult[13] = (1 / Det_A)*(a11 * ((a32*a43) - (a42*a33)) - a12 * ((a31*a43) - (a41*a33)) + a13 * ((a31*a42) - (a41*a32)));
		matrixResult[14] = (-1 / Det_A)* (a11 * ((a22*a43) - (a42*a23)) - a12 * ((a21*a43) - (a41*a23)) + a13 * ((a21*a42) - (a41*a22)));
		matrixResult[15] = (1 / Det_A)*(a11 * ((a22*a33) - (a32*a23)) - a12 * ((a21*a33) - (a31*a23)) + a13 * ((a21*a32) - (a31*a22)));
	}
	else {
		float Det_B = CMatrixCalculator::Det(b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44);

		matrixResult[0] = (1 / Det_B)*(b22 * ((b33*b44) - (b43*b34)) - b23 * ((b32*b44) - (b42*b34)) + b24 * ((b32*b43) - (b42*b33)));
		matrixResult[1] = (-1 / Det_B) * (b12 * ((b33*b44) - (b43*b34)) - b13 * ((b32*b44) - (b42*b34)) + b14 * ((b32*b43) - (b42*b33)));
		matrixResult[2] = (1 / Det_B)*(b12 * ((b23*b44) - (b43*b24)) - b13 * ((b22*b44) - (b42*b24)) + b14 * ((b22*b43) - (b42*b23)));
		matrixResult[3] = (-1 / Det_B)* (b12 * ((b23*b34) - (b33*b24)) - b13 * ((b22*b34) - (b32*b24)) + b14 * ((b22*b33) - (b32*b23)));

		matrixResult[4] = (-1 / Det_B)* (b21 * ((b33*b44) - (b43*b34)) - b23 * ((b31*b44) - (b41*b34)) + b24 * ((b31*b43) - (b41*b33)));
		matrixResult[5] = (1 / Det_B)*(b11 * ((b33*b44) - (b43*b34)) - b13 * ((b31*b44) - (b41*b34)) + b14 * ((b31*b43) - (b41*b33)));
		matrixResult[6] = (-1 / Det_B)* (b11 * ((b23*b44) - (b43*b24)) - b13 * ((b21*b44) - (b41*b24)) + b14 * ((b21*b43) - (b41*b23)));
		matrixResult[7] = (1 / Det_B)*(b11 * ((b23*b34) - (b33*b24)) - b13 * ((b21*b34) - (b31*b24)) + b14 * ((b21*b33) - (b31*b23)));

		matrixResult[8] = (1 / Det_B)*(b21 * ((b32*b44) - (b42*b34)) - b22 * ((b31*b44) - (b41*b34)) + b24 * ((b31*b42) - (b41*b32)));
		matrixResult[9] = (-1 / Det_B)* (b11 * ((b32*b44) - (b42*b34)) - b12 * ((b31*b44) - (b41*b34)) + b14 * ((b31*b42) - (b41*b32)));
		matrixResult[10] = (1 / Det_B)*(b11 * ((b22*b44) - (b42*b24)) - b12 * ((b21*b44) - (b41*b24)) + b14 * ((b21*b42) - (b41*b22)));
		matrixResult[11] = (-1 / Det_B)* (b11 * ((b22*b34) - (b32*b24)) - b12 * ((b21*b34) - (b31*b24)) + b14 * ((b21*b32) - (b31*b22)));

		matrixResult[12] = (-1 / Det_B)* (b21 * ((b32*b43) - (b42*b33)) - b22 * ((b31*b43) - (b41*b33)) + b23 * ((b31*b42) - (b41*b32)));
		matrixResult[13] = (1 / Det_B)*(b11 * ((b32*b43) - (b42*b33)) - b12 * ((b31*b43) - (b41*b33)) + b13 * ((b31*b42) - (b41*b32)));
		matrixResult[14] = (-1 / Det_B)* (b11 * ((b22*b43) - (b42*b23)) - b12 * ((b21*b43) - (b41*b23)) + b13 * ((b21*b42) - (b41*b22)));
		matrixResult[15] = (1 / Det_B)*(b11 * ((b22*b33) - (b32*b23)) - b12 * ((b21*b33) - (b31*b23)) + b13 * ((b21*b32) - (b31*b22)));

	}

	return ptr;

}

float* CMatrixCalculator::Tranpose(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float matrixA[16], float matrixB[16], float matrixResult[16]) {

	float* ptr; //to help send array through functions
	ptr = matrixResult;

	matrixResult[0] = a11;		matrixResult[1] = a21;		matrixResult[2] = a31;		matrixResult[3] = a41;
	matrixResult[4] = a12;		matrixResult[5] = a22;		matrixResult[6] = a32;		matrixResult[7] = a42;
	matrixResult[8] = a13;		matrixResult[9] = a23;		matrixResult[10] = a33;		matrixResult[11] = a43;
	matrixResult[12] = a14;		matrixResult[13] = a24;		matrixResult[14] = a34;		matrixResult[15] = a44;

	return ptr;
}

float * CMatrixCalculator::SettoI(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float matrixA[16], float matrixB[16], float matrixResult[16])
{
	float* ptr; //to help send array through functions
	ptr = matrixResult;

	matrixResult[0] = 1;    matrixResult[1] = 0;    matrixResult[2] = 0;    matrixResult[3] = 0;
	matrixResult[4] = 0;	matrixResult[5] = 1;    matrixResult[6] = 0;    matrixResult[7] = 0;
	matrixResult[8] = 0;    matrixResult[9] = 0;    matrixResult[10] = 1;    matrixResult[11] = 0;
	matrixResult[12] = 0;    matrixResult[13] = 0;    matrixResult[14] = 0;    matrixResult[15] = 1;

	return ptr;
}