#include <iostream>
#include <fstream>

using namespace std;
#define MAX 100
struct stack
{
	int data;
	stack* next;
	stack* head;
};
ifstream fin;
char buf[MAX]=" ";
int str_quantity = 0;
void show(stack* myStack);
int pop(stack* myStack);
void push(stack* myStack);
int search_value(stack* myStack);

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	int found_value = 0;
	stack* myStack = new stack;
	myStack->head = NULL;
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Считывание строк с файла и заполнение стека" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Поиск самой короткой строки" << endl;
		cout << "5 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: push( myStack); break;
		case 2:choice = pop(myStack); choice != -1 ? cout << "Извлечённый элемент:" << choice << endl : cout << "Стек пуст" << endl;
		case 3: cout << "Весь стек:" << endl; show(myStack); break;
		case 4: found_value = search_value(myStack);
			found_value ? printf("Самая короткая строка имеет номер: %i. Её длина:%i\n", str_quantity, found_value) : printf("Cтек пуст.\n"); break;
		case 5:return 0; break;
		}
	}
	return 0;
}

int search_value(stack* myStack)
{
	stack* e = myStack->head;
	int min = MAX, number = 0;
	while (str_quantity != 0)
	{
		if (e->data <= min)
		{
			min = e->data;
			number = str_quantity;
		}
		str_quantity--;
		e = e->next;
	}
	str_quantity = number;
	if (min == MAX)
		return 0;
	return min;
}
void push(stack* myStack)
{
	fin.open("text.txt");
	fin.getline(buf, MAX);
	do
	{
		str_quantity++;
		int a = strlen(buf);
		stack* e = new stack;
		e->data = a;
		e->next = myStack->head;
		myStack->head = e;
		fin.getline(buf, 49);
	}while (buf[0] != '\0');
	fin.close();
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
