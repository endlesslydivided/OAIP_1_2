#pragma once
#include <iostream>
using namespace std;

struct Element  // ������� ������ 
{
	Element* Next;  // ��������� �� ��������� ������� 
	Element* Prev;  // ��������� �� ���������� �������  
	void* Data;  //  ������
	Element(Element* prev, void* data, Element* next)
	{
		Prev = prev;
		Data = data;
		Next = next;
	}
	Element* GetNext()    // �������� ���������
	{
		return Next;
	};
	Element* GetPrev()    // �������� ����������
	{
		return Prev;
	};
};

struct Object  // ���� ���������� �������
{
	Element* Head;      // ��������� �� ������ ������
	Object()
	{
		Head = NULL;
	};

	Element* GetFirst()  // �������� ������ ������� ������
	{
		return Head;
	};

	Element* GetLast();  // �������� ��������� ������� ������
	Element* Search(void* data);  // ����� ������ ������� �� ������ 
	bool Insert(void* data);  // �������� ������� � ������	
	bool Delete(Element* e);  // ������� �� ������ �������� 
	bool Delete(void* data);  // ������� ������ �� ������
	void deleteList(Element** head_ref);      //�������� ������
	void PrintList(void(*f)(void*));
	void PrintList1(void(*f)(void*), Element*);
	int CountList(void(*f)(void*));
};
Object Create();