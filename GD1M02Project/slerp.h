//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: slerp.h
// Description	: slerp header
// Author		: Henry Oliver
// Mail			: henry.oliver@mediadesign.school.nz
//
#pragma once
#include <vector>
#include <math.h>
#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

struct CMatrix
{
	float data[16];
};

struct CSLERPRESULT {
	float data[4];
};

class slerp
{
public:
	slerp();
	~slerp();
	static CSLERPRESULT slerpQUART(HWND _hwnd, float as1, float bs1, float cs1, float ds1, float as2, float bs2, float cs2, float ds2, float ts);
	static CMatrix MATRIX(HWND _hwnd, float as1, float bs1, float cs1, float ds1);
};