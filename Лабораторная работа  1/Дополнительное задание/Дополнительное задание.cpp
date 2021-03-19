#include <iostream>   
#include <windows.h>
# define str_len 50                             
# define size 30  
using namespace std;
void enter_new();
void del();
void out();
void departure();
struct TRAIN
{
	char destination[str_len];
	int number;
	float departureTime = 00.00;
};
struct TRAIN listOfTrains[size];
struct TRAIN bad;
struct TRAIN change[1];
int current_size = 0; int choice;
int check = 0;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-поезда, которые отправляются после введённого времени" << endl;
	cout << "0-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
		case 4:  departure();	break;
		}
	} while (choice != 0);
}

void enter_new()
{
	int i = 0;
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Пункт назначения: ";
		cin.ignore();
		cin.getline(listOfTrains[current_size].destination, 50);
		cout << endl << "Номер поезда:";
		cin >> listOfTrains[current_size].number;
		cout << endl << "Время отправления в формате ЧЧ.ММ: ";
		cin >> listOfTrains[current_size].departureTime;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	do
	{
		check = 0;
		for (int i = 0; i < current_size - 1; i++)
		{
			if (strcmp(listOfTrains[i].destination, listOfTrains[i + 1].destination) > 0)
			{
				change[1] = listOfTrains[i];
				listOfTrains[i] = listOfTrains[i + 1];
				listOfTrains[i + 1] = change[1];
				check++;
			}
		}
	} while (check > 0);
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			listOfTrains[de1] = listOfTrains[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			listOfTrains[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << endl << "Пункт назначения: ";
		cout << listOfTrains[n - 1].destination;
		cout << endl << "Номер поезда:";
		cout << listOfTrains[n - 1].number;
		cout << endl << "Время отправления в формате: ";
		cout << listOfTrains[n - 1].departureTime; 
		cout << endl << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Номер выводимой строки: " << i + 1 << endl;
			cout << endl << "Пункт назначения: ";
			cout << listOfTrains[i].destination;
			cout << endl << "Номер поезда:";
			cout << listOfTrains[i].number;
			cout << endl << "Время отправления: ";
			cout << listOfTrains[i].departureTime;
			cout << endl << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void departure()
{
	float searchTime = 00.00; int check = 0;
	printf("Введите время в формате ЧЧ.ММ: "); cin >> searchTime; cout << endl;
	int i = 0;
	for (i; i < current_size; i++)
	{
		if (listOfTrains[i].departureTime > searchTime)
		{
			cout << "Номер выводимой строки  " << i + 1 << endl;  
			cout << endl << "Пункт назначения: ";
			cout << listOfTrains[i].destination;
			cout << endl << "Номер поезда:";
			cout << listOfTrains[i].number;
			cout << endl << "Время отправления: ";
			cout << listOfTrains[i].departureTime;
			cout << endl<< endl;
			check++;
		}
	}
	if (check == 0)
	{
		printf("Поездов, отправляющихся после этого времени, нет!\n");
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}