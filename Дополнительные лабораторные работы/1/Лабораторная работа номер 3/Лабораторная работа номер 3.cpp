#include <iostream>
#include <stdio.h>  
#include <windows.h>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	int str = 0, stl = 0, n = 0, k = 0; char* estr; char stroka[100], stro[100];
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите размерность квадратной матрицы: "); cin >> n;
	float** matr = new float* [n];
	for (str = 0; str < n; str++)
	{
			matr[str] = new float[n];
	}
	for (str = 0; str < n; str++)
	{
		if (str == 0 && stl == 0)
		{
			*(*(matr + str) + stl) = n;
			stl++;
			for (stl; stl < n; stl++)
			{
				*(*(matr + str) + stl) = (1 + rand() % 10) * pow(0.1, rand() % 3);
			}
		}
		else
		{
			for (stl = 0; stl < n; stl++)
			{
				*(*(matr + str) + stl) = (1 + rand() % 10) * pow(0.1, rand() % 3);
			}
		}
	}
	printf("Итоговый массив вещественных чисел:\n");
	for (str = 0; str < n; str++)
	{
		cout << endl;
		for (stl = 0; stl < n; stl++)
		{
			cout << *(*(matr + str) + stl) << "\t";
		}
	}
	cout << endl;

	errno_t err;
	FILE* f;

	err = fopen_s(&f, "Вещественные числа.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл!\n");
		return EXIT_FAILURE;
	}
	for (str = 0; str < n; str++)
	{
		fprintf(f, "\n");
		for (stl = 0; stl < n; stl++)
		{
			fprintf(f, "%.2f ",  *(*(matr + str) + stl));
		}
	}
	printf("Данные записаны в файл Вещественный числа.txt\n");
	fclose(f);

	err = fopen_s(&f, "Вещественные числа.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка октрытия файла!\n"); return -1;
	}
	else
		printf("\nСтроки, содержащиеся в начальном документе:\n");
	while (fgets(stroka, 50, f) != NULL)
	{
		printf("%s", stroka);
	}
	int l = 0;
	fclose(f);

	printf("\nВведите номер строки, которую необходимо перенести в другой файл: "); cin >> k;

	err = fopen_s(&f, "Вещественные числа.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка октрытия файла!\n"); return -1;
	}
	while (fgets(stroka, 50, f) != NULL)
	{
		if (l++ == k - 1)
		{
			fgets(stro, 50, f);
		}
	}
	fclose(f);

	FILE* N;

	err = fopen_s(&N, "Необходимая строка.txt", "w");

	if (err != 0)
	{
		perror("Невозможно создать файл!\n");
		return EXIT_FAILURE;
	}
	for (str = 0; str < n*3; str++)
	{
		{
			fprintf(f, "%.2f ", *(stro +str));
		}
	}
	fclose(N);

	printf("\nСтрока, содержащаяся в итогов документе:\n");

	err = fopen_s(&N, "Необходимая строка.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка октрытия файла!\n"); return -1;
	}
	while (fgets(stro, 50, N) != NULL)
	{
		printf("%s", stro);
	}
	fclose(N);

	return 0;
		

}
