#include <iomanip>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
int *negative(int*, int,int);
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
	printf("Количество отрицательных элементов, стоящих на чётных местах, в одномерном массиве равно: %i\n", *colvomin);
	
}

int *negative(int* x, int n, int stl)
{
	int* negative_counter = new int;
	*(negative_counter) = 0;
		for (stl = 0; stl < n; stl++)
		{
			if (*(x + stl) < 0 && stl % 2 != 0)
			{
				(*(negative_counter))++;
			}
		}
	
return negative_counter;
delete negative_counter;
}