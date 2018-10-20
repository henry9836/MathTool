#include "QuaternionCalculator.h"

QuaternionCalculator::QuaternionCalculator()
{
}

QuaternionCalculator::~QuaternionCalculator()
{
}

void QuaternionCalculator::SetA(float _i, float _j, float _k, float _r)
{
	this->a1 = _i;
	this->b1 = _j;
	this->c1 = _k;
	this->r1 = _r;
}

void QuaternionCalculator::SetB(float _i, float _j, float _k, float _r)
{
	this->a2 = _i;
	this->b2 = _j;
	this->c2 = _k;
	this->r2 = _r;
}

void QuaternionCalculator::SetT(float _Sq_MpBy, float _ADotB, float _AbsVal_A, float _AbsVal_B)
{
	this->Sq_T = _Sq_MpBy;
}

void QuaternionCalculator::Addition_AB(float & i, float & j, float & k, float & r)
{
	i = this->a1 + this->a2;
	j = this->b1 + this->b2;
	k = this->c1 + this->c2;
	r = this->r1 + this->r2;


}

void QuaternionCalculator::Subtraction_AB(float & i, float & j, float & k, float & r)
{
	i = this->a1 - this->a2;
	j = this->b1 - this->b2;
	k = this->c1 - this->c2;
	r = this->r1 - this->r2;
}

void QuaternionCalculator::Subtraction_BA(float & i, float & j, float & k, float & r)
{
	i = this->a2 - this->a1;
	j = this->b2 - this->b1;
	k = this->c2 - this->c1;
	r = this->r2 - this->r1;
}

void QuaternionCalculator::Multiplication_BA(float & i, float & j, float & k, float & r)
{
	i = (a2 * r1 + b2 * c1 - c2 * b1 + r2 * a1);
	j = (-1 * a2 * c1 + b1 * r1 + c2 * a1 + r2 * b1);
	k = (a2 * b1 - b2 * a1 + c2 * r1 + r2 * c1);
	r = (-1 * a2 * a1 - b2 * b1 - c2 * c1 + r2 * r1);
}

void QuaternionCalculator::Multiplication_AB(float & i, float & j, float & k, float & r)
{
	i = (a1 * r2 + b1 * c2 - c1 * b2 + r1 * a2);
	j = (-1 * a1 * c2 + b1 * r2 + c1 * a2 + r1 * b2);
	k = (a1 * b2 - b1 * a2 + c1 * r2 + r1 * c2);
	r = (-1 * a1 * a2 - b1 * b2 - c1 * c2 + r1 * r2);
}

float QuaternionCalculator::A_Dot_B(float a1, float b1, float c1, float r1, float a2, float b2, float c2, float r2)
{
	float ADotB;
	ADotB = a1 * a2 + a1 * b2 + a1 * c2 + a1 * r2 + b1 * a2 + b1 * b2 + b1 * c2 + b1 * r2 + c1 * a2 +
		c1 * b2 + c1 * c2 + c1 * r2 + r1 * a2 + r1 * b2 + r1 * c2 + r1 * r2;
	return ADotB;
	return 0.0f;
}

void QuaternionCalculator::Conjugate_A(float & i, float & j, float & k, float & r)
{
	i = -1 * (a1);
	j = -1 * (b1);
	k = -1 * (c1);
	r = (r1);
}

void QuaternionCalculator::Conjugate_B(float & i, float & j, float & k, float & r)
{
	i = -1 * (a2);
	j = -1 * (b2);
	k = -1 * (c2);
	r = (r2);
}

float QuaternionCalculator::AbsValue_A(float a1, float b1, float c1, float r1)
{
	float AbsValue;
	AbsValue = sqrt(pow(a1, 2) + pow(b1, 2) + pow(c1, 2) + pow(r1, 2));
	return AbsValue;
}

float QuaternionCalculator::AbsValue_B(float a2, float b2, float c2, float r2)
{
	float AbsValue;
	AbsValue = sqrt(pow(a2, 2) + pow(b2, 2) + pow(c2, 2) + pow(r2, 2));
	return AbsValue;
}

void QuaternionCalculator::Inverse_A(float & i, float & j, float & k, float & r)
{
	float AbsValueA = this->AbsValue_A(a1, b1, c1, r1);

	i = (1 / (AbsValueA))*(a1);
	j = (1 / (AbsValueA))*(b1);
	k = (1 / (AbsValueA))*(c1);
	r = (1 / (AbsValueA))*(r1);
}

void QuaternionCalculator::Inverse_B(float & i, float & j, float & k, float & r)
{
	float AbsValueB = this->AbsValue_B(a2, b2, c2, r2);

	i = (1 / (AbsValueB))*(a2);
	j = (1 / (AbsValueB))*(b2);
	k = (1 / (AbsValueB))*(c2);
	r = (1 / (AbsValueB))*(r2);
}

void QuaternionCalculator::Multiply_A_by(float & i, float & j, float & k, float & r)
{
	i = a1 * Sq_T;
	j = b1 * Sq_T;
	k = c1 * Sq_T;
	r = r1 * Sq_T;
}

void QuaternionCalculator::Multiply_B_by(float & i, float & j, float & k, float & r)
{
	i = a2 * Sq_T;
	j = b2 * Sq_T;
	k = c2 * Sq_T;
	r = r2 * Sq_T;
}
