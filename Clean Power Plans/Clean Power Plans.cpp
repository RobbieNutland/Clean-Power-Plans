// Clean Power Plans.cpp : Defines the entry point for the console application.

// Replaces the default power schemes with the current user's power schemes.
// 
// Replacing the default schemes enables users to use the Restore Defaults option in the Control Panel Power Options application to restore customized power scheme defaults instead
// of the original Windows power scheme defaults.

// The built executable must be ran as an administrator. Test by running the below from a command prompt: 
//		>	powercfg -restoredefaultschemes

//#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void ReplaceDefaultSchemes() {

	typedef DWORD(WINAPI *PowerReplaceDefaultPowerSchemes)();

	PowerReplaceDefaultPowerSchemes PowerFunc;

	HMODULE dll = LoadLibraryA("PowrProf.dll");
	if (NULL != dll) {
		PowerFunc = (PowerReplaceDefaultPowerSchemes)GetProcAddress(dll, "PowerReplaceDefaultPowerSchemes");
		if (NULL != PowerFunc) {
			if (PowerFunc() == 0) {
				cout << "Successfully replaced the default power schemes with the current user's power schemes." << endl;
			}
			else {
				cout << "Error: Call to the 'PowerReplaceDefaultPowerSchemes' function failed." << endl;
			}
		}
		else {
			cout << "Error: Failed to load 'PowerReplaceDefaultPowerSchemes' function." << endl;
		}
	}
	else {
		cout << "Error: Failed to load 'PowrProf.dll' library." << endl;
	}

	return;
}

int main()
{
	ReplaceDefaultSchemes();
	cout << "Press 'Enter' to exit...";
	cin.get(); //pauses console window

	return 0;
}