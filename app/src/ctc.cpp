#include "stdafx.h"

#include <iostream>
#include <windows.h>

using namespace std;


namespace {
	const char* spaces = " \t";
	const char* digits = "0123456789";
}
HANDLE hCon;


void SetColor(int background,int foreground){
	

	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_attribute;
	color_attribute = background;
	color_attribute = _rotl(color_attribute, 4) | foreground;
	SetConsoleTextAttribute(hCon, color_attribute);
}

