// PR4_Console.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>  
#pragma comment(lib, "Dll_PR4.lib")
using namespace std;

int main() {
	double b, x, c;
	cout << "Введите b" << endl;
	cin >> b;
	cout << "Введите x" << endl;
	cin >> x;
	cout << "Введите c" << endl;
	cin >> c;
	cout << " z = " << func(b,x,c) << endl;
	return 0;
}

