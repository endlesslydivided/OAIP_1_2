#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{

	std::cout << "<Ключ:" << x << "|Номер:" << number << "|Имя:" << name << "|Деньги на счету:$" << cash << ">";
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::extractMin()
	{
		void* rc = nullptr;
		int l;
		int min = 9999999;
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (((AAA*)storage[i])->x < min)
				{
					min = ((AAA*)storage[i])->x;
					rc = storage[i];
					l = i;
				}
			}
			storage[l] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::extractI(int keks)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[keks];
			storage[keks] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void Heap::scan(int i) const     
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}
	void Heap::find(char* k)   
	{
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		else {
			std::cout << "Найденные записи:" << std::endl;
			for (int u = 0, y = 0; u < size; u++)
			{
				if (strcmp(k, ((AAA*)storage[u])->name) == 0)
				{
					((AAA*)storage[u])->print();
					std::cout << '\n';
				}
			}
			std::cout << '\n';
		}
	}
	void Heap::find_cash(long double ca)  
	{
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		else {
			std::cout << "Найденные записи:" << std::endl;
			for (int u = 0, y = 0; u < size; u++)
			{
				if (ca <= ((AAA*)storage[u])->cash)
				{
					((AAA*)storage[u])->print();
					std::cout << '\n';
				}
			}
			std::cout << '\n';
		}
	}
	void Heap::change_write(int ke)
	{
		int choice; char k[MAXCHAR]; long double cas;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		else {
			std::cout << "Запись для изменения:" << std::endl;
			for (int u = 0, y = 0; u < size; u++)
			{
				if (ke <= ((AAA*)storage[u])->x)
				{
					((AAA*)storage[u])->print();
					std::cout << '\n';

					std::cout << "Введите номер(если не надо менять, введите 0): ";
					std::cin.ignore();
					std::cin.getline(k, MAXCHAR);
					if (strcmp(k,"0"))strcpy_s(((AAA*)storage[u])->number, 99, k);

					std::cout << "Введите имя(если не надо менять, введите 0): ";
					std::cin.getline(k, MAXCHAR);
					if (strcmp(k, "0"))strcpy_s(((AAA*)storage[u])->name, 99, k);

					std::cout << "Введите cумму(если не надо менять, введите 0): ";
					std::cin >> cas;
					if (cas)((AAA*)storage[u])->cash = cas;
					break;
				}
			}
			std::cout << '\n';
		}
	}
}
