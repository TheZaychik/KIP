// ab_para.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h";
#include  <iostream>;
using namespace std;
void func1() {
	signed char a, b, c, d, e, f;
	a = 5;
	b = 7;
	_asm {
		mov al, a;
		mov bl, b;
		not al;
		mov c, al;
		and al, bl;
		mov d, al;
		or al, bl;
		mov e, al;
		xor al, bl;
		mov f, al;
	}
	printf("\n%i", c);
	printf("\n%i", d);
	printf("\n%i", e);
	printf("\n%i", f);
	cout << endl;
}

void zad6() {
	unsigned char a, b, sum;
	a = 139;
	b = 151;
	_asm {
		mov al, a
		mov bl, b
		not al
		not bl
		mov a, al
		mov b, bl
	}
	printf("\n%i", a);
	printf("\n%i", b);
	cout << endl;
}
void zad5() {
	unsigned char a, b, sum;
	a = 139;
	b = 151;
	_asm {
		mov al, a
		xor al, b
		mov sum, al
	}
	printf("\n%i", a);
	printf("\n%i", b);
	printf("\n%i", sum);
	cout << endl;
}
void zad4() {
	unsigned char a, b, sum;
	a = 139;
	b = 151;
	_asm {
		mov al, a
		or al, b
		mov sum, al
	}
	printf("\n%i", a);
	printf("\n%i", b);
	printf("\n%i", sum);
	cout << endl;
}
void zad3() {
	unsigned char a, b, sum;
	a = 139;
	b = 151;
	_asm {
		mov al, a
		and al, b
		mov sum, al
	}
	printf("\n%i", a);
	printf("\n%i", b);
	printf("\n%i", sum);
	cout << endl;
}
void zad2() {
	signed char a, b, sum;
	a = 139;
	b = 151;
	_asm {
		mov al, a
		add al, b
		mov sum, al
	}
	printf("\n%i", a);
	printf("\n%i", b);
	printf("\n%i", sum);
	cout << endl;
}
void zad1() {
	unsigned char a, b, sum;
	a = 139;
	b = 151;
	_asm {
		mov al, a
		add al, b
		mov sum, al
	}
	printf("\n%i", a);
	printf("\n%i", b);
	printf("\n%i", sum);
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 1";
	zad1();
	cout << "Задание 2";
	zad2();
	cout << "Задание 3";
	zad3();
	cout << "Задание 4";
	zad4();
	cout << "Задание 5";
	zad5();
	cout << "Задание 6";
	zad6();
	system("pause");
	return 0;
}

