#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;
using namespace std;
int iter = 0;

const char* names[12] = { "Александр","Алексей","Евгений","Илья","Виктор","Юрий","Анита","Анна","Екатерина","Елизавета","Дмитрий","Елена" };
const char* surnames[12] = { "Ковалёв","Михалькевич","Батурель","Баранов","Демидов","Шуст","Пятинкина","Губарь","Астапкина","Зинович","Бруй","Ловенецкая" };

struct Circle
{
	char name[NAME_SIZE];
	char surname[CITY_SIZE];
	Circle* next;
	Circle* prev;
};

int menu(void);
void insert(Circle* e, Circle** phead, Circle** plast);
Circle* setElement();
void outputList(Circle** phead, Circle** plast);
void find(char name[NAME_SIZE], Circle** phead);
void delet(char name[NAME_SIZE], Circle** phead, Circle** plast);
void addXBegin(Circle* e, Circle** phead, Circle** plast);
void addelemnts(Circle* e, Circle** phead, Circle** plast);
Circle* setelements();
void delet_sector(Circle** phead, Circle** plast, int n);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Circle* head = NULL;
	Circle* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
		case 5: {addXBegin(setElement(), &head, &last);
			break;
		}
		case 6: {
			if (head == NULL) iter = 0;
			for (iter; iter < 12;)	addelemnts(setelements(), &head, &last);
			break;
		}
		case 7: {
			int i = 0;
			printf("Введите число:"); cin >> i;
			delet_sector(&head, &last, i);
			break;
		}
		case 8:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени в конец списка" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Ввод имени в начало списка" << endl;
	cout << "6. Заполнение списка" << endl;
	cout << "7. Удаление каждого k-ого человека из круга." << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin >> s;
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 8);
	return c;
}
//-----------------------------------------------------------
void insert(Circle* e, Circle** phead, Circle** plast) //Добавление в конец списка
{
	Circle* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
void addXBegin(Circle* e, Circle** phead, Circle** plast)
{
	Circle* p = *phead;
	if (*phead == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->prev = e;
		e->prev = NULL;
		e->next = p;
		*phead = e;
	}
}
//-----------------------------------------------------------
Circle* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Circle* temp = new  Circle();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите фамилию: ";
	cin.getline(temp->surname, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Circle** phead, Circle** plast)      //Вывод списка на экран
{
	Circle* t = *phead;
	int iter = 1;
	while (t)
	{
		if(iter <10)
		cout << iter++ << ".  Имя: " << t->name;
		else
		cout << iter++ << ". Имя: " << t->name;
		for (int i = strlen(t->name); i < 9; i++) cout << " ";
	
		cout << "   Фамилия: " << t->surname << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Circle** phead)    // Поиск имени в списке
{
	Circle* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->surname << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Circle** phead, Circle** plast)  // Удаление имени {	struct Circle *t = *phead;	
{
	struct Circle* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
//-----------------------------------------------------------
void addelemnts(Circle* e, Circle** phead, Circle** plast)
{
	Circle* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
Circle* setelements()
{
	Circle* temp = new  Circle();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	strcpy_s(temp->name, names[iter]);
	strcpy_s(temp->surname, surnames[iter++]);
	return temp;
}
void delet_sector(Circle** phead, Circle** plast, int n)
{
	struct Circle* t = *phead;
	struct Circle* save;
	int iter = 1;
	int current_size = 0;
	while (t != NULL)
	{
		current_size++;
		t = t->next;
	}
	save = *phead;
	do {
		t = save;
		for (iter; iter % n != 0; iter++)
		{
			if (t == NULL)return;
			t = t->next;
		}
		iter++;
		save = t->next;
			if (*phead == t)
			{
				*phead = t->next;
				if (*phead)
					(*phead)->prev = NULL;
				else
					*plast = NULL;
			}
			else
			{
				t->prev->next = t->next;
				if (t != *plast)
					t->next->prev = t->prev;
				else
					*plast = t->prev;
			}
			delete t;
	} while (t != NULL && iter < current_size);
}

