// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Source.h"
using namespace std;

int main() {
	double b, x, c;
	cout << "Введите b" << endl;
	cin >> b;
	cout << "Введите x" << endl;
	cin >> x;
	cout << "Введите c" << endl;
	cin >> c;
	cout << " z = " << Funcs::MyFunc::func(b,x,c) << endl;
	return 0;
}

