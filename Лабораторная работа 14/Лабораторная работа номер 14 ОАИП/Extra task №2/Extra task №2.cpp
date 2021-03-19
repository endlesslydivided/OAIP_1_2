#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_5000 5000

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

using namespace std;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
int* MAX_MASSIVA(int size);
int* ELEMENTS_TRASFER_A_B(int* A, int size);

void insertSort_ASCENDING_number_DISCENDING_number(int* A, int siz, int start, int finish);

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
		cout << "3 - Сортировка по возрастанию n элементов с начала и по убыванию k элементов с конца" << endl;
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
			int start, finish;
			do {
				cout << "Введите количество элементов c начала массива,которые надо отсортировать по возрастанию(меньше половины массива) :"; cin >> start;
			} while (start > size_b / 2 || start < 0);
			do {
			cout << "Введите количество элементов c конца массива,которые надо отсортировать по убыванию(меньше половины массива) :"; cin >> finish;
		    } while (finish > size_b / 2 || start < 0);
			insertSort_ASCENDING_number_DISCENDING_number(B, size_b,start,finish);
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

void insertSort_ASCENDING_number_DISCENDING_number(int* A, int siz,int start,int finish)
{
	int t, i, j;
	for (i = 1; i < siz; i++)
	{
		if (i < start)
		{
			t = A[i];
			for (j = i - 1; j >= 0 && A[j] > t; j--)
				A[j + 1] = A[j];
			A[j + 1] = t;
		}
		if (i > siz - finish)
		{
			t = A[i];
			for (j = i - 1; j >= 0 && A[j] < t; j--)
				A[j + 1] = A[j];
			A[j + 1] = t;
		}
	}
}
//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
void PRINT_MASSIVE(int* MASSIVE, int size)
{
	int space=0;
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