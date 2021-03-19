#include "Heap.h"
#include <iostream>
#include <windows.h>
#include <time.h>
int key = 0;
using namespace std;
const char* names[10] = { "Марина","Александр", "Сергей", "Виктор", "Алексей", "Евгений", "Екатерина", "Анна", "Дмитрий", "Дарья" };
const char* numbers[10] = { "+375664","+375664","+375669","+375984","+375632","+375664","+375668","+375666","+375633","+375665" };
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	char k[MAXCHAR];int choice;
	heap::Heap h1 = heap::create(100, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод кучи 1 на экран" << endl;
		cout << "2 - добавить элементы в кучу 1" << endl;
		cout << "3 - удалить максимальный элемент в куче 1" << endl;
		cout << "4 - удалить минимальный элемент в куче 1" << endl;
		cout << "5 - удалить i-й элемент в куче 1" << endl;
		cout << "6 - заполнить кучу данными" << endl;
		cout << "7 - поиск по имени" << endl;
		cout << "8 - поиск по сумме" << endl;
		cout << "9 - изменить запись" << endl;
		cout << "0 - выход" << endl;
		cout << "Сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {
				AAA* a = new AAA;
				cout << "Введите ключ: ";
				cin >> choice;
				a->x = choice;
				cout << "Введите номер: ";
				cin.ignore();
				cin.getline(k,MAXCHAR);
				strcpy_s(a->number, 99, k);
				cout << "Введите имя: " ;
				cin.getline(k, MAXCHAR);
				strcpy_s(a->name, 99, k);
				cout << "Введите cумму: ";
				cin >> a->cash;
				h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax(); break;
		case 4:   h1.extractMin(); break;
		case 5: int i; cout << "Введите номер элемента: "; cin >> i; cout << endl; h1.extractI(i); break;
			break;
		case 6: { 
			cout << "Введите количество записей: ";
			cin >> choice;
			for (int iter = choice; iter > 0; iter--)
			{
				AAA* a = new AAA;
				a->x =key++;
				strcpy_s(a->number, 99, numbers[0 + rand() % 10]);
				strcpy_s(a->name, 99, names[0 + rand() % 10]);
				a->cash = 0 + rand() % 10000;
				h1.insert(a);
			}
		}
			break;
		case 7: {
			cout << "Введите имя: ";
			cin.ignore();
			cin.getline(k, MAXCHAR);
			h1.find(k);
		}
		case 8: {
			long double ca;
			cout << "Введите сумму: ";
			cin >> ca;
			h1.find_cash(ca);
		}
		case 9: {
			int key_find;
			cout << "Введите ключ: ";
			cin >> key_find;
			h1.change_write(key_find);
		}
			  break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
