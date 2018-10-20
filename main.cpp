//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: main.cpp
// Description	: main loop
// Author		: Henry Oliver
// Mail			: henry.oliver@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN
#define WINDOW_CLASS_NAME L"WINCLASS1"

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include <sstream>
#include <iostream>
#include "utils.h"
#include "resource.h"
#include "QuaternionCalculator.h"
#include "Matrix.h"

float tmp[16];
float tmp2[16];
float tmp3[16];
float ResultMatrix[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
};

float MatrixA[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
};

float MatrixB[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
};

/* MATRICES */
float a11 = 0, a12 = 0, a13 = 0, a14 = 0, a21 = 0, a22 = 0, a23 = 0, a24 = 0, a31 = 0, a32 = 0, a33 = 0, a34 = 0, a41 = 0, a42 = 0, a43 = 0, a44 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r21 = 0, r22 = 0, r23 = 0, r24 = 0, r31 = 0, r32 = 0, r33 = 0, r34 = 0, r41 = 0, r42 = 0, r43 = 0, r44 = 0, b11 = 0, b12 = 0, b13 = 0, b14 = 0, b21 = 0, b22 = 0, b23 = 0, b24 = 0, b31 = 0, b32 = 0, b33 = 0, b34 = 0, b41 = 0, b42 = 0, b43 = 0, b44 = 0;

/* Quaternions */

float a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0, tvalue = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0;


HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;
QuaternionCalculator *objQC = new QuaternionCalculator();
int MatrixC = 0;

int prep() {

	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp[i] = MatrixA[0][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp[i + 4] = MatrixA[1][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp[i + 8] = MatrixA[2][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp[i + 12] = MatrixA[3][i];
		}
	}

	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp2[i] = MatrixB[0][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp2[i + 4] = MatrixB[1][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp2[i + 8] = MatrixB[2][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp2[i + 12] = MatrixB[3][i];
		}
	}

	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp3[i] = ResultMatrix[0][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp3[i + 4] = ResultMatrix[1][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp3[i + 8] = ResultMatrix[2][i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			tmp3[i + 12] = ResultMatrix[3][i];
		}
	}
	return 0;

}

int reassmble(float ptr[]) {
	//resemble
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			ResultMatrix[0][i] = ptr[i];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			ResultMatrix[0][i] = ptr[i + 4];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			ResultMatrix[0][i] = ptr[i + 8];
		}
	}
	for (int i = 0; i < 4; i++) { //Prep to send to function
		if (i <= 4) {
			ResultMatrix[0][i] = ptr[i + 12];
		}
	}

	return 0;
}

void updateresult(HWND _hwnd, float ptr[]) {
	WriteToEditBox(_hwnd, IDC_EDIT_R11, ptr[0]);
	WriteToEditBox(_hwnd, IDC_EDIT_R12, ptr[1]);
	WriteToEditBox(_hwnd, IDC_EDIT_R13, ptr[2]);
	WriteToEditBox(_hwnd, IDC_EDIT_R14, ptr[3]);
	WriteToEditBox(_hwnd, IDC_EDIT_R21, ptr[4]);
	WriteToEditBox(_hwnd, IDC_EDIT_R22, ptr[5]);
	WriteToEditBox(_hwnd, IDC_EDIT_R23, ptr[6]);
	WriteToEditBox(_hwnd, IDC_EDIT_R24, ptr[7]);
	WriteToEditBox(_hwnd, IDC_EDIT_R31, ptr[8]);
	WriteToEditBox(_hwnd, IDC_EDIT_R32, ptr[9]);
	WriteToEditBox(_hwnd, IDC_EDIT_R33, ptr[10]);
	WriteToEditBox(_hwnd, IDC_EDIT_R34, ptr[11]);
	WriteToEditBox(_hwnd, IDC_EDIT_R41, ptr[12]);
	WriteToEditBox(_hwnd, IDC_EDIT_R42, ptr[13]);
	WriteToEditBox(_hwnd, IDC_EDIT_R43, ptr[14]);
	WriteToEditBox(_hwnd, IDC_EDIT_R44, ptr[15]);
}

void setQresult(HWND hwn) {
	WriteToEditBox(hwn, IDC_EDIT10, objQC->GetResult(1));
	WriteToEditBox(hwn, IDC_EDIT11, objQC->GetResult(2));
	WriteToEditBox(hwn, IDC_EDIT12, objQC->GetResult(3));
	WriteToEditBox(hwn, IDC_EDIT13, objQC->GetResult(4));
}

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

					// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{
			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
		//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			break;
		}
		//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
			break;
		}
		//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;

	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

	default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

