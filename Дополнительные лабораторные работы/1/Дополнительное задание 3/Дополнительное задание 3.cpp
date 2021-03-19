#include <iomanip>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
int* summa(int*, int, int);
int main()
{
	srand(time(0));
	int  stl = 0, n = 15;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int* MASSIV = new int[n];
	for (stl = 0; stl < n; stl++)
	{
		*(MASSIV + stl) = 1 + rand() % 200;
	}

	printf("Изначальный массив:\n");
	for (stl = 0; stl < n; stl++)
	{
		cout << *(MASSIV + stl) << "  ";
	}
	cout << endl;
	int* sum;
	sum= summa(MASSIV, n, stl);
	printf("Сумма нечётных элементов массива %i\n", *sum);
}

int* summa(int* x, int n, int stl)
{
	int* sum = new int;
	*sum = 0;
	for (stl = 0; stl < n; stl++)
	{
		if (*(x + stl) % 2 != 0)
		{
			*sum += *(x + stl);
		}
	}

	return sum;
	delete sum;
}