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
	char string1[50];
	char string2[50];
	int complete = 0;
	int letterN = 0;
	f.open("FILE2.txt");
	printf("Введите строку слов, разделённых пробелами:\n");
	cin.getline(buff, 50);
	printf("Введите количество букв первой подстроки:\n");
	cin >> letterN;
	for (int i = 0; *(buff + i) != '\0'; i++)
	{
		f << (*(buff + i));
	}
	f.close();
	ifstream fin;
	fin.open("FILE2.txt");
	int i = 0;
	int l = 0;
	int k = 0;
	fin.getline(buff, 50);
	do
	{
		
		for (i; *(buff + i) != '\0'; i++)
		{
			if (i < letterN)
				string1[l++] = (*(buff + i));
			else
				string2[k++] = (*(buff + i));
		}
	} while (*(buff + i) != '\0');
	    string1[l] = '\0';
		string2[k] = '\0';
		printf("Первая подстрока:%s ", string1);
		printf("\nВторая подстрока:%s ", string2);
	fin.close();
}
