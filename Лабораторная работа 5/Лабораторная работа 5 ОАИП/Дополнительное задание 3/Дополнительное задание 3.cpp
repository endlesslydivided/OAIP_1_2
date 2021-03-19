#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct list
{
	char symbol;
	list* next;
};

void insert(list*&, char);
char del(list*&, char);
int IsEmpty(list*);
void printList(list*);
void menu(void);
void mul10(list*, char);
void toFile(list*& p);
void fromFile(list*& p);


int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	list* first = NULL;
	int choice;
	char value;
	menu();
	cout << " ? ";
	cin >> choice;
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:  cout << "Введите символ ";
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:
			if (!IsEmpty(first))
			{
				cout << "Введите удаляемый символ ";
				cin >> value;
				if (del(first, value))
				{
					cout << "Удаленый символ " << value << endl;
					printList(first);
				}
				else
					cout << "Символ не найден" << endl;
			}
			else
				cout << "Список пуст" << endl;
			break;
		case 3:
			cout << "Введите искомый символ: ";
			cin >> value;
			mul10(first, value);
			break;
		default:  cout << "Неправильный выбор" << endl;
			menu();
			break;
		case 4:   toFile(first);
			break;
		case 5:   fromFile(first);
			break;
		}
		cout << "?  ";
		cin >> choice;
	}
	cout << "Конец" << endl;
	return 0;
}
void menu(void)
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод символа" << endl;
	cout << " 2 - Удаление символа" << endl;
	cout << " 3 - Найти символ, следующий после введённого" << endl;
	cout << " 4 - Запись списка в файл" << endl;
	cout << " 5 - Чтение из файла" << endl;
	cout << " 6 - Выход" << endl;
}
void insert(list*& p, char value)
{
	list* newP = new list;
	if (newP != NULL)
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}
char del(list*& p, char value)
{
	list* previous, * current, * temp;
	if (value == p->symbol)
	{
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->symbol != value)
		{
			previous = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}
int IsEmpty(list* p)
{
	return p == NULL;
}
void printList(list* p)
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "  -->" << p->symbol;
			p = p->next;
		}
		cout << "  -->NULL" << endl;
	}
}
void mul10(list* p, char value) {
	list* current, * future;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		current = p;
		future = p->next;
		while (current != NULL && current->symbol != value)
		{
			current = future;
			future = current->next;
		}
		if (current != NULL && future != NULL)
		{
			printf("Искомый символ:"); cout << future->symbol << endl;
		}
		else
		{
			printf("Конец списка");
		}
	}
}
void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}
void fromFile(list*& p)
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.symbol);
		cout << "  -->" << buf.symbol;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "  -->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}


