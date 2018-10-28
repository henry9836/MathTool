//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: slerp.cpp
// Description	: slerp calculations
// Author		: Henry Oliver
// Mail			: henry.oliver@mediadesign.school.nz

#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include "slerp.h"
#include "resource.h"
#include <windows.h>  
#include <windowsx.h> 


slerp::slerp()
{
}

slerp::~slerp()
{
}

float multiplyRealNum(float tmp1, float tmp2, float tmp3, float tmp4, float as1, float bs1, float cs1, float ds1) {
	return ((tmp4 * ds1) - (tmp1 * as1) - (tmp2 * bs1) - (tmp3 * cs1));
}

float MULTreal(float tmp1, float tmp2, float tmp3, float tmp4, float as1, float bs1, float cs1, float ds1)
{
	return ((tmp4 * ds1) - (tmp1*as1) - (tmp2* bs1) - (tmp3 *cs1));
}

float MULTi(float tmp1, float tmp2, float tmp3, float tmp4, float as1, float bs1, float cs1, float ds1)
{
	return((tmp4 * as1) + (tmp1 * ds1) + (tmp2 * cs1) - (tmp3 * bs1));
}

float MULTj(float tmp1, float tmp2, float tmp3, float tmp4, float as1, float bs1, float cs1, float ds1)
{
	return ((tmp4 * bs1) - (tmp1 * cs1) + (tmp2 * ds1) + (tmp3 * as1));
}

float MULTk(float tmp1, float tmp2, float tmp3, float tmp4, float as1, float bs1, float cs1, float ds1)
{
	return  ((tmp4 * cs1) + (tmp1 * bs1) - (tmp2 * as1) + (tmp3 * ds1));
}

float* slerp::MATRIX(HWND _hwnd, float as1, float bs1, float cs1, float ds1)
{
	float MATray[16];
	float* ptr; //to help send array through functions
	ptr = MATray;
	float tmp1 = -as1; //i
	float tmp2 = -bs1; //j
	float tmp3 = -cs1; //k
	float tmp4 = ds1; //r
	int box = 1034;
	float i = 0.0f;
	float j = 0.0f;
	float k = 0.0f;
	float real = 0.0f;

	real = MULTreal(tmp1, tmp2, tmp3, tmp4, as1, bs1, cs1, ds1);
	i = MULTi(tmp1, tmp2, tmp3, tmp4, as1, bs1, cs1, ds1);
	j = MULTj(tmp1, tmp2, tmp3, tmp4, as1, bs1, cs1, ds1);
	k = MULTk(tmp1, tmp2, tmp3, tmp4, as1, bs1, cs1, ds1);

	i = sqrt(i + k + j + real);

	float s = 0.0f;
	s = pow(i, -2.0f);

	MATray[0] = (1.0f - (2.0f * s)*((pow(as1, 2)) + (pow(bs1, 2))));
	MATray[1] = ((2.0f * s)*((as1*bs1) - (cs1 * ds1)));
	MATray[2] = ((2.0f * s)*((as1 * cs1) - (bs1 * ds1)));
	MATray[3] = (0.0f);
	MATray[4] = ((2.0f * s) * ((as1 * bs1) + (cs1 * ds1)));
	MATray[5] = (1.0f - (2.0f * s)*((pow(as1, 2)) + (pow(cs1, 2))));
	MATray[6] = ((2.0f * s)*((bs1 * cs1) - (as1 * ds1)));
	MATray[7] = (0.0f);
	MATray[8] = ((2.0f * s)*((as1 * cs1) - (bs1 * ds1)));
	MATray[9] = ((2.0f * s) * ((bs1 * cs1) + (as1 * ds1)));
	MATray[10] = (1.0f - (2.0f * s)*((pow(as1, 2)) + (pow(bs1, 2))));
	MATray[11] = (0.0f);
	MATray[12] = (0.0f);
	MATray[13] = (0.0f);
	MATray[14] = (0.0f);
	MATray[15] = (1.0f);

	return ptr;
}

float* slerp::slerpQUART(HWND _hwnd, float as1, float bs1, float cs1, float ds1, float as2, float bs2, float cs2, float ds2, float tvalue)
{
	float result[4];
	float* ptr; //to help send array through functions
	ptr = result;

	float tmp1 = 0.0f; //i
	float tmp2 = 0.0f; //j
	float tmp3 = 0.0f; //k
	float tmp4 = 0.0f; //r
	float tmp5 = 0.0f;
	float tmp6 = 0.0f;
	float tmp7 = 0.0f;
	float tmp8 = 0.0f;


	float DOT = ((as1 * as2) + (bs1 * bs2) + (cs1 * cs2) + (ds1 * ds2));

	if (DOT < 1 && DOT > 0)
	{
		float theta = acosf(DOT);
		float invTheta = (1 / sin(theta));
		float scale = sin(theta * (1 - tvalue));
		float invScale = (sin(theta * tvalue) * invTheta * 1);

		tmp1 = as1 * scale;
		tmp2 = bs1 * scale;
		tmp3 = cs1 * scale;
		tmp4 = ds1 * scale;
		tmp5 = as2 * invScale;
		tmp6 = bs2 * invScale;
		tmp7 = cs2 * invScale;
		tmp8 = ds2 * invScale;

		tmp1 = tmp1 + tmp5;
		tmp2 = tmp2 + tmp6;
		tmp3 = tmp3 + tmp7;
		tmp4 = tmp4 + tmp8;

		result[0] = tmp1;
		result[1] = tmp2;
		result[2] = tmp3;
		result[3] = tmp4;

	}
	else
	{
		tmp1 = as2 - as1;
		tmp2 = bs2 - bs1;
		tmp3 = cs2 - cs1;
		tmp4 = ds2 - ds1;

		tmp1 = tmp1 * tvalue;
		tmp2 = tmp2 * tvalue;
		tmp3 = tmp3 * tvalue;
		tmp4 = tmp4 * tvalue;

		tmp1 = as1 + tmp1;
		tmp2 = bs1 + tmp2;
		tmp3 = cs1 + tmp3;
		tmp4 = ds1 + tmp4;

		float ans = sqrt(tmp1 + tmp2 + tmp3 + tmp4);

		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
		result[3] = ans;

	}

	return result;
}