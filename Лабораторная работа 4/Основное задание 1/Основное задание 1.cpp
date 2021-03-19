#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void foutF(ifstream &f);
char consonants[] = { 'b','c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't','v','w','x','z'};
int main()
{
    setlocale(LC_ALL, "rus");
	ifstream fout;
	foutF(fout);
}

void foutF(ifstream& f)
{
	char buff[50];
	int consonantsNumber = 0;
	int once = 0;
	f.open("lab4.txt");
	ofstream fin("FILE2.txt");
	do
	{
		f.getline(buff, 50);
		if (once == 0)
		{
			for (int k = 0; *(buff + k) != '\0'; k++)
			{
				for (int c = 0; *(consonants + c) != '\0'; c++)
				{
					if (*(consonants + c) == *(buff + k))
					{
						consonantsNumber++;
					}
				}
			}
			once++;
		}
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
		if (check == 0)
		{
			for (i = 0; *(buff + i) != '\0'; i++)
			{
				fin << (*(buff + i)) ;
			}
			fin << '\n';
		}
	} while (*buff != '\0');
	printf("В первом предложении %i согласных букв", consonantsNumber);
	f.close();
}
