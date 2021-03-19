 #include <iomanip>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
int* negative(int*, int, int);
int main()
{
	srand(time(0));
	int  stl = 0, n;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите размерность одномерного массива: "); cin >> n; cout << endl;
	int* MASSIV = new int[n];
	for (stl = 0; stl < n; stl++)
	{
		*(MASSIV + stl) = -5 + rand() % 10;
	}

	printf("Изначальный массив:\n");
	for (stl = 0; stl < n; stl++)
	{
		cout << *(MASSIV + stl) << "  ";
	}
	cout << endl;
	int* colvomin;
	colvomin = negative(MASSIV, n, stl);
	printf("Разность максимального и минимального элементов массива равна: %i\n", *colvomin);
}

int* negative(int* x, int n, int stl)
{
	int* negative = new int;
	int* positive = new int;
	int* minus = new int;
	*(negative) = 0;
	*(positive) = 0;
	for (stl = 0; stl < n; stl++)
	{
		if (*(x + stl) <= *(negative))
		{
			*(negative) = *(x + stl);
		}
		if (*(x + stl) >= *(positive))
		{
			*(positive) = *(x + stl);
		}
	}
	printf("Минимальный элемент массива: %i\n", *negative);
	printf("Максимальный элемент массива: %i\n", *positive);
	*minus = *positive - *negative;
	return minus;
	delete negative;
	delete positive;
	delete minus;
}