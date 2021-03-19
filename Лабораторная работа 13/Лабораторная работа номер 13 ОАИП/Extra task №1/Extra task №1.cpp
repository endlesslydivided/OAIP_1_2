//Заполнить массив С элементами массива А больше минимального элемента массива B"

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
int MIN_ELEMENT_B(int* B, int size);
int* TRANSFER_BIGGER_MAX_A_TO_C(int min, int* A, int size);
void ShakerSort(int* a);
void PRINT(int* MASSIVE, int size);
int getHoarBorder(int A[], int sm, int em);
void  sortHoar(int* A, int sm, int em);

int size_c = 0;

int main()
{
	int min = 0; int control = 0; int size = 0;
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
		cout << "2 - Найти минимальный элемент  массива B " << endl;
		cout << "3 - Заполнить массив С элементами массива А больше минимального элемента массива B" << endl;
		cout << "4 - Сортировка массива С 'шейкерной сортировкой' по убыванию" << endl;
		cout << "5 - Сортировка массива С сортировкой Хоара по убыванию" << endl;
		cout << "6 - Вывод массива А" << endl;
		cout << "7 - Вывод массива В" << endl;
		cout << "8- Вывод массива С" << endl;
		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Введите количество элементов массива:"; cin >> size; min = 0; control = 0; A = MAX_MASSIVA(size); B = MAX_MASSIVB(size); control = 1; break;
		case 2: if (size != 0)min = MIN_ELEMENT_B(B, size); else cout << "Проинициализируйте массив В" << endl; break;
		case 3:
			if (min != 0)
			{
				size_c = 0; C = TRANSFER_BIGGER_MAX_A_TO_C(min, A, size); control = 2;
			}
			else
				cout << "Не найдено максимальное значение массива B! " << endl;
			break;

		case 4:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			ShakerSort(C);
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
			sortHoar(C,0,size_c);
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
		*(mas + iter) = 10000 + rand() % (size * 50);
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
int MIN_ELEMENT_B(int* B, int size)
{
	int min = 9999999;
	for (int iter = 0; iter < size; iter++)
	{
		if (min > B[iter]) min = B[iter];
	}
	return min;
}
int* TRANSFER_BIGGER_MAX_A_TO_C(int min, int* A, int size)
{
	size_c = 0;
	int l = 0;
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		if (A[iter] > min)mas[size_c++] = A[iter];
	}
	return mas;
}

void ShakerSort(int* a)
{
	int left, right, i;
	left = 0;
	right = size_c - 1;
	while (left <= right) {
		for (i = right; i >= left; i--) {
			if (a[i - 1] < a[i]) {
				swap(a[i - 1], a[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (a[i - 1] < a[i]) {
				swap(a[i - 1], a[i]);
			}
		}
		right--;
	}
}
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
void sortHoar(int* A, int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
};



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
