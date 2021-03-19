#include <iomanip>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
#define cnstn 100
int** minstrokastolb(int**, int, int, int);
void main()
{
	srand(time(0));
	int str = 0, stl = 0, n;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите размерность двухмерного массива: "); cin >> n; cout << endl;
	int** MASSIV = new int* [n];
	for (str = 0; str < n; str++)
	{
		MASSIV[str] = new int[n];
	}
	for (str = 0; str < n; str++)
	{
		for (stl = 0; stl < n; stl++)
		{
			*(*(MASSIV + str) + stl) = -1 + rand() % 10;
		}
	}
	printf("Изначальный массив:\n");
	for (str = 0; str < n; str++)
	{
		cout << endl;
		for (stl = 0; stl < n; stl++)
		{
			cout << *(*(MASSIV + str) + stl) << "\t";
		}
	}
	cout << endl;
	MASSIV = minstrokastolb(MASSIV, n, str, stl);
	printf("Итоговый массив:\n");
	for (str = 0; str < n; str++)
	{
		cout << endl;
		for (stl = 0; stl < n; stl++)
		{
			cout << *(*(MASSIV + str) + stl) << "\t";
		}
	}
}

int** minstrokastolb(int** x, int n, int str, int stl)
{
	for (str = 0; str < n; str++)
	{
		for (stl = 0; stl < n; stl++)
		{
			if (*(*(x + str) + stl) < 0)
			{
				stl= str; 
				goto part2;
			}
		}
	}
part2: 

	printf("Первая строка, содержащая отрицательный элемент - %i-я.\nУменьшаем содержимое столбца с номером %i вдвое.\n", stl +1, stl + 1);
	for (str = 0; str < n; str++)
	{
		*(*(x + str) + stl) = *(*(x + str) + stl) / 2;
	}
	return x;
}