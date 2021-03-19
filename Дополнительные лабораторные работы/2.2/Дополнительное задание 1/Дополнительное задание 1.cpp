#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
unsigned int n;
unsigned int k = 0;
int l = 0;
int MM = 0;
#define q 100
int* A = new int[q];
int* B = new int[q];
int* C = new int[q];
int* D = new int[q];
int* E = new int[q];
int* MainMassiv[5] = {A,B,C,D,E};
int minelemenet(int,int,int*, ...);
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите размерность одномерного массива: "); cin >> n;
	int k = 0;
	srand(time(0));
	for (MM; MM < 5; MM++)
	{
		for (k = 0; k < n; k++)
		{
			*(*(MainMassiv + MM) + k) = -4 + rand() % 10;
		}
		printf("Массив №%i: ",MM);
		cout << "\t";
		for (k = 0; k < n; k++)
		{
			cout << *(*(MainMassiv + MM) + k) << "\t";
		}
		cout << endl;
	}
		minelemenet(n,2,A, B);
		minelemenet(n,1, C);
		minelemenet(n,3, B,D,E);
}
int minelemenet(int n,int e,int*P, ... )
{
	printf("Проверенные массивы:\n");
	int** perme = &P;
	int x; int xx;
	int zpP = 0;
	for (xx = 0; xx < e; xx++)
	{
		int zpP = 0;
		int* zeroplace = new int[q];
		for (x = 0; x < n; x++)
		{
			if (*(*(perme + xx) + x) == 0)
			{
				*(zeroplace + zpP++) = x;
			}
		}
		int minuscount = 0;
		for (x = 0; x < n; x++)
		{
			if (*(*(perme + xx) + x) < 0)
			{
				*(*(perme + xx) + x) = 0;
				minuscount++;
			}
		}
		for (x = 0; x < n; x++)
		{
			int search = x;
			if (*(*(perme + xx) + x) == 0)
			{
				while (*(*(perme + xx) + search) == 0)
				{
					search++;
				}
				if (*(*(perme + xx) + search) > 0)
				{
					*(*(perme + xx) + x) = *(*(perme + xx) + search);
					*(*(perme + xx) + search) = 0;
				}
			}
		}
		printf("Итоговый массив №%i: ", xx);
		cout << "\t";
		for (x = 0; x < n; x++)
		{
			cout << *(*(perme + xx) + x) << "\t";
		}
		cout << endl;
	}
	return 0;
}