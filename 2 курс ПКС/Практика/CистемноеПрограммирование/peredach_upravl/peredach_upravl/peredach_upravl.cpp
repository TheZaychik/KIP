// peredach_upravl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned char a = 7, b=7, c, d;
	_asm {
		mov al, a
		add al, b
		jc error1
		cont:
		mov c, al
		shl al, 2
		jc error2
		mov d, al
		jmp end
	

		error1:
		mov c, 0
		jmp cont

		error2:
		mov d, 1
		jmp end

		end:
	}

	printf("a = %i\n", a);
	printf("b = %i\n", b);
	printf("c = %i\n", c);
	printf("d = %i\n", d);
	system("pause");
	return 0;
}

