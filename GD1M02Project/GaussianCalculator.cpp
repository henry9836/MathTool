//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: GaussianCalculator.cpp
// Description	: GaussianCalculator Calculations
// Author		: Henry Oliver
// Mail			: henry.oliver@mediadesign.school.nz
//

#include "GaussianCalculator.h"

GaussianCalculator::GaussianCalculator()
{
}

GaussianCalculator::~GaussianCalculator()
{
}

ROW GaussianCalculator::Multiply_Row_By(float _Row[4], float _Value) {

	ROW result;

	for (int j = 0; j < 4; j++) {
		result.data[j] = _Value * _Row[j];
	}

	return result;
}

 ROW GaussianCalculator::AddTimestoRow(float _Row[4], float Old_row[4], float _Num) {
	
	 ROW resultRow;
	 ROW toAddRow;
	 ROW oldRow;

	for (int _i = 0; _i < 4; _i++) {
		toAddRow.data[_i] = _Row[_i];
		oldRow.data[_i] = Old_row[_i];
	}

	resultRow = Multiply_Row_By(_Row, _Num);

	for (int _i = 0; _i < 4; _i++) {
		resultRow.data[_i] = oldRow.data[_i] + resultRow.data[_i];
	}

	return resultRow;
}