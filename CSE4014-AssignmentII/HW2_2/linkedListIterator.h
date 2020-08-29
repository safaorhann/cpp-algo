#pragma once
#ifndef H_linkedListType
#define H_linkedListType

#include <iostream> 
#include <string>
#include <cassert>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedListIterator//this is an class to make iterator to list and iterator lets us traverse the list easily
{
public:
	linkedListIterator();
	linkedListIterator(nodeType<Type> *p);
	Type operator*();
	linkedListIterator<Type> operator++();
	bool operator==(const linkedListIterator<Type>& temp) const;
	bool operator!=(const linkedListIterator<Type>& temp) const;

private:
	nodeType<Type> *curr;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	curr = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *p)
{
	curr = p;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return curr->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	curr = curr->link;
	return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& temp) const
{
	return (curr == temp.curr);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& temp) const
{
	return (curr != temp.curr);
}



#endif