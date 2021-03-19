#include "Hash.h"

const char* words[11] = { "Привет","Яблоко", "Книга", "Стол", "Желе", "С++", "ПОИТ", "КЯР", "228", "300", "Пока" };

void AAA_print(void* d)
{
	std::cout.width(4);
	std::cout << "Ключ " << ((AAA*)d)->key << "-" << ((AAA*)d)->mas;
}
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}

using namespace std;

//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int siz = 0, choice, k;
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "\n1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "5 - заполнение хеш-таблицы элементами" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			bool b = false;
			cout << "Введите ключ: " << endl; cin >> k;
			a->key = k;
			cout << "Введите строку" << endl; cin >> str;
			a->mas = str;
			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
		} break;
		case 3: {  cout << "Введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "Введите ключ для поиска" << endl;
			cin >> k;
			H.searchInd(k);
		}  break;
		case 5: {
			for (int iter = 0; iter < siz; iter++)
			{
				AAA* a = new AAA;
				char* str = new char[20];
				bool b = false;
				a->key = 1 + rand() % 20;

				a->mas = words[0 + rand() % 11];
				if (H.N == H.size)
					cout << "Таблица заполнена" << endl;
				else
					H.insert(a);
			}
		}  break;
		}
	}
	return 0;
}
