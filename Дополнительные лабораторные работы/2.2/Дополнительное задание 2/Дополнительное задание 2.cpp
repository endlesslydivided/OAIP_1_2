#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
using namespace std;
int a, b, c, d, e, f = 0, g = 0, h, i, j, k;
#define constanta 100
int fdtb(int,int n, ...);
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do
	{
		printf("Сколько чисел необходимо перевести из десятичной системы счисления в двоичную?\n");
		printf("1-Одно число \n"); printf("2-Два числа\n"); printf("3-Три числа\n"); printf("4-Четыре числа\n"); printf("0-ВЫХОД\n");
		cin >> a;
		switch (a)
		{
		case 1:
			printf("Введите первое число: "); cin >> b;
			 fdtb(1,b); break;

		case 2:
			printf("Введите первое число: "); cin >> b;
			printf("Введите второе число: "); cin >> c;
			fdtb(2,b, c); break;

		case 3:
			printf("Введите первое число: "); cin >> b;
			printf("Введите второе число: "); cin >> c;
			printf("Введите третье  число: "); cin >> d;
		    fdtb(3, b, c, d); break;

		case 4:
			printf("Введите первое число: "); cin >> b;
			printf("Введите второе число: "); cin >> c;
			printf("Введите третье число: "); cin >> d;
			printf("Введите четвёртое число: "); cin >> e;
		    fdtb(4,b, c, d, e); break;

		case 0:break;
		}
	} while (a != 0);
	
}
int fdtb(int k, int n, ...)
{
	int* p = &n;
	for (f = 0; f < k; f++)
	{
		g = 0;
		int* BINARY = new int[constanta];
		do
		{
			*(BINARY + g++) = *(p + f) % 2;
			*(p + f) = (*(p + f) - (*(p + f) % 2)) / 2;
		} 
		while (*(p + f) != 0);
		g--;
		for (g; g >= 0; g--)
		{
			cout << *(BINARY + g);
		}
		cout << endl;
		delete[] BINARY;
	}
	return 0;
}

