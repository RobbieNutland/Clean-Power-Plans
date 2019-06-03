// Clean Power Plans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void ReplaceDefaultSchemes() {

	typedef DWORD(WINAPI *PowerReplaceDefaultPowerSchemes)();

	PowerReplaceDefaultPowerSchemes PowerFunc;

	HMODULE dll = LoadLibraryA("POWRPROF.DLL");
	if (NULL != dll) {
		PowerFunc = (PowerReplaceDefaultPowerSchemes)GetProcAddress(dll, "PowerReplaceDefaultPowerSchemes");
		if (NULL != PowerFunc) {
			PowerFunc();
		}
		else {
			cout << "I can't load this function";
		}
	}
	else {
		cout << "I can't load this dll file";
	}
}

int main()
{
	ReplaceDefaultSchemes();
	return 0;
}