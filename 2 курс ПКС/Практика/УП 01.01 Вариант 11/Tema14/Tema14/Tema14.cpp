#include "stdafx.h"  // Больше внешних зависимостей богу внешних зависимотсей! 
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <random>
#include <time.h>
using namespace System;
using namespace std;

double mas[100][100];
int n, m;

void zad1() {
	int kol1 = 0, sum1 = 0, kol2 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if ((j < i) && (mas[i][j] < 0)) {
				sum1 += mas[i][j];
				kol1++;
			}
			else {
				sum2 += mas[i][j];
				kol2++;
			}
		}
	}
	cout << "Cреднее арифметическое отрицательных элементов матрицы, лежащей ниже главной диагонали: " << (sum1 / kol1) << endl;
	cout << "Cреднее арифметическое всех элементов главной диагонали: " << (sum2 / kol2) << endl;
}
void zad2() {
	int pos1[7], pos2[7];
	double max = -30000, mi, mj;
	srand(time(NULL));
	for (int i = 0; i < 7; i++) {
		pos1[i] = -20 + rand() % 45;
		pos2[i] = -20 + rand() % 45;
		cout << pos1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 7; i++)
		cout << pos2[i] << " ";
	cout << endl;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++) {
			if (pos1[i] / (pos2[j] + pos1[i] * pos1[i]) > max) {
				max = pos1[i] / (pos2[j] + pos1[i] * pos1[i]);
				mi = i;
				mj = j;
			}
		}
	cout << "При i = " << mi << " и j = " << mj << " максимально значение = " << max << endl;
}
void viv_mas() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

void vvod_manual() { // input from keyboard
	Console::Clear();
	cout << "Введите размер массива NxM" << endl;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mas[i][j];
	viv_mas();
}

void vvod_rnd() {  // random input
	Console::Clear();
	cout << "Введите размер массива NxM" << endl;
	cin >> n >> m;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mas[i][j] = -20 + rand() % 45;
	viv_mas();
}

void vvod_file() {
	Console::Clear();
	cout << "Введите размер массива NxM" << endl;
	cin >> n >> m;
	string line;
	ifstream file("mas_input.txt", ios::in);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 0; j++) {
			getline(file, line);
			mas[i][j] = atoi(line.c_str());
		}
	viv_mas();
}

int main() {
	setlocale(LC_ALL, "Russian");
	int y, code;
	COORD position;                                   
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	position.X = 5;                                
	position.Y = 1;                                
	SetConsoleCursorPosition(hConsole, position); 
	puts("Создание массива");                              

	position.X = 3;                           
	position.Y = 2;                                
	SetConsoleCursorPosition(hConsole, position);    
	puts("1.Ввод рандомный ");

	position.Y = 3;                                
	SetConsoleCursorPosition(hConsole, position);       
	puts("2.Ввод с клавиатуры");

	position.Y = 4;                            
	SetConsoleCursorPosition(hConsole, position);     
	puts("3.Ввод с файла");

	position.Y = 5;                               
	SetConsoleCursorPosition(hConsole, position);    
	puts("4.Выход");
	position.X = 1;
	do
	{
		y = _getch();
		code = static_cast<int>(y);
		SetConsoleCursorPosition(hConsole, position);
		puts(" ");
		switch (code) {
		case 72: if (position.Y > 2) position.Y--;
			SetConsoleCursorPosition(hConsole, position);
			puts(">");
			break;
		case 80: if (position.Y < 6) position.Y++;
			SetConsoleCursorPosition(hConsole, position);
			puts(">");
			break;
		}
	} while (code != 13);
	switch (position.Y) {
	case 2:
		vvod_rnd();
		break;
	case 3: vvod_manual();
		break;
	case 4: vvod_file();
		break;
	case 5: exit(0);
		break;
	}
	cout << "Выберите задание:" << endl;
	cout << "1 - Задание 1, 2 - Задание 2" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1: zad1();
		break;
	case 2: zad2();
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}