BOOL CALLBACK MatrixDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	static float _value;
	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_EDIT_A11:
		{
			a11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			MatrixA[0][0] = a11;
			break;
		}
		case IDC_EDIT_A12: {
			a12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			MatrixA[0][1] = a12;
			break;
		}
		case IDC_EDIT_A13: {
			a13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			MatrixA[0][2] = a13;
			break;
		}
		case IDC_EDIT_A14: {
			a14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
			MatrixA[0][3] = a14;
			break;
		}
		case IDC_EDIT_A21: {
			a21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			MatrixA[1][0] = a21;
			break;
		}
		case IDC_EDIT_A22: {
			a22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			MatrixA[1][1] = a22;
			break;
		}
		case IDC_EDIT_A23: {
			a23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			MatrixA[1][2] = a23;
			break;
		}
		case IDC_EDIT_A24: {
			a24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
			MatrixA[1][3] = a24;
			break;
		}
		case IDC_EDIT_A31: {
			a31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			MatrixA[2][0] = a31;
			break;
		}
		case IDC_EDIT_A32: {
			a32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			MatrixA[2][1] = a32;
			break;
		}
		case IDC_EDIT_A33: {
			a33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			MatrixA[2][2] = a33;
			break;
		}
		case IDC_EDIT_A34: {
			a34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
			MatrixA[2][3] = a34;
			break;
		}
		case IDC_EDIT_A41: {
			a41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			MatrixA[3][0] = a41;
			break;
		}
		case IDC_EDIT_A42: {
			a42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			MatrixA[3][1] = a42;
			break;
		}
		case IDC_EDIT_A43: {
			a43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			MatrixA[3][2] = a43;
			break;
		}
		case IDC_EDIT_A44: {
			a44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);
			MatrixA[3][3] = a44;
			break;
		}
		case IDC_EDIT_B11:
		{
			b11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			MatrixB[0][0] = b11;
			break;
		}
		case IDC_EDIT_B12: {
			b12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			MatrixB[0][1] = b12;
			break;
		}
		case IDC_EDIT_B13: {
			b13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			MatrixB[0][2] = b13;
			break;
		}
		case IDC_EDIT_B14: {
			b14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
			MatrixB[0][3] = b14;
			break;
		}
		case IDC_EDIT_B21: {
			b21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			MatrixB[1][0] = b21;
			break;
		}
		case IDC_EDIT_B22: {
			b22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			MatrixB[1][1] = b22;
			break;
		}
		case IDC_EDIT_B23: {
			b23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			MatrixB[1][2] = b23;
			break;
		}
		case IDC_EDIT_B24: {
			b24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
			MatrixB[1][3] = b24;
			break;
		}
		case IDC_EDIT_B31: {
			b31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			MatrixB[2][0] = b31;
			break;
		}
		case IDC_EDIT_B32: {
			b32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			MatrixB[2][1] = b32;
			break;
		}
		case IDC_EDIT_B33: {
			b33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			MatrixB[2][2] = b33;
			break;
		}
		case IDC_EDIT_B34: {
			b34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
			MatrixB[2][3] = b34;
			break;
		}
		case IDC_EDIT_B41: {
			b41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			MatrixB[3][0] = b41;
			break;
		}
		case IDC_EDIT_B42: {
			b42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			MatrixB[3][1] = b42;
			break;
		}
		case IDC_EDIT_B43: {
			b43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			MatrixB[3][2] = b43;
			break;
		}
		case IDC_EDIT_B44: {
			b44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);
			MatrixB[3][3] = b44;
			break;
		}

		case IDC_EDIT_R11: {
			r11 = ReadFromEditBox(_hwnd, IDC_EDIT_R11);
			ResultMatrix[0][0] = r11;
			break;
		}
		case IDC_EDIT_R12: {
			r12 = ReadFromEditBox(_hwnd, IDC_EDIT_R12);
			ResultMatrix[0][1] = r12;
			break;
		}

		case IDC_EDIT_R13: {
			r13 = ReadFromEditBox(_hwnd, IDC_EDIT_R13);
			ResultMatrix[0][2] = r13;
			break;
		}
		case IDC_EDIT_R14: {
			r14 = ReadFromEditBox(_hwnd, IDC_EDIT_R14);
			ResultMatrix[0][3] = r14;
			break;
		}
		case IDC_EDIT_R21: {
			r21 = ReadFromEditBox(_hwnd, IDC_EDIT_R21);
			ResultMatrix[1][0] = r21;
			break;
		}
		case IDC_EDIT_R22: {
			r22 = ReadFromEditBox(_hwnd, IDC_EDIT_R22);
			ResultMatrix[1][1] = r22;
			break;
		}

		case IDC_EDIT_R23: {
			r23 = ReadFromEditBox(_hwnd, IDC_EDIT_R23);
			ResultMatrix[1][2] = r23;
			break;
		}
		case IDC_EDIT_R24: {
			r24 = ReadFromEditBox(_hwnd, IDC_EDIT_R24);
			ResultMatrix[1][3] = r24;
			break;
		}
		case IDC_EDIT_R31: {
			r31 = ReadFromEditBox(_hwnd, IDC_EDIT_R31);
			ResultMatrix[2][0] = r31;
			break;
		}
		case IDC_EDIT_R32: {
			r32 = ReadFromEditBox(_hwnd, IDC_EDIT_R32);
			ResultMatrix[2][1] = r32;
			break;
		}

		case IDC_EDIT_R33: {
			r33 = ReadFromEditBox(_hwnd, IDC_EDIT_R33);
			ResultMatrix[2][2] = r33;
			break;
		}
		case IDC_EDIT_R34: {
			r34 = ReadFromEditBox(_hwnd, IDC_EDIT_R34);
			ResultMatrix[2][3] = r34;
			break;
		}
		case IDC_EDIT_R41: {
			r41 = ReadFromEditBox(_hwnd, IDC_EDIT_R41);
			ResultMatrix[3][0] = r41;
			break;
		}
		case IDC_EDIT_R42: {
			r42 = ReadFromEditBox(_hwnd, IDC_EDIT_R42);
			ResultMatrix[3][1] = r42;
			break;
		}

		case IDC_EDIT_R43: {
			r43 = ReadFromEditBox(_hwnd, IDC_EDIT_R43);
			ResultMatrix[3][2] = r43;
			break;
		}
		case IDC_EDIT_R44: {
			r44 = ReadFromEditBox(_hwnd, IDC_EDIT_R44);
			ResultMatrix[3][3] = r44;
			break;
		}


		case IDOK3: {
			float m_MA;

			m_MA = CMatrixCalculator::Det(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44);
			WriteToEditBox(_hwnd, IDC_EDIT_DetA, m_MA);
			break;
		}

		case IDOK6: {
			float mult;

			mult = ReadFromEditBox(_hwnd, IDC_EDIT_AScaled);

			prep();

			float* ptr = CMatrixCalculator::Multiply_by(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, true, mult);
			
			reassmble(ptr);

			WriteToEditBox(_hwnd, IDC_EDIT_A11, ptr[0]);
			WriteToEditBox(_hwnd, IDC_EDIT_A12, ptr[1]);
			WriteToEditBox(_hwnd, IDC_EDIT_A13, ptr[2]);
			WriteToEditBox(_hwnd, IDC_EDIT_A14, ptr[3]);
			WriteToEditBox(_hwnd, IDC_EDIT_A21, ptr[4]);
			WriteToEditBox(_hwnd, IDC_EDIT_A22, ptr[5]);
			WriteToEditBox(_hwnd, IDC_EDIT_A23, ptr[6]);
			WriteToEditBox(_hwnd, IDC_EDIT_A24, ptr[7]);
			WriteToEditBox(_hwnd, IDC_EDIT_A31, ptr[8]);
			WriteToEditBox(_hwnd, IDC_EDIT_A32, ptr[9]);
			WriteToEditBox(_hwnd, IDC_EDIT_A33, ptr[10]);
			WriteToEditBox(_hwnd, IDC_EDIT_A34, ptr[11]);
			WriteToEditBox(_hwnd, IDC_EDIT_A41, ptr[12]);
			WriteToEditBox(_hwnd, IDC_EDIT_A42, ptr[13]);
			WriteToEditBox(_hwnd, IDC_EDIT_A43, ptr[14]);
			WriteToEditBox(_hwnd, IDC_EDIT_A44, ptr[15]);
			
			break;
		}

		case IDOK10: {
			float mult;

			mult = ReadFromEditBox(_hwnd, IDC_EDIT_BScaled);

			prep();

			float* ptr = CMatrixCalculator::Multiply_by(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, false, mult);

			reassmble(ptr);

			WriteToEditBox(_hwnd, IDC_EDIT_B11, ptr[0]);
			WriteToEditBox(_hwnd, IDC_EDIT_B12, ptr[1]);
			WriteToEditBox(_hwnd, IDC_EDIT_B13, ptr[2]);
			WriteToEditBox(_hwnd, IDC_EDIT_B14, ptr[3]);
			WriteToEditBox(_hwnd, IDC_EDIT_B21, ptr[4]);
			WriteToEditBox(_hwnd, IDC_EDIT_B22, ptr[5]);
			WriteToEditBox(_hwnd, IDC_EDIT_B23, ptr[6]);
			WriteToEditBox(_hwnd, IDC_EDIT_B24, ptr[7]);
			WriteToEditBox(_hwnd, IDC_EDIT_B31, ptr[8]);
			WriteToEditBox(_hwnd, IDC_EDIT_B32, ptr[9]);
			WriteToEditBox(_hwnd, IDC_EDIT_B33, ptr[10]);
			WriteToEditBox(_hwnd, IDC_EDIT_B34, ptr[11]);
			WriteToEditBox(_hwnd, IDC_EDIT_B41, ptr[12]);
			WriteToEditBox(_hwnd, IDC_EDIT_B42, ptr[13]);
			WriteToEditBox(_hwnd, IDC_EDIT_B43, ptr[14]);
			WriteToEditBox(_hwnd, IDC_EDIT_B44, ptr[15]);

			break;
		}

		case IDOK7: {
			float m_MB;

			m_MB = CMatrixCalculator::Det(b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44);
			WriteToEditBox(_hwnd, IDC_EDIT_DetB, m_MB);

			break;
		}

		case IDOK: {

			prep();

			float* ptr = CMatrixCalculator::Addition_AB(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, true);

			reassmble(ptr);

			updateresult(_hwnd, ptr);

			break;
		}

		case IDCANCEL: {

			prep();

			float* ptr = CMatrixCalculator::Subtraction_AB(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, true);

			reassmble(ptr);

			updateresult(_hwnd, ptr);

			break;
		}

		case IDOK2: {

			prep();

			float* ptr = CMatrixCalculator::MultiplyMatrix(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, true);

			reassmble(ptr);

			updateresult(_hwnd, ptr);

			break;
		}

		case IDOK5: {

			prep();

			float* ptr = CMatrixCalculator::MultiplyMatrix(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, false);

			reassmble(ptr);

			updateresult(_hwnd, ptr);

			break;
		}

		case IDCANCEL2: {
			prep();

			float* ptr = CMatrixCalculator::Inverse(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, true);

			reassmble(ptr);

			WriteToEditBox(_hwnd, IDC_EDIT_A11, ptr[0]);
			WriteToEditBox(_hwnd, IDC_EDIT_A12, ptr[1]);
			WriteToEditBox(_hwnd, IDC_EDIT_A13, ptr[2]);
			WriteToEditBox(_hwnd, IDC_EDIT_A14, ptr[3]);
			WriteToEditBox(_hwnd, IDC_EDIT_A21, ptr[4]);
			WriteToEditBox(_hwnd, IDC_EDIT_A22, ptr[5]);
			WriteToEditBox(_hwnd, IDC_EDIT_A23, ptr[6]);
			WriteToEditBox(_hwnd, IDC_EDIT_A24, ptr[7]);
			WriteToEditBox(_hwnd, IDC_EDIT_A31, ptr[8]);
			WriteToEditBox(_hwnd, IDC_EDIT_A32, ptr[9]);
			WriteToEditBox(_hwnd, IDC_EDIT_A33, ptr[10]);
			WriteToEditBox(_hwnd, IDC_EDIT_A34, ptr[11]);
			WriteToEditBox(_hwnd, IDC_EDIT_A41, ptr[12]);
			WriteToEditBox(_hwnd, IDC_EDIT_A42, ptr[13]);
			WriteToEditBox(_hwnd, IDC_EDIT_A43, ptr[14]);
			WriteToEditBox(_hwnd, IDC_EDIT_A44, ptr[15]);

			break;
		}

		case IDCANCEL3: {
			prep();

			float* ptr = CMatrixCalculator::Inverse(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44, b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44, tmp, tmp2, tmp3, false);

			reassmble(ptr);

			WriteToEditBox(_hwnd, IDC_EDIT_B11, ptr[0]);
			WriteToEditBox(_hwnd, IDC_EDIT_B12, ptr[1]);
			WriteToEditBox(_hwnd, IDC_EDIT_B13, ptr[2]);
			WriteToEditBox(_hwnd, IDC_EDIT_B14, ptr[3]);
			WriteToEditBox(_hwnd, IDC_EDIT_B21, ptr[4]);
			WriteToEditBox(_hwnd, IDC_EDIT_B22, ptr[5]);
			WriteToEditBox(_hwnd, IDC_EDIT_B23, ptr[6]);
			WriteToEditBox(_hwnd, IDC_EDIT_B24, ptr[7]);
			WriteToEditBox(_hwnd, IDC_EDIT_B31, ptr[8]);
			WriteToEditBox(_hwnd, IDC_EDIT_B32, ptr[9]);
			WriteToEditBox(_hwnd, IDC_EDIT_B33, ptr[10]);
			WriteToEditBox(_hwnd, IDC_EDIT_B34, ptr[11]);
			WriteToEditBox(_hwnd, IDC_EDIT_B41, ptr[12]);
			WriteToEditBox(_hwnd, IDC_EDIT_B42, ptr[13]);
			WriteToEditBox(_hwnd, IDC_EDIT_B43, ptr[14]);
			WriteToEditBox(_hwnd, IDC_EDIT_B44, ptr[15]);

			break;
		}

		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK GaussianDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{

	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK QuaternionDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_COMMAND: {
		switch (LOWORD(_wparam))
		{
		case IDC_EDIT1:
			a1 = ReadFromEditBox(_hwnd, IDC_EDIT1);
			objQC->SetA(a1, a2, a3, a4);
			break;
		case IDC_EDIT2:
			a2 = ReadFromEditBox(_hwnd, IDC_EDIT2);
			objQC->SetA(a1, a2, a3, a4);
			break;
		case IDC_EDIT3:
			a3 = ReadFromEditBox(_hwnd, IDC_EDIT3);
			objQC->SetA(a1, a2, a3, a4);
			break;
		case IDC_EDIT4:
			a4 = ReadFromEditBox(_hwnd, IDC_EDIT4);
			objQC->SetA(a1, a2, a3, a4);
			break;
		case IDC_EDIT5:
			b1 = ReadFromEditBox(_hwnd, IDC_EDIT5);
			objQC->SetB(b1, b2, b3, b4);
			break;
		case IDC_EDIT6:
			b2 = ReadFromEditBox(_hwnd, IDC_EDIT6);
			objQC->SetB(b1, b2, b3, b4);
			break;
		case IDC_EDIT7:
			b3 = ReadFromEditBox(_hwnd, IDC_EDIT7);
			objQC->SetB(b1, b2, b3, b4);
			break;
		case IDC_EDIT8:
			b4 = ReadFromEditBox(_hwnd, IDC_EDIT8);
			objQC->SetB(b1, b2, b3, b4);
			break;
		case IDC_EDIT9:
			tvalue = ReadFromEditBox(_hwnd, IDC_EDIT9);
			objQC->SetT(tvalue);
			break;
		case IDC_EDIT10:
			r1 = ReadFromEditBox(_hwnd, IDC_EDIT8);
			break;
		case IDC_EDIT11:
			break;
		case IDC_EDIT12:
			break;
		case IDC_EDIT13:
			break;
		case IDC_BUTTON1:
			objQC->Addition_AB();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON2:
			objQC->Multiplication_AB();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON3:
			objQC->Conjugate_A();
			setQresult(_hwnd);
			break;
		/*case IDC_BUTTON4:
			break;*/
		case IDC_BUTTON5:
			objQC->Subtraction_AB();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON6:
			objQC->Subtraction_BA();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON7:
			objQC->Multiplication_BA();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON8:
			float adotbtmp;
			adotbtmp = objQC->A_Dot_B();
			WriteToEditBox(_hwnd, IDC_EDIT10, adotbtmp);
			WriteToEditBox(_hwnd, IDC_EDIT11, NULL);
			WriteToEditBox(_hwnd, IDC_EDIT12, NULL);
			WriteToEditBox(_hwnd, IDC_EDIT13, NULL);
			break;
		case IDC_BUTTON9:
			objQC->Conjugate_B();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON10:
			float abs;
			abs = objQC->AbsValue_A();
			WriteToEditBox(_hwnd, IDC_EDIT9, abs);
			break;
		case IDC_BUTTON11:
			abs = objQC->AbsValue_B();
			WriteToEditBox(_hwnd, IDC_EDIT9, abs);
			break;
		case IDC_BUTTON12:
			objQC->Inverse_A();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON13:
			objQC->Inverse_B();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON14:
			objQC->Multiply_A_byT();
			setQresult(_hwnd);
			break;
		case IDC_BUTTON15:
			objQC->Multiply_B_byT();
			setQresult(_hwnd);
			break;

		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK SLERPDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

						 // First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Calculator",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 100,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, (DLGPROC)MatrixDlgProc);
	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, (DLGPROC)TransformationDlgProc);
	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, (DLGPROC)GaussianDlgProc);
	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, (DLGPROC)QuaternionDlgProc);
	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, (DLGPROC)SLERPDlgProc);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT) {
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}

