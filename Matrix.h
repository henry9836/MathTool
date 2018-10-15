#pragma once
#include <vector>
#include <math.h>
#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

class CMatrixCalculator {
private:
	
	double a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
	double b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44;
	float ResultMatrix[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	};

public:

	CMatrixCalculator();
	~CMatrixCalculator();

	void Multiplication_AB(double &_Sq1, double &_Sq2, double &_Sq3, double &_Sq4, double &_Sq5,
		double &_Sq6, double &_Sq7, double &_Sq8, double &_Sq9, double &_Sq10, double &_Sq11,
		double &_Sq12, double &_Sq13, double &_Sq14, double &_Sq15, double &_Sq16);

	void Multiplication_BA(double &_Sq1, double &_Sq2, double &_Sq3, double &_Sq4, double &_Sq5,
		double &_Sq6, double &_Sq7, double &_Sq8, double &_Sq9, double &_Sq10, double &_Sq11,
		double &_Sq12, double &_Sq13, double &_Sq14, double &_Sq15, double &_Sq16);

	static float MultiplyMatrix(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44, float b11, float b12, float b13, float b14, float b21, float b22, float b23, float b24, float b31, float b32, float b33, float b34, float b41, float b42, float b43, float b44, float result[4][4]);

	static float Det(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34, float a41, float a42, float a43, float a44);

	

};

