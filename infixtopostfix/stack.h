#pragma once
#include <string>
#include <iostream>

using namespace std;
//stack is simply last in first out data structure.
template <class Type>
class stackType
{
	Type *list;//pointer to create an array where we keep the elements
	int maxStackSize;//it contains the maximum size of the stack
	int stackTop;//it point the top element
	void copyStack(const stackType<Type>& tList);//function to make a copy
public:
	stackType();//constructor
	stackType(const stackType<Type>& tList);//copy constructor
	stackType<Type>& operator=(const stackType<Type>& tList)const;//assignment operator overloading
	void push(const Type& elem);//function to add a new element to the stack
	Type top()const;//function to return the top element from the stack
	void pop();//function to delete the last element from stack
	void initializeStack();//function to make the stack empty	
	bool isEmptyStack();//function to check if the stack is empty
	bool isFullStack();// function to check if the stack is full
};

template <class Type>
stackType<Type>::stackType()
{
	maxStackSize = 100;
	stackTop = 0;
	list = new Type[100];
}
template <class Type>
stackType<Type>::stackType(const stackType<Type>& tList)
{
	copyStack(tList);
}
template <class Type>
void stackType<Type>::pop()
{
	if (!isEmptyStack())
		stackTop--;
	else
		cout << "empty stack,can't delete" << endl;
}
template <class Type>
void stackType<Type>::push(const Type& elem)
{
	if (!isFullStack())
	{
		list[stackTop] = elem;
		stackTop++;
	}
	else
		cout << "cannot push,its full" << endl;
}
template <class Type>
Type stackType<Type>::top()const
{
	return list[stackTop - 1];
}
template <class Type>
bool stackType<Type>::isEmptyStack()
{
	return (stackTop == 0);
}
template <class Type>
bool stackType<Type>::isFullStack()
{
	return (stackTop == maxStackSize);
}
template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;
}
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& tList)
{
	maxStackSize = tList.maxStackSize;
	stackTop = tList.stackTop;
	delete[] list;
	list = new Type[maxStackSize];
	for (int i = 0; i < maxStackSize; i++)
		list[i] = tList[i];

}
template <class Type>
stackType<Type>& stackType<Type>::operator=(const stackType<Type>& tList)const
{
	copyStack(tList);
	return this;
}