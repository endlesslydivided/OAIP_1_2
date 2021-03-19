#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define cSize 100
int sizeOfMassive = 0, checker = 0, checkPlace = 0; errno_t err;
int massive1[cSize];
int massive2[cSize];
int check[1];
int afterAll[cSize];
FILE* fi; FILE* fi1;

using namespace std;

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите размерность массива: "); cin >> sizeOfMassive;
	for (int i = 0; i < sizeOfMassive; i++)
	{
		*(massive1 + i) = 0 + rand() % 10;
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
	for (int r = 0; r < sizeOfMassive; r++)
	{
		fscanf_s(fi, "%i", &check);
		massive2[r] = *check;
	}
	if (fclose(fi) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	err = fopen_s(&fi1, "massive2.txt", "w");
	if (err != 0)
	{
		perror("Невозможно открыть файл\n");
		return EXIT_FAILURE;
	}
	int r = 0;
part1:	for (; r < sizeOfMassive; )
	{
	r++;
		int between = massive2[r];
		checker = 0;
		for (int d = 0; d < checkPlace; d++)
		{
			if (between == afterAll[d])
			{
				goto part1;
			}
		}
		for (int l = 0; l < sizeOfMassive; l++)
		{
			if (between == massive2[l])
			{
				checker++;
			}
			if (checker > 2)
			{
				afterAll[checkPlace++] = between;
				fprintf_s(fi1, "%i ", between); break;
			}
		}
	}
	if (fclose(fi1) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	return 0;
}