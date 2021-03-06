// Tema16.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"  // Больше внешних зависимостей богу внешних зависимотсей! 
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <random>
#include <time.h>
#include <iomanip>
using namespace System;
using namespace std;

double mas[100][100];
int n, m;
string menu[] = { "Меню создания массива:", "Рандомный", "Ручной", "Из файла", "ВЫХОД" };
string menu1[] = { "Меню задач:", "Задача 1", "Назад" };
int code, l, l1;

COORD position;										// Объявление необходимой структуры
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода

int print_menu(string menu[], int l)
{
	char ch;
	int i, m;
	system("cls");
	position.X = 5;										// Установка координаты X
	position.Y = 1;										// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
	cout << menu[0];										// Вывод сообщения
	position.X = 3;

	for (i = 1; i <l; i++)
	{
		position.Y = i + 1;
		SetConsoleCursorPosition(hConsole, position);
		cout << menu[i];
	}
	position.X = 2;
	do
	{
		ch = _getch();
		code = static_cast<int>(ch);
		SetConsoleCursorPosition(hConsole, position);
		puts(" ");
		switch (code) {
		case 80: if (position.Y<l) position.Y++;
				 else position.Y = 2;
				 SetConsoleCursorPosition(hConsole, position);
				 puts(">");
				 break;
		case 72: if (position.Y>2) position.Y--;
				 else position.Y = l;
				 SetConsoleCursorPosition(hConsole, position);
				 puts(">");
				 break;
		}
	} while (code != 13);
	return position.Y;
}

void viv_mas() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

void vvod_manual() { // input from keyboard
	system("cls");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mas[i][j];
	viv_mas();
}

void vvod_rnd() {  // random input
	system("cls");
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mas[i][j] = -10 + rand() % 45;
	viv_mas();
}

void vvod_file() {
	system("cls");
	string line;
	ifstream file("mas_input.txt", ios::in);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 0; j++) {
			getline(file, line);
			mas[i][j] = atoi(line.c_str());
		}
	viv_mas();
}
void menu_2(); // объявлем заранее тк меню1 ссылается на меню2
void menu_1() {
	l = print_menu(menu, 5);
	switch (l)
	{
	case 2: vvod_rnd();
		break;
	case 3: vvod_manual();
		break;
	case 4: vvod_file();
		break;
	case 5:
		exit(0);

		break;
	default:
		break;
	}
	menu_2();
}
bool check_sign(int a, int b, int c) {
	if (a >= 0)
		if (b >= 0)
			if (c >= 0)
				return true;
			else
				return false;
		else
			return false;
	else if (a < 0)
			if (b < 0)
				if (c < 0)
					return true;
				else
					return false;
			else
				return false;
}

void zad1() {
	system("cls");
	cout << "Данные задачи:" << endl;
	viv_mas();
	cout << "----------------" << endl;
	cout << "_____________________________" << endl;
	cout << "|  NS  |     1|     2|     3|" << endl;
	cout << "|------|------|------|------|" << endl;
	for (int i = 0; i < n; i++) {
		if (!check_sign(mas[i][0], mas[i][1], mas[i][2]))
		{
			//cout.width(6);
			cout.setf(ios::right);
			cout << "|" << setw(6) << i << "|";
			cout << setw(6) << mas[i][0] << "|";
			cout << setw(6) << mas[i][1] << "|";
			cout << setw(6) << mas[i][2] << "|\n";
		}
			//cout << setw(29) << "|" << i << "|" << mas[i][0] << "|" << mas[i][1] << "|" << mas[i][2] << "|" << endl;
			//printf("|     %-u|      %u|      %-u|      %u|\n", i, mas[i][0], mas[i][1], mas[i][2]);
	}	
	cout << "|______|______|______|______|" << endl;
}

void menu_2() {
	l1 = print_menu(menu1, 3);
	switch (l1)
	{
	case 2: zad1();
		break;
	case 3: menu_1();
		break;
	default:
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер массива NxM" << endl;
	cin >> n >> m;
	menu_1();
	system("pause");
	return 0;
}
