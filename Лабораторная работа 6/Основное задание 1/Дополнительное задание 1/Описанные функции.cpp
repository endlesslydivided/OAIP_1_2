#include "myStack.h"

int search_value(stack* myStack)
{
	stack* e = myStack->head;
	int* exception = new int[MAX];
	*(exception + 0) = 0;
	int a, l, repeated = 0, k = 0,coming = 0,check = 0,F = 0,once = 0; 
	if (e == NULL)
	{
		cout << "Стек пуст" << endl;
		return 0;
	}
	while (e != NULL)
		{
		F = 0;
		check = 0;
		a = e->data;
		e = myStack->head;
		for (; e != NULL; ) 
		{
			if (e == NULL)
			{
				break;
			}
			l = e->data;
			for (int i = 0; i <= k; i++)
			{
				if (*(exception + i) == a)
				{
					goto part1;
				}
			}
			if (a == l && once != F)
			{
				check++;
				*(exception + (k++)) = a;
			}
		part1:
			e = e->next;
			F++;
		}
		if (check == 1)
		{
			repeated++;
		}
		coming++;
		e = myStack->head;
		once = 0;
		for (int i = 0; i < coming; i++)
		{
			e = e->next;
			once++;
		}
	}
	delete[] exception;
	return repeated;
}
void push(int x, stack* myStack)
{
	stack* e = new stack;
	e->data = x;
	e->next = myStack->head;
	myStack->head = e;
}
void show(stack* myStack)
{
	stack* e = myStack->head;
	int a;
	if (e == NULL)
	{
		cout << "Стек пуст" << endl;
	}
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
int pop(stack* myStack)
{
	if (myStack->head == NULL)
	{
		cout << "Стек пуст" << endl;
		return -1;
	}
	else
	{
		stack* e = myStack->head;
		int a = myStack->head->data;
		myStack->head = myStack->head->next;
		delete e;
		return a;
	}
}


