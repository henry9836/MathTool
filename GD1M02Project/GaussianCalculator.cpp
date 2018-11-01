#include "GaussianCalculator.h"

GaussianCalculator::GaussianCalculator()
{
}

GaussianCalculator::~GaussianCalculator()
{
}

ROW GaussianCalculator::Multiply_Row_By(float _Row[4],float _Value) {

	ROW result;

	for (int j = 0; j < 4; j++) {
		result.data[j] = _Value * _Row[j];
	}

	return result;
}

 ROW GaussianCalculator::AddTimestoRow(float _Row[4], float _Num) {
	
	 ROW resultRow;
	 ROW toAddRow;

	for (int _i = 0; _i < 4; _i++) {
		toAddRow.data[_i] = _Row[_i];
	}

	resultRow = Multiply_Row_By(_Row, _Num);

	/*for (int j = 0; j < 4; j++) {
		resultRow.data[j] = resultRow.data[j] + toAddRow.data[j];
	}*/
	return resultRow;
}