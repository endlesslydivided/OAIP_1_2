#include <iostream>
#include <windows.h>
using namespace std;


struct stack
{
	char data[50];
	stack* next;
	stack* head;
};

void show(stack* myStack);
char* pop(stack* myStack);
void push(char* x, stack* myStack); 
void search_value(stack* myStack);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int choice;

	char input[50];
	stack* myStack = new stack;
	myStack->head = NULL;
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Вывести слова с символами в определённом порядке" << endl;
		cout << "5 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент:"; do { cin.ignore(); cin.getline(input, 50); } while (strlen(input) % 2 != 0); push(input, myStack); break;
		case 2: strcpy_s(input,sizeof(input),pop(myStack)); (strcmp(input, "nothing")) ? cout << "Извлечённый элемент:" << input << endl : cout << "Стек пуст" << endl;
		case 3: cout << "Весь стек:" << endl; show(myStack); break;
		case 4:search_value(myStack); break;
		case 5:return 0; break;
		}
	}
	return 0;
}


void search_value(stack* myStack)
{
	stack* e = myStack->head;
	if (e == NULL)
	{
		cout << "Стек пуст" << endl;
	}
	while (e != NULL)
	{
		char a[50];
		char second[50]; int second_length = 0;
		char first[50]; int first_length = 0;
		char finale[50]; int finale_length = 0;
		strcpy_s(a, sizeof(a), e->data);
		int length = strlen(a);
		for (int i = 0; i != length; i++)
		{
			if (i < length / 2)
			{
				first[first_length++] = a[i];
			}
			if (i > length / 2)
			{
				second[second_length++] = a[i];
			}
		}
		for (int i = 0; i != length; i++)
		{
			if (i < length / 2)
			{
				finale[finale_length++] = first[first_length--];
			}
			if (i > length / 2)
			{
				finale[finale_length++] = second[second_length--];
			}
		}
		cout << finale << endl;
	}
	cout << endl;
}
void push(char* x, stack* myStack)
{
	stack* e = new stack;
	strcpy_s(e->data, sizeof(e->data), x);
	e->next = myStack->head;
	myStack->head = e;
}
void show(stack* myStack)
{
	stack* e = myStack->head;
	char* a;
	if (e == NULL)
	{
		cout << "Стек пуст" << endl;
	}
	while (e != NULL)
	{
		a = e->data;
		cout << a << " " << endl;
		e = e->next;
	}
	cout << endl;
}
char* pop(stack* myStack)
{
	if (myStack->head == NULL)
	{
		cout << "Стек пуст" << endl;
		char nothing[50];
		strcpy_s(nothing, sizeof(nothing), "nothing");
		return nothing;
	}
	else
	{
		stack* e = myStack->head;
		char a[50];
		strcpy_s(a, sizeof(a), myStack->head->data);
		myStack->head = myStack->head->next;
		delete e;
		return a;
	}
}



