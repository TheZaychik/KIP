// PR3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void zad1() {
	unsigned char a = 138;
	unsigned char d, c;
	_asm {
		mov a, d
		mov a, c
		SHL d, 2
		SHR d, 2
		SAL c, 2
		SAR c, 2
	}
	cout << "Беззнаковое исходное число";
	printf("\n%i", a);
	print("\nБеззнаковое число после лог сдвигов")
	cout << endl;
}

int main()
{	
	setlocale(LC_ALL, "ru");
	zad1();
	system("pause");
    return 0;
}

