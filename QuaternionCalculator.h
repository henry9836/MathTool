#pragma once
#include <math.h>

class QuaternionCalculator {
private:
	float a1, b1, c1, r1;
	float a2, b2, c2, r2;
	float Sq_T;

public:
	QuaternionCalculator();
	~QuaternionCalculator();
	void SetA(float _i, float _j, float _k, float _r);
	void SetB(float _i, float _j, float _k, float _r);
	void SetT(float _Sq_MpBy, float _ADotB, float _AbsVal_A, float _AbsVal_B);
	void Addition_AB(float &i, float &j, float &k, float &r);
	void Subtraction_AB(float &i, float &j, float &k, float &r);
	void Subtraction_BA(float &i, float &j, float &k, float &r);
	void Multiplication_BA(float &i, float &j, float &k, float &r);
	void Multiplication_AB(float &i, float &j, float &k, float &r);
	float A_Dot_B(float a1, float b1, float c1, float r1, float a2, float b2, float c2, float r2);
	void Conjugate_A(float &i, float &j, float &k, float &r);
	void Conjugate_B(float &i, float &j, float &k, float &r);
	float AbsValue_A(float a1, float b1, float c1, float r1);
	float AbsValue_B(float a2, float b2, float c2, float r2);
	void Inverse_A(float &i, float &j, float &k, float &r);
	void Inverse_B(float &i, float &j, float &k, float &r);
	void Multiply_A_by(float &i, float &j, float &k, float &r);
	void Multiply_B_by(float &i, float &j, float &k, float &r);
};
