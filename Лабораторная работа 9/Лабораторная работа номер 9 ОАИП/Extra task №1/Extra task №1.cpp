#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

#define MAX 100

void foutF(ofstream& f,char* name, int m);
int exchange(unsigned num,int m, int number, int *iter);

int iteration = 0;
void main()
{
	int n, m, choice = 0, * numbers;
	setlocale(LC_ALL, "rus");
	ofstream fout;
	char name[10];
	do {
		iteration = 0;
		do {
			printf("������� �������� m (�������������): "); cin >> m;
		} while (m <= 0);
		printf("������� �������� ����� ��� ������: "); cin.ignore(); cin.getline(name, 20);
	    foutF(fout,name,m);	printf("\n���������� ������� � ����� %s\n", name);
		printf("\n����������?\n(����� �����) - ��\n0 - ���\n������� �����:"); cin >> choice; cout << endl;
	} while (choice);
}

void foutF(ofstream& f, char* name, int m)
{
	f.open(name);
	for (int i = 0; i < pow(m + 1, m); i++)
	{
		int* iter = new int;
		*iter = 0;
		int number = 0;
		f << i << ".  " << exchange(i, m + 1, number, iter) << endl;
		delete iter;
	}
	f.close();
}

int exchange(unsigned num, int m, int number,int *iter)
{
	number += (num % m) * pow(10, (*iter)++);
	if (num / m)
		number = exchange(num / m,m, number, iter);
	return number;
}
