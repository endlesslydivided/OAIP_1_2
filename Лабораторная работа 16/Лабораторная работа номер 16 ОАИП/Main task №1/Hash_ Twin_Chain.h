#pragma once              //������������ ���� Hash_ Twin_Chain.h
#include "Lists.h"
namespace hashTC
{
	struct Object                                                                       //��������� "������"
	{
		int sizeO;                                                                      //������ �������
		int(*FunKey)(void*);
		listx::Object* Hash;
		Object(int size, int(*f)(void*))                                                //����� �������� ������ ������� (������, ���������)
		{
			sizeO = size;                                                               //������ ������ �������                           
			FunKey = f;                                                                 //��������� �� ������ ������-������� �������
			Hash = new listx::Object[size];
		};
		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
	};
	Object create(int size, int(*f)(void*));
}
