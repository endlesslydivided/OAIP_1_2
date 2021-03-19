﻿

#include <iostream>
#include <windows.h>
using namespace std;
#define max 100
struct Tree          //дерево
{
	int key;         //ключ
	int number;    //текст - не более 4 букв
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root, int& left, int& right);       //Создание дерева
Tree* list(int i, int s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, int s, int& left, int& right);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t);  //Подсчет количества слов
void delAll(Tree* t);             //Очистка дерева

		 //количество слов
Tree* Root = NULL; 	//указатель корня
int sum = 0;
void main()
{
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int key, choice, left_count = 0, right_count = 0;
	Tree* rc; int s, letter;
	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -	подсчет количества листов\n";
		cout << "7 -	очистка дерева\n";
		cout << "8 -	выход\n";
		cout << "Ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root, left_count, right_count);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите число: "; cin >> s;
			insertElem(Root, key, s, left_count, right_count); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			if (rc != NULL)
			{
				cout << "Найденное число= ";
				cout << rc->number << endl;
			}break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root != NULL)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:
			sum = 0;
			count(Root);
			cout << "Количество листов = " << sum << endl; break;
		case 7:  delAll(Root); Root = NULL; break;
		case 8:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root, int& left, int& right)    //Создание дерева
{
	int key; int s;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите число корня: "; cin >> s;
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите число: ";  cin >> s;
		insertElem(Root, key, s, left, right);
	}
	return Root;
}

Tree* list(int i, int s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->number = s;
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int s, int& left, int& right)  //Добавление нового элемента
{
	Tree* Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;  // признак поиска  
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}

	if (!find)
	{
		t = list(key, s);
		if (key < Prev->key)
		{
			Prev->Left = t;
			left++;
		}
		else
		{
			Prev->Right = t;
			right++;
		}
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < n->key)
			rc = search(n->Left, key);
		else
			if (key > n->key)
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

int count(Tree* t)
{
	if (t == NULL) { return NULL; }
	if (t->Right == NULL && t->Left == NULL)
	{
		sum += 1;
		return 1;
	}
	else
	{
		return (count(t->Right) + count(t->Left));
	}
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t == NULL)return;
	else
	{
		view(t->Left, ++level);
		for (int i = 0; i < level; i++)
			cout << "      ";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->number << endl;
		level--;
	}
	view(t->Right, ++level);
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

