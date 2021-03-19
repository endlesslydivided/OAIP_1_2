#include <iostream>   
#include <windows.h>
# define str_len 50                             
# define size 30  
using namespace std;
void enter_new();
void del();
void out();
void search();
union STO
{
	char name[str_len];
	int quantity;
	int price;
	int percent;
}stoU;
struct STORE
{
	char name[str_len];
	int quantity;
	int price;
	int percent;
};
struct STORE listOfSto[size];
struct STORE bad;
struct STORE change[1];

int current_size = 0;
int choice;
int check = 0;
int current_check = 0, current_checkName = 0;
int buf = 0;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "0-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
		case 4:  search();	break;
		}
	} while (choice != 0);
}

void enter_new()
{
	int currentForm;
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименование: ";
		cin.ignore();
		cin.getline(stoU.name, 50);
		strcpy_s(listOfSto[current_size].name, stoU.name);
		cout << endl << "Количество: ";
		cin >> stoU.quantity;
		listOfSto[current_size].quantity = stoU.quantity;
		cout << endl << "Цена(руб.): ";
		cin >> stoU.price;
		listOfSto[current_size].price = stoU.price;
		cout << endl << "Процент торговой надбавки: ";
		cin >> stoU.percent;
		listOfSto[current_size].percent = stoU.percent;
		current_size++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}


	do
	{
		check = 0;
		for (int i = 0; i < current_size - 1; i++)
		{
			if (strcmp(listOfSto[i].name, listOfSto[i + 1].name) > 0)
			{
				change[1] = listOfSto[i];
				listOfSto[i] = listOfSto[i + 1];
				listOfSto[i + 1] = change[1];
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
			listOfSto[de1] = listOfSto[de1 + 1];
		current_size = current_size - 1;
		current_check--;
	}
	if (d == 99)
	{
		current_check--;
		for (int i = 0; i < size; i++)
			listOfSto[i] = bad;
	}

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
		cout << endl << "\nНаименование      Количество               Цена(руб.)          Процент торговой надбавки \n";
		cout << listOfSto[n - 1].name << "\t\t   " << listOfSto[n - 1].quantity << "\t\t\t       " << listOfSto[n - 1].price << "\t\t\t            " << listOfSto[n - 1].percent << endl;
	}
	if (sw == 2)
	{
		cout << endl << "\nНаименование      Количество               Цена(руб.)         Процент торговой надбавки\n";
		for (int i = 0; i < current_size; i++)
		{

			cout << listOfSto[i].name << "\t\t   " << listOfSto[i].quantity << "\t\t\t       " << listOfSto[i].price << "\t\t\t            " << listOfSto[i].percent << endl;
		}
	}
	cout << endl << endl;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	int choose; int none = 0; struct STORE searching[1];
	printf("Введите номер необходимого вида поиска:\n");
	printf("1 - поиск по наименованию\n");
	cin >> choose;
	if (choose == 1)
	{
		printf("Введите наименование государства: ");
		cin.ignore();
		cin.getline(searching[0].name, 30);
		cout << endl << "\nНаименование      Количество               Цена(руб.)         Процент торговой надбавки\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(searching[0].name, listOfSto[i].name) == 0)
			{
				cout << listOfSto[i].name << "\t\t   " << listOfSto[i].quantity << "\t\t\t       " << listOfSto[i].price << "\t\t            " << listOfSto[i].percent << endl;
				none++;
			}
		}
		if (none == 0)
		{
			printf("Не было найдено ни одной записи\n");
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
