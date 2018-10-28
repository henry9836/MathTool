#pragma once
#include <vector>
#include <math.h>
#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

class slerp
{
public:
	slerp();
	~slerp();
	static float* slerpQUART(HWND _hwnd, float as1, float bs1, float cs1, float ds1, float as2, float bs2, float cs2, float ds2, float ts);
	static float* MATRIX(HWND _hwnd, float as1, float bs1, float cs1, float ds1);

};