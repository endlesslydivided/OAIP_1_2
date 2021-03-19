#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void foutF(ifstream& f);
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fout;
	foutF(fout);
}

void foutF(ifstream& f)
{
	char buff[50];
	int letterNumber = 0;
	f.open("lab4.txt");
	ofstream fin("FILE2.txt");
	do
	{
		f.getline(buff, 50);

		char word[50];
		int i = 0;
		int check = 0;
		for (i; *(buff + i) != ' '; i++)
		{
			word[i] = buff[i];
		}
		word[i] = '\0';
		i++;
		for (; *(buff + i) != '\0' && *(buff + i) != 'М'; i++)
		{
			int k = 0;
			char between[50];
			strcpy_s(between, "MMMMMMMMMMMMMMMM");
			for (i; *(buff + i) != ' ' && *(buff + i) != '\0'; i++)
			{
				between[k] = buff[i];
				k++;
			}
			between[k] = '\0';
			if (strcmp(between, word) == 0)
			{
				check++;
			}
		}
		if (check != 0)
		{
			for (i = 0; *(buff + i) != '\0'; i++)
			{
				fin << (*(buff + i));
				if(*(buff + i) != ' ')
				letterNumber++;
			}
			fin << '\n';
		}
		
	} while (*buff != '\0');
	printf("В файле %i символов", letterNumber);
	f.close();
}
