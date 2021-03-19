#include <iostream> 
using namespace std;
extern int choose = 0, access = 0, access_1 = 0;
struct Number
{
	int info;
	Number* next;
};
struct Number_1
{
	int info_1;
	Number_1* next;
};
struct Number_2
{
	int info_2;
	Number_2* next;
};
void create(Number** begin, Number** end, int p); 
void view(Number* begin);
void view_1(Number_1* begin_1);
void view_2(Number_2* begin_2); 
void minElem(Number* begin, Number_1** begin_1, Number_2** begin_2, Number_1** end_1, Number_2** end_2, int size); 
void DelONE(Number** begin);
void DelALL(Number** begin);

int main()
{
	setlocale(LC_ALL, "Russian");
	Number* begin = NULL, * end, * t;
	Number_1* begin_1 = NULL, * end_1, * t_1;
	Number_2* begin_2 = NULL, * end_2, * t_2;

	int p, size = 0;
	do
	{
		printf("\n1.Формирование очереди.\n2.Вывести элементы очереди.\n3.Раздвоение очереди по минимальным и максимальным элементам.\n4.Удаление элемента очереди.\n5.Удаление очереди.\n6.Вывести элементы новых очередей.\n7.Выход.");
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
		case 3:minElem(begin, &begin_1, &begin_2, &end_1, &end_2, size); break;
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
			  if (begin_2 == NULL)   
			  {
				  cout << "Очередь №2 пуста!\n" << endl;
			  }
			  else
			  {
				  cout << "\nОчередь №2:\n";
				  view_2(begin_2);
			  }break;
		case 7: break;
		default:break;
		}
	} while (choose != 7);
	return 0;
}

void create(Number** begin, Number** end, int p) 
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
void view_2(Number_2* begin_2)
{
	Number_2* t_2 = begin_2;
	if (t_2 == NULL)
	{
		cout << "Очередь пуста!\n";
		return;
	}
	else
		while (t_2 != NULL)
		{
			cout << t_2->info_2 << endl;
			t_2 = t_2->next;
		}
}
void minElem(Number* begin, Number_1** begin_1, Number_2** begin_2, Number_1** end_1, Number_2** end_2, int size)
{
	int lMin[50];
	int lMax[50];
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
		Number_2* t_2;
		t_2 = new Number_2;
		while (*begin_2 != NULL)
		{
			t_2 = *begin_2;
			*begin_2 = (*begin_2)->next;
			delete t_2;
		}
	}
	Number* t = begin, * mn;
	int min;
	int max;
	int out = 0, cheeter_1 = 0, cheeter_2 = 0;
	int lCountMin = 0, lCountMax = 0;
	if (t == NULL)
	{
		cout << "Очередь пуста\n";
	}
	else
	{
		while (out < size)
		{
			t = begin;
			if (out > 0)
			{
				min = lMax[0];
				max = lMin[0];
			}
			else
			{
				min = t->info;
				max = t->info;
			}
			while (t != NULL)
			{
				cheeter_1 = 0;
				if (t->info <= min)
				{
					for (int i = 0; i <= lCountMin; i++)
					{
						if (lMin[i] == t->info)
						{
							cheeter_1 = 1;
						}
						if (lMax[i] == t->info)
						{
							cheeter_1 = 1;
						}
					}
					if (!cheeter_1)
					{
						min = t->info;
						mn = t;
					}
				}
				t = t->next;
			}
			lMin[lCountMin++] = min;
			out++;
			t = begin;
			while (t != NULL)
			{
				cheeter_2 = 0;
				if (out <= size)
				{
					if (t->info >= max)
					{
						for (int i = 0; i <= lCountMax; i++)
						{
							if (lMax[i] == t->info)
							{
								cheeter_2 = 1;
							}
							if (lMin[i] == t->info)
							{
								cheeter_1 = 1;
							}
						}
						if (!cheeter_2)
						{
							max = t->info;
							mn = t;
						}
					}
				}
				t = t->next;
			}
			if (out <= size)
			{
				lMax[lCountMax++] = max;
				out++;
			}
		}
		for (int i = 0; i < lCountMin; i++)
		{
			Number_1* t_1 = new Number_1;
			t_1->next = NULL;
			if (*begin_1 == NULL)
				*begin_1 = *end_1 = t_1;
			t_1->info_1 = lMin[i];
			(*end_1)->next = t_1;
			*end_1 = t_1;
		}
		for (int i = 0; i < lCountMax; i++)
		{
			Number_2* t_2 = new Number_2;
			t_2->next = NULL;
			if (*begin_2 == NULL)
				*begin_2 = *end_2 = t_2;
			t_2->info_2 = lMax[i];
			(*end_2)->next = t_2;
			*end_2 = t_2;
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

