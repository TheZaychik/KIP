#include "stdafx.h"
#include <iostream>

using namespace System;
using namespace std;


int main()
{
	char ots[21] = { 4, 4, 5, 2, 3, 5, 4, 5, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 5, 4, 4 }, r = 20, sr = 0, sum = 0;
	char o2 = 0, o3 = 0, o4 = 0, o5 = 0;
	_asm {
		lea esi, ots
		mov cl, 0

	cyc:
		cmp cl, 21
		je endf
		mov al, [esi]
		add esi, 1
		inc cl
		add sum, al
		cmp al, 5
		je five
		cmp al, 4
		je four
		cmp al, 3
		je three
	    cmp al, 2
	    je two

	five:
		inc o5
		jmp cyc

	four:
		inc o4
		jmp cyc

	three:
		inc o3
		jmp cyc

	two:
		inc o2
		jmp cyc

	endf:
	}
    return 0;
}
