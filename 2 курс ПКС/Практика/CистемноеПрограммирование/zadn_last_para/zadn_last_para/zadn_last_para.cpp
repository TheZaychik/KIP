#include "stdafx.h"
#include <random>
#include <time.h>
using namespace System;

int main()
{
	srand(time(NULL));
	unsigned char mas[2][4], sum1 = 0, sum2 = 0;
	mas[0][0] = 1;
	mas[0][1] = 5;
	mas[0][2] = 8;
	mas[0][3] = 9;
	mas[1][0] = 7;
	mas[1][1] = 2;
	mas[1][2] = 1;
	mas[1][3] = 3;
	_asm {
		lea esi, mas
		mov cl, 0
	cyc1:
		cmp cl, 4
		je u1
		mov al, [esi]
		add sum1, al
		add esi, 1
		add cl, 1
		jmp cyc1

	u1:
		mov cl, 0
	cyc2:
		cmp cl, 4
		je edf
		mov al, [esi]
		add sum2, al
		add esi, 1
		add cl, 1
		jmp cyc2
	edf:	
	}
	printf("sum1 = %i\n", sum1);
	printf("sum2 = %i\n", sum2);
	system("pause");
    return 0;
}
