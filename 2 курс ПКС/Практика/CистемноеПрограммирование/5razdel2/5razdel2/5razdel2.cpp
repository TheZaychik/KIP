// 5razdel2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

void del5_2() {
	unsigned short a = 5;
	unsigned char b = 2, otv, ost;
	_asm {
		mov ax, a
		div b
		mov otv, al
		mov ost, ah
	}
	printf("%i\n", otv);
	printf("%i\n", ost);
}

void del70k_300() {
	int a = 70000;
	unsigned short b = 300, del, ost;
	_asm {
		mov eax, a
		mov edx, a
		shr edx, 16
		div b
		mov del, ax
		mov ost, dx
	}
	printf("%i\n", del);
	printf("%i\n", ost);
}

int main(){
	setlocale(LC_ALL, "rus");
	del70k_300();
	system("pause");
	return 0;
}

