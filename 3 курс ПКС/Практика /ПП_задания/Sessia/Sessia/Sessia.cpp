
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

using namespace std;

class WORKER {
public:
	string family, post;
	int year;
	
	void Setup(string _family, string &_post, int _year) {
		family = _family;
		post = _post;
		year = _year;
	}

	void Show() {
		cout << "Фамилия: " << family << endl;
		cout << "Должность: " << post << endl;
		cout << "Год начала работы: " << year << endl;
	}


};
WORKER *mas = new WORKER[2];

void InputFile() {
	string family, post, year;
	fstream f;
	f.open("worker.txt", ios::in);
	if (!f) {
		cout << "Файла не существует!" << endl;
		f.close();
		return;
	}
	for (int i = 0; i < 2; i++) {
		getline(f, family);
		getline(f, post);
		getline(f, year);
		mas[i].Setup(family, post, atoi(year.c_str()));
	}
	f.close();
}

void OutputFile() {
	fstream f;
	f.open("worker.txt", ios::out);
	for (int i = 0; i < 2; i++) {
		f << mas[i].family << endl;
		f << mas[i].post << endl;
		f << mas[i].year << endl;
	}
	f.close();
}

void OutputConsole() {
	for (int i = 0; i < 2; i++) {
		mas[i].Show();
	}
}

void InputConsole() {
	string family, post;
	int year;
	for (int i = 0; i < 2; i++) {
		cout << "Работник №" << i + 1 << endl;
		cout << "Введите фамилию работника:" << endl;
		cin >> family;
		cout << "Введите должность работника:" << endl;
		cin >> post;
		cout << "Введите год начала работы работника:" << endl;
		cin >> year;
		mas[i].Setup(family, post, year);
	}
}

void InputFileC() {
	char *buff = new char[256];
	string family, post;
	int year;
	FILE *f = fopen("worker.txt", "r+");
	int err = fileno(f);
	if (err == -1) {
		cout << "Файла не существует!" << endl;
		delete buff;
		std::fclose(f);
		return;
	}
	for (int i = 0; i < 2; i++) {
		fscanf(f, "%s", buff);
		family = string(buff);
		buff = new char[256];
		fscanf(f, "%s", buff);
		post = string(buff);
		buff = new char[256];
		fscanf(f, "%s", buff);
		year = atoi(buff);
		mas[i].Setup(family, post, year);
	}
	delete buff;
	std::fclose(f);
}

void OutputFileС() {
	FILE *f = fopen("worker.txt", "r+");
	for (int i = 0; i < 2; i++) {
		fprintf(f, "%s\n", mas[i].family.c_str());
		fprintf(f, "%s\n", mas[i].post.c_str());
		fprintf(f, "%d\n", mas[i].year);
	}
	std::fclose(f);
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "1. Ввод данных о работнике с клавиатуры" << endl;
	cout << "2. Ввод данных о работнике из файла worker.txt методом С++" << endl;
	cout << "3. Ввод данных о работнике из файла worker.txt методом С" << endl;
	cout << "4. Запись массива в файл worker.txt методом С++" << endl;
	cout << "5. Запись массива в файл worker.txt методом С" << endl;
	cout << "6. Вывод массива работников" << endl;
	cout << "7. Выход" << endl;
	int sw;
	cin >> sw;
	switch (sw) {
		case 1: 
			InputConsole();
			break;
		
		case 2: 
			InputFile();
			break;
		
		case 3: 
			InputFileC();
			break;
		
		case 4: 
			OutputFile();
			break;

		case 5:
			OutputFileС();
			break;

		case 6:
			OutputConsole();
			break;

		case 7:
			exit(0);

	default: main();
	}
	main();
}

