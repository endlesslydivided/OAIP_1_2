#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_5000 5000

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

using namespace std;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
int* MAX_MASSIVA(int size);
int* ELEMENTS_TRASFER_A_B(int* A, int size);

void BIGGEST_SMALLEST(int *B,int size_b);

void PRINT_MASSIVE(int* MASSIVE, int size);

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

int size_b = 0;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
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
		cout << "2 - Заполнить массив B элементами массива А" << endl;
		cout << "3 - Поиск максимального и минимального элементов массива B" << endl;
		cout << "4 - Вывод массива А" << endl;
		cout << "5 - Вывод массива В" << endl;
		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Введите количество элементов массива:"; cin >> size; control = 0; A = MAX_MASSIVA(size); control = 1; break;

		case 2: if (size != 0) { B = ELEMENTS_TRASFER_A_B(A, size); control = 2; }
			  else cout << "Проинициализируйте массив A!" << endl; break;

		case 3:if (control == 2)
		{
			BIGGEST_SMALLEST(B, size_b);
		}
			  else
			cout << "Массив B не объявлен!" << endl;
			break;

		case 4:if (control >= 1)PRINT_MASSIVE(A, size);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 5:if (control == 2)PRINT_MASSIVE(B, size_b);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 0:exit(0); break;

		default:cout << "Введена неверная команда!" << endl; break;
		}

	} while (choice != 0);
	return 0;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

int* MAX_MASSIVA(int size)
{
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		*(mas + iter) = 10000 + rand() % (size * 50);
	}
	return  mas;
}

int* ELEMENTS_TRASFER_A_B(int* A, int size)
{
	size_b = 0;
	int l = 0;
	int* mas = new int[size];
	for (int iter = 0; iter < size; iter++)
	{
		mas[size_b++] = A[iter];
	}
	return mas;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	void BIGGEST_SMALLEST(int* B, int size_b)
	{
		int max = 0, min = 999999999, iter_max = 0, iter_min = 0;
		for (int iter = 0; iter < size_b; iter++)
		{
			if (B[iter] > max)
			{
				max = B[iter];
				iter_max = iter;
			}
			if (B[iter] < min)
			{
				min = B[iter];
				iter_min = iter;
			}
		}
		cout << "Минимальный элемент массива: " << min << " Его порядковый номер в массиве: " << iter_min + 1 << endl;
		cout << "Максимальный элемент массива: " << max << " Его порядковый номер в массиве: " << iter_max + 1 << endl;
	}
	//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
	void PRINT_MASSIVE(int* MASSIVE, int size)
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