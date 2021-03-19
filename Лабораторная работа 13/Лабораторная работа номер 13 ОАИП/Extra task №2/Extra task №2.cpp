//Заполнить массив С элементами массива А больше максимального элемента массива B
#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_5000 5000

using namespace std;

int* MAX_MASSIVA(int size);
int* ODD_ELEMENTS_TRASFER_A_B(int* A, int size);
void shellsort(int x[], int n);
void PRINT(int* MASSIVE, int size);
void selectSort(int A[], int size);

int size_b = 0;

int main()
{
	int control = 0; int size = 0;
	int* A = new int[MAX_5000], * B = new int[MAX_5000];
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int choice = 0;
	do
	{
		printf("\nВыберите необходимый пункт:\n");
		cout << "1 - Заполнить массив A n-значениями" << endl;
		cout << "2 - Заполнить массив B чётными элементами массива А " << endl;
		cout << "3 - Сортировка массива B сортировкой Шелла по убыванию" << endl;
		cout << "4 - Сортировка массива B выбором по убыванию" << endl;
		cout << "5 - Вывод массива А" << endl;
		cout << "6 - Вывод массива В" << endl;
		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Введите количество элементов массива:"; cin >> size;control = 0; A = MAX_MASSIVA(size);control = 1; break;
		case 2: if (size != 0) { B = ODD_ELEMENTS_TRASFER_A_B(A, size); control = 2; }
			  else cout << "Проинициализируйте массив A!" << endl; break;
		case 3:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			shellsort(B,size_b);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;

		}
			  else
			cout << "Массив С не объявлен!" << endl;
			break;
		case 4:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			selectSort(B, size_b);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
		}
			  else
			cout << "Массив B не объявлен!" << endl;
			break;

		case 5:if (control >= 1)PRINT(A, size);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 6:if (control >= 1)PRINT(B, size_b);
			  else
			cout << "Массив не объявлен!" << endl;
			break;
		case 0:exit(0); break;
		default:cout << "Введена неверная команда!" << endl; break;
		}

	} while (choice != 0);
	return 0;
}

int* MAX_MASSIVA(int size)
{
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		*(mas + iter) = 10000 + rand() % (size * 50);
	}
	return  mas;
}

int* ODD_ELEMENTS_TRASFER_A_B(int* A, int size)
{
	size_b = 0;
	int l = 0;
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		if ( A[iter]% 2 == 0)mas[size_b++] = A[iter];
	}
	return mas;
}

void shellsort(int x[], int n)         //SHELL SORT - SHELL'S INCREMENTS
{
	int i, j, k, increment, temp;
	int swp = 0, comp = 0; increment = n / 2;
	while (increment > 0)
	{
		for (i = 0; i < increment; i++)
		{
			for (j = 0; j < n; j += increment)
			{
				temp = x[j];
				for (k = j - increment; k >= 0 && temp < x[k]; k -= increment)
				{
					comp++;
					swp++;
					x[k + increment] = x[k];
				}
				x[k + increment] = temp;
				swp++;
			}
		}
		comp++;
		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
}
void selectSort(int A[], int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
}

void PRINT(int* MASSIVE, int size)
{
	int space = 0;
	for (int iter = 0; iter < size; iter++)
	{
		cout.width(5);
		cout << MASSIVE[iter] << "  ";
		space++;
		if (space == 20)
		{
			printf("\n");
			space = 0;
		}
	}
	printf("\n");
}