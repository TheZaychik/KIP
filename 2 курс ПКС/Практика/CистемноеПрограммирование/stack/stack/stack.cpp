#include "stdafx.h"
#include <iostream>
using namespace System;
using namespace std;

int main()
{
	unsigned int a = 1, b = 2, c = 3, d = 4;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "-------" << endl;
	_asm {
		push a
		push b
		push c 
		push d
		pop a 
		pop b
		pop c
		pop d
	}
	//printf("%i\n", a);
	//b = &a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	system("pause");
    return 0;
}
