#include "stdafx.h"
#include <iostream>
using namespace System;
using namespace std;

short f(short a, short b, short c) {
	return (a+b*c);
}

void zad1() {
	short a = 301, b = 302, c = 303;
	int ch1, zn;
	cout << f(301, 302, 303) << endl;
	_asm {
		mov ax, b
		mov bx, c
		mul bx
		add eax, a
		mov ebx, eax
		mov ax, a
		mov bx, b
		mul bx
		mov zn, eax
		mov eax, ebx
		mov ch1, eax
	}
	cout << ch1 << endl;
	cout << zn << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	zad1();
    return 0;
}
