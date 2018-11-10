
#include <math.h>

struct rowMatrix
{
	float data[16];
};

struct columnMatrix
{
	float data[16];
};

struct Matrix
{
	float data[16];
};

class TransformationCalculator {
private:

public:

	TransformationCalculator();
	~TransformationCalculator();

	Matrix Scale_RowColumn(float scalex, float scaley, float scalez, Matrix mat);

	Matrix Translate_Row(float scalex, float scaley, float scalez, Matrix mat);

	Matrix Translate_Column(float scalex, float scaley, float scalez, Matrix mat);

	Matrix Rot_Row(float x, float y, float z, float angle, Matrix mat);

	Matrix Rot_Column(float x, float y, float z, float angle, Matrix mat);

	Matrix Proj_Row(float x, float y, float z, float distance, Matrix mat);

	Matrix Proj_Column(float x, float y, float z, float distance, Matrix mat);

	Matrix Multiply_m(Matrix matA, Matrix matB, Matrix r_Mat);
};
