#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX_5000 5000

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

using namespace std;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
int* MAX_MASSIVA(int size);
int* ELEMENTS_TRASFER_A_B(int* A, int size);

int* countSort_DESCENDING(int *in, int size);

void heapify(int* A, int pos, int n);
void piramSort_DESCENDING(int* A, int n);

void insOrd(int* m, int sm, int em, int e);
int* merge(int* m, int sm, int cm, int em);
void sortMerge_ASCENDING(int* m, int lm, int sm);

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
		cout << "3 - Сортировка массива B подсчётом по убыванию" << endl;
		cout << "4 - Сортировка массива B пирамидальной сортировкой по убыванию " << endl;
		cout << "5 - Сортировка массива B слиянием по возрастанию" << endl;
		cout << "6 - Вывод массива А" << endl;
		cout << "7 - Вывод массива В" << endl;
		cout << "0- Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Введите количество элементов массива:"; cin >> size; control = 0; A = MAX_MASSIVA(size); control = 1; break;

		case 2: if (size != 0) { B = ELEMENTS_TRASFER_A_B(A, size); control = 2; }
			  else cout << "Проинициализируйте массив A!" << endl; break;

		case 3:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			B = countSort_DESCENDING(B,size_b);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;

		}
			  else
			cout << "Массив B не объявлен!" << endl;
			break;

		case 4:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			piramSort_DESCENDING(B,size_b);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;
		}
			  else
			cout << "Массив B не объявлен!" << endl;
			break;

		case 5:if (control == 2)
		{
			time_t t1 = 0, t2 = 0;
			t1 = clock();
			sortMerge_ASCENDING(B, size_b,0);
			t2 = clock();
			cout << "Время сортировки: " << t2 - t1 << endl;

		}
			  else
			cout << "Массив B не объявлен!" << endl;
			break;

		case 6:if (control >= 1)PRINT_MASSIVE(A, size);
			  else
			cout << "Массив не объявлен!" << endl;
			break;

		case 7:if (control == 2)PRINT_MASSIVE(B, size_b);
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

int* countSort_DESCENDING(int* in,int size)
{
	int i, j, count;
	int* mas = new int[size];
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j)
			if (in[j] > in[i] || (in[j] == in[i] && i < j))
				count++;
		mas[count] = in[i];
	}
	return mas;
}


//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

void heapify(int* A, int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] <= A[t])
			t = 2 * pos + 2;
		if (A[pos] > A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort_DESCENDING(int* A, int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}


//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

void insOrd(int* m, int sm, int em, int e)
{ // m[]  массив чисел; sm  индекс 1-ого элемента левой части; cm  индекс
  //последн. элемента левой части; em  индекс последн. элемента правой части
	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int* m, int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
void sortMerge_ASCENDING(int* m, int lm, int sm)
{
	if (lm > 1)
	{
		sortMerge_ASCENDING(m, lm / 2, sm);
		sortMerge_ASCENDING(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
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