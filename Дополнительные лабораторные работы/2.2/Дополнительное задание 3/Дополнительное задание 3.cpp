#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
int a, b, c, d, e, f = 0, g = 0, h, i, j, k, sum;
#define constanta 100
int fsum(int, int n, ...);
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do
	{
		printf("Сколько произведений чисел надо сложить?\n");
		printf("1-Одно произведение \n"); printf("2-Два произведения\n"); printf("3-Три произведения\n"); printf("0-ВЫХОД\n");
		cin >> a;
		switch (a)
		{
		case 1:
			printf("Введите первое число: "); cin >> b;
			printf("Введите второе число: "); cin >> c;
			cout << fsum(1, b, c) << endl; break; 

		case 2:
			printf("Введите первое число: "); cin >> b;
			printf("Введите второе число: "); cin >> c;
			printf("Введите третье  число: "); cin >> d;
			cout << fsum(2, b, c, d) << endl; break;

		case 3:
			printf("Введите первое число: "); cin >> b;
			printf("Введите второе число: "); cin >> c;
			printf("Введите третье  число: "); cin >> d;
			printf("Введите четвёртое число: "); cin >> e;
			cout << fsum(3, b, c, d, e) << endl; break;

		case 0:break;
		}
	} while (a != 0);

}
int fsum(int k, int n, ...)
{
	int* p = &n;
	sum = 0;
	for (f = 0; f < k; f++)
	{
			sum += *(p + f) * *(p + f + 1);
	}
	return sum;
}
