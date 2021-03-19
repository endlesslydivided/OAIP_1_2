#include <iostream>
#include <windows.h>
using namespace std;
float a, b; float x;
#define e 0.001
float f1(float(*) (float), float(*) (float),float, float,float);
float f2(float(*) (float), float(*) (float),float, float,float);
float g11(float);
float g21(float);
float g12(float);
float g22(float);
int main()
{ 
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Введите значение первого конца отрезка: "); cin >> a;
	printf("Введите значение второго конца отрезка: "); cin >> b;
	cout << "Корень первого уравнения: " << f1(g12, g11,a,b,x) << endl;
	cout << "Корень второго уравнения: " << f2(g22, g21,a,b,x) << endl;
}
float f1(float(*g12) (float), float(*g11)(float),float a, float b, float x)
{
	do
	{
		x = (a + b) / 2;
		if (g11(x) * g12(a) <= 0)
			b = x;
		else
			a = x;
	} while (abs(a - b) > 2 * e);
	return x;
}
float f2(float(*g22) (float), float(*g21)(float), float a, float b, float x)
{
	do
	{
		x = (a + b) / 2;
		if (g21(x) * g22(a) <= 0)
			b = x;
		else
			a = x;
	} while (abs(a - b) > 2 * e);
	return x;
}
float g11(float x)
{
	return(2 * x + pow(x, 3) - 7);
}
float g21(float x)
{
	return(exp(x) + 2*x);
}
float g12(float x)
{
	return(2 * a + pow(a, 3) - 7);
}
float g22(float x)
{
	return(exp(a) + 2 * a);
}