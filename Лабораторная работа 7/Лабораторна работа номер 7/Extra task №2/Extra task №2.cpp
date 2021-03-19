#include <iostream> 
using namespace std;
extern int choose = 0, access = 0, access_1 = 0;
struct Number
{
	float info;
	Number* next;
};
struct Number_1
{
	float info_1;
	Number_1* next;
};

void create(Number** begin, Number** end, float p);
void view(Number* begin);
void view_1(Number_1* begin_1);
void minElem(Number* begin, Number_1** begin_1,  Number_1** end_1,  int size); 
void DelONE(Number** begin);
void DelALL(Number** begin);

int main()
{
	setlocale(LC_ALL, "Russian");
	Number* begin = NULL, * end, * t;
	Number_1* begin_1 = NULL, * end_1, * t_1;

	float p;int size = 0;
	do
	{
		printf("\n1.Формирование очереди.\n2.Вывести элементы очереди.\n3.Совершить сдвиг по максимальному элементу.\n4.Удаление элемента очереди.\n5.Удаление очереди.\n6.Вывести элементы новой очереди.\n7.Выход.");
		cout << "\nВведите необходимый пункт меню: "; cin >> choose;
		switch (choose)
		{
		case 1: if (access == 0)
		{
			access = 1;
			cout << "Введите размер очереди:";  cin >> size;
			cout << "\nВведите первый элемент: "; cin >> p;
			t = new Number;
			t->info = p;        
			t->next = NULL;
			begin = end = t;
			for (int i = 1; i < size; i++) 
			{
				cout << "\nВведите число:";    cin >> p;
				create(&begin, &end, p);
			}
		}
			  else
		{
			cout << "\nСначала необходимо очистить очередь!";
		}break;
		case 2:
			if (begin == NULL)   
			{
				cout << "Очередь пуста!\n" << endl;
			}
			else
			{
				view(begin);
			}break;
		case 3:minElem(begin, &begin_1,&end_1,size); break;
		case 4: DelONE(&begin); break;
		case 5: DelALL(&begin); break;
		case 6:if (begin_1 == NULL)   
		{
			cout << "Очередь №1 пуста!\n" << endl;
		}
			  else
		{
			cout << "\nОчередь №1:\n";
			view_1(begin_1);
		}
			 break;
		case 7: break;
		default:break;
		}
	} while (choose != 7);
	return 0;
}

void create(Number** begin, Number** end, float p) 
{
	Number* t = new Number;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	else
	{
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}
void view(Number* begin) 
{
	Number* t = begin;
	if (t == NULL)
	{
		cout << "Очередь пуста\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
void view_1(Number_1* begin_1) 
{
	Number_1* t_1 = begin_1;
	if (t_1 == NULL)
	{
		cout << "Очередь пуста!\n";
		return;
	}
	else
		while (t_1 != NULL)
		{
			cout << t_1->info_1 << endl;
			t_1 = t_1->next;
		}
}
void minElem(Number* begin, Number_1** begin_1,Number_1** end_1, int size)
{
	if (access_1)
	{
		Number_1* t_1;
		t_1 = new Number_1;
		while (*begin_1 != NULL)
		{
			t_1 = *begin_1;
			*begin_1 = (*begin_1)->next;
			delete t_1;
		}
	}
	Number* t = begin, * mn;
	float max;
	int lCountMin = 0, lCountMax = 0;
	if (t == NULL)
	{
		cout << "Очередь пуста\n";
	}
	else
	{
			t = begin;
			max = t->info;
			while (t != NULL)
			{
					if (t->info >= max)
					{
						max = t->info;
					}
					t = t->next;
		    }
			int check_once = 0;
			t = begin;
			while (t != NULL)
			{
				Number_1* t_1 = new Number_1;
				if (!check_once)
				{
					t_1->next = NULL;
					if (*begin_1 == NULL)
						*begin_1 = *end_1 = t_1;
					t_1->info_1 = max;
					(*end_1)->next = t_1;
					*end_1 = t_1;
					check_once++;
				}
				else if(t->info == max)
					t = t->next;
				else {
					t_1->next = NULL;
					if (*begin_1 == NULL)
						*begin_1 = *end_1 = t_1;
					t_1->info_1 = t->info;
					(*end_1)->next = t_1;
					*end_1 = t_1;
					t = t->next;
				}
			}
	}
	access_1 = 1;
}
void DelONE(Number** begin)
{
	Number* t;
	t = new Number;
	t = *begin;
	*begin = (*begin)->next;
	delete t;
	if (*begin == NULL)
	{
		access = 0;
	}
}
void DelALL(Number** begin)
{
	Number* t;
	t = new Number;
	while (*begin != NULL)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
	access = 0;
}

