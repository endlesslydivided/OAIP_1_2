#include <iostream>
#include <fstream>
using namespace std;
struct list
{
	float number;
	list* next;
};

void insert(list*&, float); 
float del(list*&, float);   
int IsEmpty(list*);         
void printList(list*);      
void menu(void);     
void mul10(list*);
void toFile(list*& p);         
void fromFile(list*& p);


int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	float value;
	menu();    // вывести меню 
	cout << " ? ";
	cin >> choice;
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите число "; 
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:   if (!IsEmpty(first)) 
		{
			cout << "Введите удаляемое число ";
			cin >> value;
			if (del(first, value))
			{
				cout << "Удалено число " << value << endl;
				printList(first);
			}
			else
				cout << "Число не найдено" << endl;
		}
			  else
			cout << "Список пуст" << endl;
			break;
		case 3:   mul10(first);
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
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Вычисление произведения чисел, меньше 10" << endl;
	cout << " 4 - Запись списка в файл" << endl;
	cout << " 5 - Чтение из файла" << endl;
	cout << " 6 - Выход" << endl;
}
void insert(list*& p, float value) 
{
	list* newP = new list;
	if (newP != NULL)     
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}
float del(list*& p, float value)  
{
	list* previous, * current, * temp;
	if (value == p->number)
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
		while (current != NULL && current->number != value)
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
			cout << "  -->" << p->number;
			p = p->next;
		}
		cout << "  -->NULL" << endl;
	}
}
void mul10(list* p)  {
	float sm = 1;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number < 10)
				sm = sm * (p->number);
			p = p->next;
		}
		cout << "Произведение = " << sm << endl;
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
		insert(first, buf.number);
		cout << "  -->" << buf.number;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "  -->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}



