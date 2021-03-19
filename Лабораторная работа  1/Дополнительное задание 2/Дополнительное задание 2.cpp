#include <iostream>   
#include <windows.h>
# define str_len 50                             
# define size 30  
using namespace std;
void enter_new();
void del();
void out();
void departure();
void search();


struct SANATORIUM
{
	char name[str_len];
	char placement[str_len];
	char profile[str_len];
	int quantity;
};
struct SANATORIUM listOfSan[size];
struct SANATORIUM bad;
struct SANATORIUM change[1];

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
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Имя санатория: ";
		cin.ignore();
		cin.getline(listOfSan[current_size].name, 50);
		cout << endl << "Расположение санатория: ";
		cin >> listOfSan[current_size].placement;
		cout << endl << "Лечебный профиль: ";
		cin >> listOfSan[current_size].profile;
		cout << endl << "Количество путёвок: ";
		cin >> listOfSan[current_size].quantity;
		current_size++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}
				
				do
				{
					check = 0;
					for (int i = 0; i < current_size - 1 ; i++)
					{
						if (strcmp(listOfSan[i].profile, listOfSan[i + 1].profile) > 0)
						{
							change[1] = listOfSan[i];
							listOfSan[i] = listOfSan[i + 1];
							listOfSan[i + 1] = change[1];
							check++;
						}
					}
				}while (check > 0);

				do
				{
					check = 0;
					for (int i = 0; i < current_size - 1; i++)
					{
						if (strcmp(listOfSan[i].profile, listOfSan[i + 1].profile) == 0)
						{
							if (strcmp(listOfSan[i].name, listOfSan[i + 1].name) > 0)
							{
								change[1] = listOfSan[i];
								listOfSan[i] = listOfSan[i + 1];
								listOfSan[i + 1] = change[1];
								check++;
							}
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
			listOfSan[de1] = listOfSan[de1 + 1];
		current_size = current_size - 1;
		current_check--;
	}
	if (d == 99)
	{
		current_check--;
		for (int i = 0; i < size; i++)
			listOfSan[i] = bad;
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
		cout << endl << "\nИмя санатория      Расположение санатория           Лечебный профиль            Количество путёвок\n";
		cout << listOfSan[n - 1].name <<"\t\t          "<< listOfSan[n - 1].placement << "\t\t           "<<listOfSan[n - 1].profile << "\t\t            "<< listOfSan[n - 1].quantity << endl;
	}
	if (sw == 2)
	{
		cout << endl << "\nИмя санатория      Расположение санатория           Лечебный профиль            Количество путёвок\n";
		for (int i = 0; i < current_size; i++)
		{
			
		cout << listOfSan[i].name << "\t\t          " << listOfSan[i].placement << "\t\t           " << listOfSan[i].profile << "\t\t            " << listOfSan[i].quantity << endl;
		}
	}
	cout << endl << endl;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	int choose; int none = 0; struct SANATORIUM searching[1];
	printf("Введите номер необходимого вида поиска:\n");
	printf("1 - поиск по названию\n2 - поиск по местоположению\n3 - поиск по профилю\n4 - поиск по наличию путёвок\n");
	cin >> choose;
	if (choose == 1)
	{
		printf("Введите название санатория: ");
		cin.ignore();
		cin.getline(searching[0].name, 30);
		cout << endl << "\nИмя санатория      Расположение санатория           Лечебный профиль            Количество путёвок\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(searching[0].name,listOfSan[i].name) == 0)
			{
				cout << listOfSan[i].name << "\t\t          " << listOfSan[i].placement << "\t\t           " << listOfSan[i].profile << "\t\t            " << listOfSan[i].quantity << endl;
				none++;
			}
		}
		if (none == 0)
		{
			printf("Не было найдено ни одной записи\n");
		}
	}
	if (choose == 2)
	{
		printf("Введите название города: ");
		cin.ignore();
		cin.getline(searching[0].placement, 30);
		cout << endl << "\nИмя санатория      Расположение санатория           Лечебный профиль            Количество путёвок\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(searching[0].placement,listOfSan[i].placement) == 0)
			{
				cout << listOfSan[i].name << "\t\t          " << listOfSan[i].placement << "\t\t           " << listOfSan[i].profile << "\t\t            " << listOfSan[i].quantity << endl;
				none++;
			}
		}
		if (none == 0)
		{
			printf("Не было найдено ни одной записи\n");
		}
	}
	if (choose == 3)
	{
		printf("Введите название профиля: ");
		cin.ignore();
		cin.getline(searching[0].profile, 30);
		cout << endl << "\nИмя санатория      Расположение санатория           Лечебный профиль            Количество путёвок\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(searching[0].profile,listOfSan[i].profile) == 0)
			{
				cout << listOfSan[0].name << "\t\t          " << listOfSan[i].placement << "\t\t           " << listOfSan[i].profile << "\t\t            " << listOfSan[i].quantity << endl;
				none++;
			}
		}
		if (none == 0)
		{
			printf("Не было найдено ни одной записи\n");
		}
	}
	if (choose == 4)
	{
		cout << endl << "\nИмя санатория      Расположение санатория           Лечебный профиль            Количество путёвок\n";
		for (int i = 0; i < current_size; i++)
		{
			if (listOfSan[i].quantity > 0)
			{
				cout << listOfSan[i].name << "\t\t          " << listOfSan[i].placement << "\t\t           " << listOfSan[i].profile << "\t\t            " << listOfSan[i].quantity << endl;
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