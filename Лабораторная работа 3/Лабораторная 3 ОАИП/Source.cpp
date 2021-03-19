#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define cSize 100
int sizeOfMassive = 0, maxElement = 0, average = 0, betweenResult1 = 0, betweenResult2 = 0, check = 0, complete1 = 0, complete2 = 0; errno_t err;
int massive1[cSize];
FILE* fi;

using namespace std;

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите размерность массива: "); cin >> sizeOfMassive;
	printf("\nВведите максимальное число в массиве: "); cin >> maxElement;
	check = maxElement;
	printf("\nВведите необходимое среднее арифметическое: "); cin >> average;
	for (int i = 0; i < sizeOfMassive; i++)
	{
		*(massive1 + i) = 0 + rand() % maxElement;
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

	for (int i = 0; i < sizeOfMassive; i++)
	{
		err = fopen_s(&fi, "massive.txt", "r");
		if (err != 0)
		{
			perror("Невозможно открыть файл\n");
			return EXIT_FAILURE;
		}
		for (int r = 0; r < i; r++)
		{ 
			fscanf_s(fi, "%i", &betweenResult1);
		}
		for (int l = 0;l < sizeOfMassive - i; l++)
		{
			fscanf_s(fi, "%i", &betweenResult2);
			if (check >= abs(average - ((betweenResult1 + betweenResult2)/2)))
			{
				check = abs(average - ((betweenResult1 + betweenResult2)/2));
				complete1 = betweenResult1;
				complete2 = betweenResult2;
			}
			fclose(fi) == EOF;
			
		}
	}
	err = fopen_s(&fi, "massive.txt", "r");
	
	printf("Среднее арифметическое двух данных чисел из массива ближе всего к введённому чилу %i: %i и %i", average, complete1, complete2);
	return 0;
}

