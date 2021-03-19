#include "myStack.h"

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
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Есть ли в стеке повторяющиеся значения?" << endl;
		cout << "5 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент:"; cin >> choice; push(choice, myStack); break;
		case 2:choice = pop(myStack); choice != -1 ? cout << "Извлечённый элемент:" << choice << endl : cout << "Стек пуст" << endl;
		case 3: cout << "Весь стек:" << endl; show(myStack); break;
		case 4: found_value = search_value(myStack);
			found_value ? printf("Количество повторяющихся элементов: %i\n",found_value) : printf("Повторяющихся значений нет или стек пуст.\n"); break;
		case 5:return 0; break;
		}
	}
	return 0;
}

