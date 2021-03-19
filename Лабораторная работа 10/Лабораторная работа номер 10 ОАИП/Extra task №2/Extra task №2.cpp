#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;
int iter = 0;
const char* names[10] = { "Александр","Алексей","Евгений","Илья","Виктор","Юрий","Анита","Анна","Екатерина","Елизавета" };
const char* surnames[10] = { "Ковалёв","Михалькевич","Батурель","Баранов","Демидов","Шуст","Пятинкина","Губарь","Астапкина","Зинович" };
const char* middlenames[10] = { "Александрович","Сергеевич","Дмитриевич","Андреевич","Дмитриевич","Алексеевич","Михайловна","Александровна","Сергеевна","Михайловна" };
int courses[10] = { 4,3,4,2,3,4,2,4,3,2};
int groups[10] = { 4,6,3,2,4,3,5,7,5,3};
int birthYears[10] = { 2002,2001,2001,2002,2000,2001,2002,2000,2000,2001};
int maths[10] = { 9,4,5,5,5,6,8,5,7,5 };
int englishes[10] = {9,5,6,8,9,8,9,6,5,8 };
int programmings[10] = { 9,8,8,9,9,6,7,9,6,5 };
int hardwares[10] = { 8,7,6,7,5,8,7,6,8,6};
int physics[10] = { 7,6,7,5,6,7,8,5,7,9};
using namespace std;
struct Student
{
	char name[NAME_SIZE];
	char surname[CITY_SIZE];
	char middlename[CITY_SIZE];
	int birthYear;
	int course;
	int group;
	int math;
	int english;
	int programming;
	int hardware;
	int physics;
	Student* next;
	Student* prev;
};

int menu(void);
void insert(Student* e, Student** phead, Student** plast);
Student* setElement();
void outputList(Student** phead, Student** plast);
void find(char name[NAME_SIZE], Student** phead);
void delet(char name[NAME_SIZE], Student** phead, Student** plast);
void addXBegin(Student* e, Student** phead, Student** plast);
void addelemnts(Student* e, Student** phead, Student** plast);
Student* setelements();
void sort(Student** phead, Student** plast);
void average(Student** phead, Student** plast);
void theBest(Student** phead, Student** plast);
void theOldest(Student** phead, Student** plast);

