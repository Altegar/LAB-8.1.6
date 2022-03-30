// LAB-8.1.6.cpp
// Сушинський Ігор
// Лабораторна робота №8.1
// Пошук та заміна символів у літерному рядку.
// Варіант 20
// 2 завдання
// Рекурсивний спосіб

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 2] != 0)
	{
		if (str[i] == ',' && str[i + 2] == '-')
		{
			strcat(t, "**");
			return Change(dest, str, t + 4, i + 3);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	char str[101];

	cout << "Ввести лiтерний рядок:" << endl;
	cin.getline(str, 100);

	char* dest1 = new char[151];
	dest1[0] = '\0';

	char* dest2;

	dest2 = Change(dest1, str, dest1, 0);

	cout << "Модифiкований лiтерний рядок (param) : " << dest1 << endl;
	cout << "Модифiкований лiтерний рядок (result): " << dest2 << endl;

	return 0;
}