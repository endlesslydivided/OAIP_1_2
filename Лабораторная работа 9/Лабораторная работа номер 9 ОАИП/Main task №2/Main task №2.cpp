#include <iostream>
using namespace std;

float function_F(int x, float cos_sum,float alpha);



void main()
{
	int x, choice = 0; float alpha = 0;
	setlocale(LC_ALL, "Russian");
	float cos_sum = 0;
	do {
		do {
			printf("Введите значение x (положительное): "); cin >> x;
		} while (x <= 0);
		do {
			printf("Введите значение угла в радианах alpha (положительное): "); cin >> alpha;
		} while (x <= 0);
		printf("\nРезультаты функции F(x):\n");cout << function_F(x, cos_sum, alpha) << endl;
		printf("\nПродолжить?\n(Любое число) - Да\n0 - Нет\nВведите число:"); cin >> choice; cout << endl;
	} while (choice);
}

float function_F(int x, float cos_sum, float alpha)
{
	cos_sum += cos(x * alpha);
	if (x > 1)
	{
		cos_sum = function_F(--x, cos_sum, alpha);
	}
	return cos_sum;
}