// umnozh_16ss.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

void zad1() {
	unsigned char a = 10, b = 30, d, f;
	short c;
	_asm {
		mov al, a
		mov bl, b
		mul bl
		mov c, ax
		mov d, al
		mov f, ah;
	}
	printf("Число после умножения: %i", d);
	printf("\nЧисло после умножения в 16 с/с %x", d);
	printf("\nЧисло после умножения в 16 с/с al = %x", c);
	printf("\nЧисло после умножения в 16 с/с ah = %x\n", f);
}

void zad2() {
	int a = 10000, b = 30, c;
	_asm {
		mov eax, a
		mov ebx, b
		mul ebx
		mov c, ebx
	}
	printf("Число после умножения: %i\n", c);
}

int main(){
	setlocale(LC_ALL, "rus");
	zad2();
	system("pause");
    return 0;
}

