#include <iostream>
using namespace std;

int function_F(int m, int n);
int iteration = 0;
void main()
{
	int n, m, choice = 0;
	setlocale(LC_ALL, "Russian");
	do{
		iteration = 0;
		do {
			printf("Введите значение m (положительное): "); cin >> m;
		} while (m <= 0);
		do{
			printf("Введите значение n (положительное): "); cin >> n;
	    } while (n <= 0);
	printf("\nРезультаты функции F(m,n):\n"); function_F(m, n);
	printf("\nПродолжить?\n(Любое число) - Да\n0 - Нет\nВведите число:"); cin >> choice; cout << endl;
    }while (choice);
}

int function_F(int m, int n)
{
	if (m == 0 || n == 0)
	{
		n = n + 1;
	}
	else
	{ 
	    n = function_F(m - 1, function_F(m, n - 1));
	}
	iteration++;
	printf("%i.F(%i,%i) = %i\n",iteration, m, n, n);
	return n;
}