int main(void)
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Student* head = NULL;
	Student* last = NULL;
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
			for(iter; iter < 10;)	addelemnts(setelements(), &head, &last);
			break;
		}
		case 7: {
			sort(&head, &last);
			break;
		}
		case 8: {
			average(&head, &last);
			break;
		}
		case 9: {
			theBest(&head, &last);
			break;
		}
		case 10: {
			theOldest(&head, &last);
			break;
		}
		case 11:  exit(0);
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
	cout << "1. Ввод записи в конец списка" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Ввод записи в начало списка" << endl;
	cout << "6. Заполнение списка записями" << endl;
	cout << "7. Сортировка по группам и имени" << endl;
	cout << "8. Подсчёт средних оценок каждых групп" << endl;
	cout << "9. Найти лучших по успеваемости в группах" << endl;
	cout << "10. Найти самых старших студентов" << endl;
	cout << "11. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		cin >> s;
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 11);
	return c;
}
//-----------------------------------------------------------
void insert(Student* e, Student** phead, Student** plast) //Добавление в конец списка
{
	Student* p = *plast;
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
void addXBegin(Student* e, Student** phead, Student** plast)
{
	Student* p = *phead;
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
Student* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Student* temp = new  Student();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cin.ignore();
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите фамилию: ";
	cin.getline(temp->surname, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите отчество: ";
	cin.getline(temp->middlename, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите год рождения: ";
	cin >> temp->birthYear;
	cout << "Введите курс: ";
	cin >> temp->course;
	cout << "Введите группу: ";
	cin >> temp->group;
	cout << "Введите оценку(математика): ";
	cin >> temp->math;
	cout << "Введите оценку(английский): ";
	cin >> temp->english;
	cout << "Введите оценку(ОАИП): ";
	cin >> temp->programming;
	cout << "Введите оценку(схемотехника): ";
	cin >> temp->hardware;
	cout << "Введите оценку(физика): ";
	cin >> temp->physics;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Student** phead, Student** plast)      //Вывод списка на экран
{
	Student* t = *phead;
	int iter = 1;
	while (t)
	{
		cout << iter++ << ".| Имя:" << t->name;
		for (int i = strlen(t->name); i < 9; i++) cout << ' ';
		cout << " | Фамилия:" << t->surname;
		for (int i = strlen(t->surname); i < 11; i++) cout << ' ';
		cout << " | Отчество:" << t->middlename;
		for (int i = strlen(t->middlename); i < 13; i++) cout << ' ';
		cout << " | Год рождения:" << t->birthYear << "| Курс:" << t->course << "|  Группа:" <<
			t->group << " | Оценка(математика):" << t->math << " | Оценка(английский):" << t->english << " | Оценка(ОАИП):" << t->programming << " | Оценка(схемотехника):" << t->hardware << " | Оценка(физика):" << t->physics << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Student** phead)    // Поиск имени в списке
{
	Student* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout <<". Имя: " << t->name << ".   Фамилия: " << t->surname << ". Отчество: " << t->middlename << ".   Год рождения: " << t->birthYear << ". Курс: " << t->course << ".  Группа: " <<
		t->group << endl << "Оценка(математика): " << t->math << ".    Оценка(английский): " << t->english << ".    Оценка(ОАИП):" << t->programming << ".    Оценка(схемотехника):" << t->hardware << ".    Оценка(физика):" << t->physics << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Student** phead, Student** plast)  // Удаление имени {	struct Student *t = *phead;	
{
	struct Student* t = *phead;
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
void addelemnts(Student* e, Student** phead, Student** plast)
{
	Student* p = *plast;
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
Student* setelements()      
{
	Student* temp = new  Student();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	strcpy_s(temp->name, names[iter]);
	strcpy_s(temp->surname, surnames[iter]);
	strcpy_s(temp->middlename, middlenames[iter]);
	temp->birthYear = birthYears[iter];
	temp->course = courses[iter];
	temp->group = groups[iter];
	temp->math = maths[iter];
	temp->english = englishes[iter];
	temp->programming = programmings[iter];
	temp->hardware = hardwares[iter];
	temp->physics = physics[iter++];
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void sort(Student** phead, Student** plast)
{
	Student* t = *phead;
	Student c;
	Student* s ;
	int current_size = 0;
	int check = 0;
	while (t != NULL)
	{
		current_size++;
		t = t->next;
	}
	t = *phead;
	do
	{
		check = 0;
		t = *phead;
		for (int i = 0; i < current_size - 1; i++)
		{
			if (t != NULL && t->next != NULL)
			{
				if (t->course < t->next->course)
				{
					swap(t->name, t->next->name);
					swap(t->surname, t->next->surname);
					swap(t->middlename, t->next->middlename);
					swap(t->birthYear, t->next->birthYear);
					swap(t->course, t->next->course);
					swap(t->group, t->next->group);
					swap(t->math, t->next->math);
					swap(t->english, t->next->english);
					swap(t->programming, t->next->programming);
					swap(t->hardware, t->next->hardware);
					swap(t->physics, t->next->physics);
					check++;
				}
		    }
			if (t != NULL && t->next != NULL)
			{
				t = t->next;
			}
		}
	} while (check > 0);
	do
	{
		check = 0;
		t = *phead;
		for (int i = 0; i < current_size - 1; i++)
		{
			if (t->course == t->next->course)
			{
				if (strcmp(t->name, t->next->name) > 0)
				{
					swap(t->name, t->next->name);
					swap(t->surname, t->next->surname);
					swap(t->middlename, t->next->middlename);
					swap(t->birthYear, t->next->birthYear);
					swap(t->course, t->next->course);
					swap(t->group, t->next->group);
					swap(t->math, t->next->math);
					swap(t->english, t->next->english);
					swap(t->programming, t->next->programming);
					swap(t->hardware, t->next->hardware);
					swap(t->physics, t->next->physics);
					check++;
				}
			}
			if (t != NULL && t->next != NULL)
			{
				t = t->next;
			}
		}
	} while (check > 0);
}
void average(Student** phead, Student** plast)
{
	Student* t = *phead;
	int current_size = 0;
	int max_group = 0;
	float average_math;
	float average_english;
	float average_programming;
	float average_hardware;
	float average_physics;
	int student_number;
	while (t != NULL)
	{
		current_size++;
		if (t->group > max_group)max_group = t->group;
		t = t->next;
	}
	for (int gr_i = 1; gr_i < max_group; gr_i++)
	{
		t = *phead;
		average_math = 0;
	    average_english = 0;
		average_programming = 0;
		average_hardware = 0;
		average_physics = 0;
		student_number = 0;
		for (int i = 0; i < current_size - 1; i++)
		{
				if (t->group == gr_i)
				{
					average_math += t->math;
					average_english += t->english;
					average_programming += t->programming;
					average_hardware += t->hardware;
					average_physics += t->physics;
					student_number++;
				}
				if (t != NULL && t->next != NULL)
				{
					t = t->next;
				}
		}
		if(average_math != 0)
		{
			    average_math = average_math / student_number;
				average_english = average_english / student_number;
				average_programming = average_programming / student_number;
				average_hardware = average_hardware / student_number;
				average_physics = average_physics / student_number;
				printf("\nСредние оценки группы номер %i:\nМатематика:%.1f. Английский язык:%.1f. ОАИП:%.1f. Схемотехника:%.1f.Физика:%.1f.\n", gr_i, average_math, average_english, average_programming, average_hardware, average_physics);
		}
		}
}
void theBest(Student** phead, Student** plast)
{
	Student* t = *phead;
	Student* B = NULL;
	int current_size = 0;
	int max_group = 0;
	float average;
	float the_best_average;
	while (t != NULL)
	{
		current_size++;
		if (t->group > max_group)max_group = t->group;
		t = t->next;
	}
	for (int gr_i = 1; gr_i < max_group; gr_i++)
	{
		t = *phead;
		average = 0;
		the_best_average = 0;
		for (int i = 0; i < current_size - 1; i++)
		{
			if (t->group == gr_i)
			{
				average = (t->math + t->english + t->physics + t->programming + t->hardware) / 5.0;
				if (average > the_best_average)
				{
					the_best_average = average;
					B = t;
				}
			}
			if (t != NULL && t->next != NULL)
			{
				t = t->next;
			}
		}
		if (average != 0)
		{
			printf("\nЛучший по успеваемости студент группы %i :%s %s %s. Средний балл:%.1f.\n", gr_i, B->surname, B->name, B->middlename, the_best_average);
		}
	}
}
void theOldest(Student** phead, Student** plast)
{
	Student* t = *phead;
	Student* B = NULL;
	int current_size = 0;
	int max_group = 0;
	int the_oldest;
	while (t != NULL)
	{
		current_size++;
		if (t->group > max_group)max_group = t->group;
		t = t->next;
	}
	for (int gr_i = 1; gr_i < max_group; gr_i++)
	{
		t = *phead;
		the_oldest = 9999;
		for (int i = 0; i < current_size - 1; i++)
		{
			if (t->group == gr_i)
			{
				if (t->birthYear < the_oldest)
				{
					the_oldest = t->birthYear;
					B = t;
				}
			}
			if (t != NULL && t->next != NULL)
			{
				t = t->next;
			}
		}
		if (the_oldest != 9999)
		{
			printf("\nСамый старший студент группы %i :%s %s %s. Год рождения:%i.\n", gr_i, B->surname, B->name, B->middlename, the_oldest);
		}
	}
}