#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void foutF(ofstream& f);
int main()
{
	setlocale(LC_ALL, "rus");
	ofstream fout;
	foutF(fout);
}

void foutF(ofstream& f)
{
	char buff[50];
	int complete = 0;
	f.open("FILE2.txt");
	printf("Введите строку слов, разделённых пробелами:\n");
	cin.getline(buff, 50);
	for (int i = 0; *(buff + i) != '\0'; i++)
	{
		f << (*(buff + i));
	}
	f.close();
	ifstream fin;
	fin.open("FILE2.txt");
	int i = 0;
	fin.getline(buff, 50);
	do
	{
		char word[50];
		int check = 0;
		int l = 0;
		for (i; *(buff + i) != ' ' && *(buff + i) != '\0'; i++)
		{
			word[l++] = buff[i];
		}
		word[l] = '\0';
			if (atoi(word) % 2 != 0)
			{
				check++;
			}
		if (check != 0)
		{
			printf(word);
			printf("\n");
			complete++;
		}
		i++;
	} while (*(buff + i) != '\0');
	if (complete == 0)
	{
		printf("Нечётных чисел нет");
	}
	fin.close();
}
