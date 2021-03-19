#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define cSize 100
int sizeOfMassive = 0, maxElement = 0, average = 0, betweenResult1 = 0, betweenResult2 = 0, check = 0, complete1 = 0, complete2 = 0, getOut = 0; errno_t err; char* estr;
FILE* fi1; FILE* fi2;
char checkBox[100];
char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };

using namespace std;

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	err = fopen_s(&fi1, "message1.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	fputs("Строка текста без чисел (первая) \n", fi1);
	fputs("2 Строка текста начинается с числа (вторая)\n", fi1);
	fputs("Строка текста без чисел (третья)\n", fi1);
	fputs("Строка текста без чисел (четвёртая)\n", fi1);
	fputs("324 Строка текста начинается с числа (пятая)\n", fi1);
	fputs("\0", fi1);
	if (fclose(fi1) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	err = fopen_s(&fi2, "message2.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	err = fopen_s(&fi1, "message1.txt", "r");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	do
	{
		getOut = 0;
		estr = fgets(checkBox, sizeof(checkBox), fi1);
		for (int i = 0; checkBox[i] != '\0' && estr != NULL; i++)
		{
			for (int l = 0; l < 10; l++)
			{
				if (checkBox[i] == numbers[l])
				{
					getOut++;
				}
				if (getOut > 0 && estr != NULL && i == 0)
				{
					fputs(checkBox, fi2); break;
				}
			}
		}
		
	} while (estr != NULL);
	if (fclose(fi1) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	if (fclose(fi2) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	err = fopen_s(&fi2, "message2.txt", "r");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	err = fopen_s(&fi1, "message1.txt", "r");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
	}
	printf("Исходный файл:\n");
	do
	{
		estr = fgets(checkBox, sizeof(checkBox), fi1);
		if (estr != NULL)
			printf(estr);
	} while (estr != NULL);
	printf("\nИтоговый файл:\n");
	do
	{
		estr = fgets(checkBox, sizeof(checkBox), fi2);
		if (estr != NULL)
			printf(estr);
	} while (estr != NULL);
	if (fclose(fi1) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	if (fclose(fi2) == EOF)
	{
		printf("Ошибка закрытия\n");
	}
	return 0;
}