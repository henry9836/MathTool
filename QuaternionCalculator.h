#pragma once
#include <math.h>

class QuaternionCalculator {
private:
	float a1 = 0, b1 = 0, c1 = 0, d1 = 0;
	float a2 = 0, b2 = 0, c2 = 0, d2 = 0;
	float r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	float Sq_T = 0;

public:
	QuaternionCalculator();
	~QuaternionCalculator();
	void SetA(float _i, float _j, float _k, float _r);
	void SetB(float _i, float _j, float _k, float _r);
	void SetT(float _Sq_MpBy);
	void Addition_AB();
	void Subtraction_AB();
	void Subtraction_BA();
	void Multiplication_BA();
	void Multiplication_AB();
	float A_Dot_B();
	void Conjugate_A();
	void Conjugate_B();
	float AbsValue_A();
	float AbsValue_B();
	void Inverse_A();
	void Inverse_B();
	void Multiply_A_byT();
	void Multiply_B_byT();
	float GetResult(float result);
};
