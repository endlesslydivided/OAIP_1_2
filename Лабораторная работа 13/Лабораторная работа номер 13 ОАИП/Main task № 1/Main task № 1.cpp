﻿//Заполнить массив С элементами массива А больше максимального элемента массива B
#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_1000 1000
#define MAX_2000 2000
#define MAX_3000 3000
#define MAX_4000 4000
#define MAX_5000 5000

using namespace std;

int* MAX_MASSIVA(int size);
int* MAX_MASSIVB(int size);
int MAX_ELEMENT_B(int* B, int size);
int* TRANSFER_BIGGER_MAX_A_TO_C(int max, int* A, int size);
void BUBBLE_DISCENDING(int* C);
void PRINT(int* MASSIVE, int size);
void insertSort(int* A);

int size_c = 0;

int main()
{
	int max = 0; int control = 0; int size = 0;
	int* C = new int[MAX_5000]; int* A = new int[MAX_5000], * B = new int[MAX_5000];
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int choice = 0;
	do
	{
		printf("\nВыберите необходимый пункт:\n");
		cout << "1 - Заполнить массив A и B n-значениями" << endl;
		cout << "2 - Найти максимальный элемент  массива B " << endl;
		cout << "3 - Заполнить массив С элементами массива А больше максимального элемента массива B" << endl;
		cout << "4 - Сортировка массива С пузырьком по убыванию" << endl;
		cout << "5 - Сортировка массива С простой вставкой по убыванию" << endl;
		cout << "6 - Вывод массива А" << endl;
		cout << "7 - Вывод массива В" << endl;
		cout << "8- Вывод массива С" << endl;
		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Введите количество элементов массива:"; cin >> size; max = 0; control = 0; A = MAX_MASSIVA(size); B = MAX_MASSIVB(size); control = 1; break;
		case 2: if (size != 0)max = MAX_ELEMENT_B(B, size); else cout << "Проинициализируйте массив В" << endl; break;
		case 3:
			if (max != 0)
			{
				size_c = 0; C = TRANSFER_BIGGER_MAX_A_TO_C(max, A, size); control = 2;
			}
			else
				cout << "Не найдено максимальное значение массива B! " << endl;
			break;

		case 4:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			BUBBLE_DISCENDING(C);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;

		}
			  else
			cout << "Массив С не объявлен!" << endl;
			break;
		case 5:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			insertSort(C);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
		}
			  else
			cout << "Массив С не объявлен!" << endl;
			break;

		case 6:if (control >= 1)PRINT(A, size);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 7:if (control >= 1)PRINT(B, size);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 8:if (control == 2)PRINT(C, size_c);
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
		*(mas +iter) = 10000 + rand() % (size * 50);
	}
	return  mas;
}
int* MAX_MASSIVB(int size)
{
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		*(mas + iter) = 1 + rand() % (size * 2);
	}
	return  mas;
}

int MAX_ELEMENT_B(int* B, int size)
{
	int max = 0;
	for (int iter = 0; iter < size; iter++)
	{
		if (max < B[iter]) max = B[iter];
	}
	return max;
}

int* TRANSFER_BIGGER_MAX_A_TO_C(int max, int* A, int size)
{
	size_c = 0;
	int l = 0;
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		if (A[iter] > max)mas[size_c++] = A[iter];
	}
	return mas;
}

void BUBBLE_DISCENDING(int* C)
{
	int i, j, t;
	for (i = 1; i < size_c; i++)
		for (j = size_c - 1; j >= i; j--)
			if (C[j - 1] < C[j])
			{
				t = C[j - 1];
				C[j - 1] = C[j];
				C[j] = t;
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

void insertSort(int* A)
{
	int t, i, j;
	for (i = 1; i < size_c; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] < t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
}
