#include "stdafx.h"
#include <iostream>
using namespace System;
using namespace std;

void zad3() {

}

void zad1() {
	unsigned char a = 139, b, c, d;
	_asm {
		mov bl, a
		mov cl, a
		shr bl, 4
		shl bl, 3
		shl cl, 5
		shr cl, 4
		inc cl
		mov b, bl
		mov c, cl
		add bl, cl
		mov d, bl
	}
	printf("Исходное число : %i\n", a);
	printf("Первые 4 бита : %i\n", b);
	printf("Последние 4 бита : %i\n", c);
	printf("Число 'наизнанку' : %i\n", d);
}

int main(){
	setlocale(LC_ALL, "rus");
	zad1();
	system("pause");
    return 0;
}
