#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

int main()  // все что будет в скобочках мэина - удаляем
{
	int a, b, c;
	cin >> a >> b;
	TestClassLib1::Class1 ab1;
	c = ab1.method1(a, b);
	cout << "-----\n" << c;
	cin >> c;
    return 0;
}
