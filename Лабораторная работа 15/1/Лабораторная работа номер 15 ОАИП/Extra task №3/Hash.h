#pragma once
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <time.h>

#define HASHDEL (void*) -1
struct Object
{
	void** data;
	Object(int, int(*)(void*));
	void ObjectREFILL(int, int(*)(void*));
	int size;  int N;
	int(*getKey)(void*);
	bool insert(void*);
	void searchInd(int key);
	int searchInd_2(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
};
static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL
struct AAA
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};

