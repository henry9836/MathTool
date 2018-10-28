//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: Matrix.h
// Description	: Matrix Calculations
// Author		: Henry Oliver
// Mail			: henry.oliver@mediadesign.school.nz
//


#pragma once
#include <vector>
#include <math.h>
#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

class CMatrixCalculator {
private:


public:

	CMatrixCalculator();
	~CMatrixCalculator();

	static float* MultiplyMatrix(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB);

	static float Det(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44);

	static float* Addition_AB(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB);

	static float* Subtraction_AB(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB);

	static float* Multiply_by(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool AB, float mult);

	static float* Inverse(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float matrixA[16], float matrixB[16], float matrixResult[16], bool A);

	static float * Tranpose(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float matrixA[16], float matrixB[16], float matrixResult[16]);

	static float* SettoI(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float matrixA[16], float matrixB[16], float matrixResult[16]);

};

