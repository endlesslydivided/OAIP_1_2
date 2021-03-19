#include <iostream>   
#include <windows.h>
# define str_len 50                             
# define size 30  
using namespace std;
void enter_new();
void del();
void out();
void search();
struct NOTE
{
	char name[str_len];
	char date[str_len];
	char adress[str_len];
	char telephone[str_len];
	struct
	{
		unsigned day : 8;
		unsigned month : 4;
		unsigned year : 16;
	}poop;
};
struct NOTE listOfNot[size];
struct NOTE bad;
struct NOTE change[1];

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
	int currentForm, a, b, c;
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "ФИО: ";
		cin.ignore();
		cin.getline(listOfNot[current_size].name, 50);
		cout << endl << "Дата рождения: ";
		cin >> a >> b >> c;
		listOfNot[current_size].poop.day = a; 
		listOfNot[current_size].poop.month = b;
		listOfNot[current_size].poop.year = c;
		cout << endl << "Адрес: ";
		cin.ignore();
		cin.getline(listOfNot[current_size].adress, 50);
		cout << endl << "Телефон(+код страны...): ";
		cin.getline(listOfNot[current_size].telephone, 50);
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
				if (strcmp(listOfNot[i].name, listOfNot[i + 1].name) > 0)
				{
					change[1] = listOfNot[i];
					listOfNot[i] = listOfNot[i + 1];
					listOfNot[i + 1] = change[1];
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
			listOfNot[de1] = listOfNot[de1 + 1];
		current_size = current_size - 1;
		current_check--;
	}
	if (d == 99)
	{
		current_check--;
		for (int i = 0; i < size; i++)
			listOfNot[i] = bad;
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
		cout << endl << "\nФИО      Дата рождения         Адрес        Телефон\n";
		cout << listOfNot[n - 1].name << "\t   " << listOfNot[n + 1].poop.day << listOfNot[n + 1].poop.month<< listOfNot[n+1].poop.year << "\t       " << listOfNot[n - 1].adress<< "\t\t            "  << listOfNot[n - 1].telephone << endl;
	}
	if (sw == 2)
	{
		cout << endl << "\nФИО       Дата рождения       Адрес          Телефон\n";
		for (int i = 0; i < current_size; i++)
		{

			cout << listOfNot[i].name << "\t   " << listOfNot[i].poop.day << listOfNot[i].poop.month << listOfNot[i].poop.year << "\t       " << listOfNot[i].adress << "\t\t            " << listOfNot[i].telephone << endl;
		}
	}
	cout << endl << endl;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	int choose; int none = 0; struct NOTE searching[1];
	printf("Введите номер необходимого вида поиска:\n");
	printf("1 - поиск по фамилии\n");
	cin >> choose;
	if (choose == 1)
	{
		printf("Введите фамилию ");
		cin.ignore();
		cin.getline(searching[0].name, 30);
        cout << endl << "\nФИО      Дата рождения       Адрес         Телефон\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(searching[0].name, listOfNot[i].name) == 0)
			{
				cout << listOfNot[i].name << "\t   " << listOfNot[i].poop.day << listOfNot[i].poop.month << listOfNot[i].poop.year  << "\t       " << listOfNot[i].adress << "\t\t            " << listOfNot[i].telephone << endl;
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
