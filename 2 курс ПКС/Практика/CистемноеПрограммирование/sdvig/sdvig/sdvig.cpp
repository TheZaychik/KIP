// sdvig.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>;
using namespace std;

void SHR() {
	short a;
	cin >> a;
	_asm {
		mov ax, a;
		shr ax, 1;
		mov a, ax;
	}
	cout << a << endl;
}

void SHL() {
	short a;
	cin >> a;
	_asm {
		mov ax, a;
		shl ax, 1;
		mov a, ax;
	}
	cout << a << endl;
}

void SHR_Char() {
	char a;
	cin >> a;
	_asm {
		mov al, a;
		shl al, 1;
		mov a, al;
	}
	cout << a << endl;
}

int main()
{
	SHR_Char();
	system("pause");
    return 0;
}

