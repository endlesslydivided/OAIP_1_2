#include <iostream>	
using namespace std;


static char find(char* arr, const int& n, int m)
{
	if (m < 26)
		find(arr,n, m + 1);
	if(m == 26)
	return arr[n + m];
}
void main()
{
	int max = 26;
	constexpr int size = 26 + 26;
	char arr[size];
	setlocale(LC_ALL, "russian");
	int n = 0;
	for (int i = 0; i < max; i++)
	{
		arr[i] = 'a' + i;
		arr[i + max] = 'a' + i;
	}
	do
	{
		printf("Введите число n меньше 26 и больше нуля:"); cin >> n;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". "<< arr[i] << endl;
		}
		cout << endl;
		cout <<"Искомый символ:" << find(arr, n, 0) << endl;
	} while (n);
}