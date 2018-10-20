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
	this->d1 = _r;
}

void QuaternionCalculator::SetB(float _i, float _j, float _k, float _r)
{
	this->a2 = _i;
	this->b2 = _j;
	this->c2 = _k;
	this->d2 = _r;
}

void QuaternionCalculator::SetT(float _Sq_MpBy)
{
	this->Sq_T = _Sq_MpBy;
}

void QuaternionCalculator::Addition_AB()
{
	this->r1 = this->a1 + this->a2;
	this->r2 = this->b1 + this->b2;
	this->r3 = this->c1 + this->c2;
	this->r4 = this->d1 + this->d2;


}

void QuaternionCalculator::Subtraction_AB()
{
	this->r1 = this->a1 - this->a2;
	this->r2 = this->b1 - this->b2;
	this->r3 = this->c1 - this->c2;
	this->r4 = this->d1 - this->d2;
}

void QuaternionCalculator::Subtraction_BA()
{
	this->r1 = this->a2 - this->a1;
	this->r2 = this->b2 - this->b1;
	this->r3 = this->c2 - this->c1;
	this->r4 = this->d2 - this->d1;
}

void QuaternionCalculator::Multiplication_BA()
{
	this->r1 = (this->a2 * this->d1 + this->b2 * this->c1 - this->c2 * this->b1 + this->d2 * this->a1);
	this->r2 = (-1 * this->a2 * this->c1 + this->b1 * this->d1 + this->c2 * this->a1 + this->d2 * this->b1);
	this->r3 = (this->a2 * this->b1 - this->b2 * this->a1 + this->c2 * this->d1 + this->d2 * this->c1);
	this->r4 = (-1 * this->a2 * this->a1 - this->b2 * this->b1 - this->c2 * this->c1 + this->d2 * this->d1);
}

void QuaternionCalculator::Multiplication_AB()
{
	this->r1 = (this->a1 * this->d2 + this->b1 * this->c2 - this->c1 * this->b2 + this->d1 * this->a2);
	this->r2 = (-1 * this->a1 * this->c2 + this->b1 * this->d2 + this->c1 * this->a2 + this->d1 * this->b2);
	this->r3 = (this->a1 * this->b2 - this->b1 * this->a2 + this->c1 * this->d2 + this->d1 * this->c2);
	this->r4 = (-1 * this->a1 * this->a2 - this->b1 * this->b2 - this->c1 * this->c2 + this->d1 * this->d2);
}

float QuaternionCalculator::A_Dot_B()
{
	float ADotB;
	ADotB = this->a1 * this->a2 + this->a1 * this->b2 + this->a1 * this->c2 + this->a1 * this->r2 + this->b1 * this->a2 + this->b1 * this->b2 + this->b1 * this->c2 + this->b1 * this->r2 + this->c1 * this->a2 + this->c1 * this->b2 + this->c1 * this->c2 + this->c1 * this->r2 + this->r1 * this->a2 + this->r1 * this->b2 + this->r1 * this->c2 + this->r1 * this->r2;
	return ADotB;
}

void QuaternionCalculator::Conjugate_A()
{
	this->r1 = -1 * (this->a1);
	this->r2 = -1 * (this->b1);
	this->r3 = -1 * (this->c1);
	this->r4 = (this->d1);
}

void QuaternionCalculator::Conjugate_B()
{
	this->r1 = -1 * (this->a2);
	this->r2 = -1 * (this->b2);
	this->r3 = -1 * (this->c2);
	this->r4 = (this->d2);
}

float QuaternionCalculator::AbsValue_A()
{
	float AbsValue;
	AbsValue = sqrt(pow(this->a1, 2) + pow(this->b1, 2) + pow(this->c1, 2) + pow(this->r1, 2));
	return AbsValue;
}

float QuaternionCalculator::AbsValue_B()
{
	float AbsValue;
	AbsValue = sqrt(pow(this->a2, 2) + pow(this->b2, 2) + pow(this->c2, 2) + pow(this->r2, 2));
	return AbsValue;
}

void QuaternionCalculator::Inverse_A()
{
	float AbsValueA = this->AbsValue_A();

	this->r1 = (1 / (AbsValueA))*(this->a1);
	this->r2 = (1 / (AbsValueA))*(this->b1);
	this->r3 = (1 / (AbsValueA))*(this->c1);
	this->r4 = (1 / (AbsValueA))*(this->d1);
}

void QuaternionCalculator::Inverse_B()
{
	float AbsValueB = this->AbsValue_B();

	this->r1 = (1 / (AbsValueB))*(this->a2);
	this->r2 = (1 / (AbsValueB))*(this->b2);
	this->r3 = (1 / (AbsValueB))*(this->c2);
	this->r4 = (1 / (AbsValueB))*(this->d2);
}

void QuaternionCalculator::Multiply_A_byT()
{
	this->r1 = this->a1 * this->Sq_T;
	this->r2 = this->b1 * this->Sq_T;
	this->r3 = this->c1 * this->Sq_T;
	this->r4 = this->d1 * this->Sq_T;
}

void QuaternionCalculator::Multiply_B_byT()
{
	this->r1 = this->a2 * this->Sq_T;
	this->r2 = this->b2 * this->Sq_T;
	this->r3 = this->c2 * this->Sq_T;
	this->r4 = this->d2 * this->Sq_T;
}

float QuaternionCalculator::GetResult(float result)
{
	if (result == 1) {
		result = this->r1;
	}
	else if (result == 2) {
		result = this->r2;
	}
	else if (result == 3) {
		result = this->r3;
	}
	else if (result == 4) {
		result = this->r4;
	}

	return result;
}

