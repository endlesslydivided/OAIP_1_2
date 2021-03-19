#pragma once
#include <iostream>
using namespace std;

struct stack
{
	char* data;
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
	int choice;

	char* input[50];
	stack* myStack = new stack;
	myStack->head = NULL;
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Есть ли в стеке значение из диапазона?" << endl;
		cout << "5 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент:"; cin.getline(input,50); push(input, myStack); break;
		case 2: input = pop(myStack); (!strcmp(input,"nothing")) ? cout << "Извлечённый элемент:" << input << endl : cout << "Стек пуст" << endl;
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
}
void push(char* x, stack* myStack)
{
	stack* e = new stack;
	strcpy_s(x,sizeof(x),e->data);
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
		char* nothing[1];
		strcpy_s(nothing[0],sizeof(nothing), "nothing");
		return nothing[0];
	}
	else
	{
		stack* e = myStack->head;
		char* a = myStack->head->data;
		myStack->head = myStack->head->next;
		delete e;
		return a;
	}
}



