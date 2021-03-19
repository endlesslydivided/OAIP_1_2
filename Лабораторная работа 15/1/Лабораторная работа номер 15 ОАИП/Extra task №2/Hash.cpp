#include "Hash.h"


//-------------------------------

int HashFunction(int key, int size, int p)    //���-�������
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (int)key2;
}
//-------------------------------
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}
//-------------------------------
void Object::searchInd(int key)
{
	int t = -1;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size; j = Next_hash(j, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					std::cout.width(5);
					std::cout << i + 1 << ". ���� " << ((AAA*)data[j])->key << "-" << ((AAA*)data[j])->mas << std::endl;
				}
}
int Object::searchInd_2(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd_2(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	int space = 0;
	for (int i = 0; i < this->size; i++)
	{
		std::cout.width(25);
		std::cout << i + 1 << ".�������: ";
		if ((this->data)[i] == NULL)
		{
			std::cout.width(4);
			std::cout << "�����   ";
		}
		else
			if ((this->data)[i] == DEL)
			{
				std::cout.width(4);
				std::cout << "������   ";
			}
			else
				f((this->data)[i]);
		space++;
		if (space == 3)
		{
			printf("\n");
			space = 0;
		}
	}
	printf("\n");
	printf("\n");
}
