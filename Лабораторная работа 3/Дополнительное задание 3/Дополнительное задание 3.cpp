#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define cSize 100
int sizeOfMassive = 0, maxElement = 0, quantity = 0,getOut = 0; errno_t err; char* estr;
FILE* fi1; FILE* fi2;
char checkBox[100];

using namespace std;

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите количество символов в строке:\n"); cin >> quantity;
	err = fopen_s(&fi1, "message1.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	fputs("1\n", fi1);
	fputs("22\n", fi1);
	fputs("333\n", fi1);
	fputs("4444\n", fi1);
	fputs("55555\n", fi1);
	fputs("666666\n", fi1);
	fputs("7777777\n", fi1);
	fputs("88888888\n", fi1);
	fputs("999999999\n", fi1);
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
		for (int i = 0; checkBox[i] != '\0' && estr != NULL && checkBox[i] != '\n'; i++)
		{
			getOut++;
		}
		if (getOut > quantity)
		{
			fputs(checkBox,fi2);
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