#include "stdafx.h"

bool Object::Insert(void* data)  // Вставка в начало
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else

	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}

Element* Object::Search(void* data)  // Найти заданный элемент
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}

void Object::PrintList(void(*f)(void*))  // Вывод
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	}
}

void Object::PrintList1(void(*f)(void*), Element* e)
{
	f(e->Data);
}


bool  Object::Delete(Element* e)  // Удалить по ссылке
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}


bool Object::Delete(void* data)  // Удалить по значению
{
	return Delete(Search(data));
};


Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}

Object Create()
{
	return *(new Object());
}

int Object::CountList(void(*f)(void*))
{
	int count = 0;
	Element* e = Head;
	while (e != NULL)
	{
		e = e->GetNext();
		count++;
	}
	return count;
}
/* Function to delete the entire linked list */
void Object::deleteList(Element** head_ref)
{

	/* deref head_ref to get the real head */
	Element* current = *head_ref;
	Element* next;

	while (current != NULL)
	{
		next = current->Next;
		free(current);
		current = next;
	}

	/* deref head_ref to affect the real head back
		in the caller. */
	*head_ref = NULL;
}