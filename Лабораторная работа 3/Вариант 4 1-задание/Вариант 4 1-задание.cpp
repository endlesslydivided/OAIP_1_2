#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define cSize 100
int sizeOfMassive = 0, maxElement = 0,minElement = 0,  betweenResult1 = 0,l = 0; errno_t err;
int massive1[cSize];
FILE* fi;

using namespace std;

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите количество чисел: "); cin >> sizeOfMassive;
	printf("\nВведите максимальное число в массиве: "); cin >> maxElement;
	printf("\nВведите минимальное число в массиве: "); cin >> minElement;
	for (int i = 0; i < sizeOfMassive; i++)
	{
		*(massive1 + i) = minElement + rand() % maxElement;
	}
	err = fopen_s(&fi, "massive.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < sizeOfMassive; i++)
	{
		fprintf_s(fi, "%i ", *(massive1 + i));
	}
	if (fclose(fi) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	err = fopen_s(&fi, "massive.txt", "r");
	if (err != 0)
	{
		perror("Невозможно открыть файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < sizeOfMassive; i++)
	{
			fscanf_s(fi, "%i", &betweenResult1);
			if (betweenResult1 < 0)
			{
				massive1[l++] = betweenResult1;
			}
	}
	fclose(fi);
	printf("Отрицательные числа: ");
	for (int i = 0; i < l; i++)
	{
		cout << massive1[i] << " ";
	}
	return 0;
}

