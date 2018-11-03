#pragma once
#ifndef _GAUSSIANCALCULATOR_H
#define _GAUSSIANCALCULATOR_H
#include <string>

struct ROW
{
	float data[4];
};

struct GMatrix
{
	float data[12];
};

class  GaussianCalculator
{
public:
	GaussianCalculator();
	~GaussianCalculator();
	ROW Multiply_Row_By(float _Row[4], float _Value);
	ROW AddTimestoRow(float _Row[4], float Old_row[4], float _Num);

	float Row[1][4];
	float Matrix[3][4];
};
#endif 