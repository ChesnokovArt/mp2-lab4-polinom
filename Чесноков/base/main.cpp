#include "TPolinom.h"
#include <iostream>
using namespace std;

void ReadPolinom(TPolinom& p);
void SortByIndex(int** m, int size);

void main()
{
	setlocale(LC_ALL, "ru");
	TPolinom p, q, res;
	char input;
	while (true)
	{
		start:
		cout << "1) Ввести полином Р" << endl;
		cout << "2) Ввести полином Q" << endl;
		cout << "3) Cложить полиномы" << endl;
		cout << "4) Выйти" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			ReadPolinom(p);
			p.print();
			break;
		case '2':
			ReadPolinom(q);
			q.print();
			break;
		case '3':
			res = (p + q);
			cout << "Результат сложения: ";
			res.print();
			break;
		case '4':
			goto end;
			break;
		default:
			cout << "Неккоректный ввод" << endl;
			goto start;
			break;
		}
	}
	end:
	getchar();
}

void ReadPolinom(TPolinom& p)
{
	int index, size, tmp;
	int** m;
	cout << "Сколько мономов содержит полином?" << endl;
	cin >> size;
	m = new int*[size];
	for (int i = 0; i < size; i++)
	{
		m[i] = new int[2];
		cout << "Коэфициент: ";
		cin >> m[i][0];
		cout << "Cтепень Х: ";
		cin >> index;
		index *= 10;
		cout << "Cтепень У: ";
		cin >> tmp;
		index += tmp;
		index *= 10;
		cout << "Cтепень Z: ";
		cin >> tmp;
		index += tmp;
		m[i][1] = index;
	}
	SortByIndex(m, size);
	p = TPolinom(m, size);
}

void SortByIndex(int ** m, int size)
{
	int buf[2];
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (m[j][1] > m[j - 1][1])
			{
				buf[0] = m[j][0];
				buf[1] = m[j][1];
				m[j][0] = m[j - 1][0];
				m[j][1] = m[j - 1][1];
				m[j - 1][0] = buf[0];
				m[j - 1][1] = buf[1];
			}
		}
	}
}
