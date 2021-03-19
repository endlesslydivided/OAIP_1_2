#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

#define MAX 100

void next_perm(int k, int A[], int size);
void swap(int& x, int& y);
int o = 1;
int main()
{
	int n, m, choice = 0, numbers[MAX];
	setlocale(LC_ALL, "rus");
	do {
		do {
			printf("Введите количество чисел: "); cin >> m;
		} while (m <= 0);
		for (int i = 0; i < m; i++)
		{
			printf("Введите число номер №%i: ", i + 1); cin >> numbers[i];
		}
		printf("\nРезультат:\n"); next_perm(0, numbers, m);
		printf("\nПродолжить?\n(Любое число) - Да\n0 - Нет\nВведите число:"); cin >> choice; cout << endl;
	} while (choice);
}

void print(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i];
	cout << endl;
	o++;
}
void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void next_perm(int k, int A[], int size)
{
	if (k == size)
	{
		print(A, size);
		return;
	}
	for (int i = k; i < size; i++)
	{
		swap(A[k], A[i]);
		next_perm(k + 1, A, size);
		swap(A[k], A[i]);
	}
}
