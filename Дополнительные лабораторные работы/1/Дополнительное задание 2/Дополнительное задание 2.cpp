#include <iomanip>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
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
			*(*(MASSIV + str) + stl) = -4 + rand() % 10;
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
	if (*(*(MASSIV + 0) + n - 0) != -100)
	{
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
	else
	{
		printf("Массив не имеет столбцов, в которых отсутствуют отрицательные элементы!\n");
	}
}

int** minstrokastolb(int** x, int n, int str, int stl)
{
	int counter;
	int fixedstl = -2;
	for (stl = 0; stl < n; stl++)
	{
		counter = 0;
		for (str = 0; str < n; str++)
		{
			if (*(*(x + str) + stl) >= 0)
			{
				counter++;
			}
			if (counter == n)
			{
				fixedstl = stl - 1;
				goto part2;
			}
		}
	}
part2:
	if (stl > 0)
	{
		for (str = 0; str < n; str++)
		{
			*(*(x + str) + fixedstl) = -(*(*(x + str) + fixedstl));
		}
	}
	if (fixedstl < 0)
	{
		for (str = 0; str < n; str++)
		{
			*(*(x + str) + n - 1) = -(*(*(x + str) + n - 1));
		}
	}
	if (fixedstl == -2)
	{
		*(*(x + 0) + n - 0) = -100;
	}
	return x;
	
}