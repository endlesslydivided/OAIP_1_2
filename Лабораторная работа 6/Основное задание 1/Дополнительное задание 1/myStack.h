#pragma once
#include <iostream>
using namespace std;
#define MAX 100
struct stack
{
	int data;
	stack* next;
	stack* head;
};

void show(stack* myStack);
int pop(stack* myStack);
void push(int x, stack* myStack);
int search_value(stack* myStack);