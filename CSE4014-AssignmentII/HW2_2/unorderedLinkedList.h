#pragma once
#ifndef H_unorderedLinkedList
#define H_unorderedLinkedList

#include "linkedListIterator.h"

using namespace std;

template <class Type>
class unorderedLinkedList //linked list class to create graph with nodes
{
	void copyList(const unorderedLinkedList<Type>& otherList);
	int count;
	nodeType<Type> *first;
	nodeType<Type> *last;
public:
	const unorderedLinkedList<Type>& operator=(const unorderedLinkedList<Type>&);//operator= overloading it copies the list to other list 
	void initializeList();//it initializes the list to an empty state that means destroys
	bool isEmptyList() const;//checks the list if its empty
	void print() const;//displays the list
	int length() const;//return the length of list
	void destroyList();//destroys the tree
	Type front() const;//returns the first elem
	Type back() const;//returns the last elem
	linkedListIterator<Type> begin();//gives an iterator of the begining of the list
	linkedListIterator<Type> end();////gives an iterator of the back of the list
	bool search(const Type& elem) const;//searchs the elem if its in the list
	void insertFirst(const Type& elem);//adds an element to the begining of the list
	void insertLast(const Type& elem);//adds the elem to the end of the list
	void deleteNode(const Type& elem);//deletes the elem from list
	unorderedLinkedList();//constructure
	unorderedLinkedList(const unorderedLinkedList<Type>& otherList);////constructure
	~unorderedLinkedList();//destructure
};
template <class Type>
linkedListIterator<Type> unorderedLinkedList<Type>::end()
{
	linkedListIterator<Type> temp(NULL);
	return temp;
}
template <class Type>
linkedListIterator<Type> unorderedLinkedList<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	return temp;
}

template <class Type>
const unorderedLinkedList<Type>& unorderedLinkedList<Type>::operator=(const unorderedLinkedList<Type>&list)
{
	copyList(list);
}

template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList()
{
	first = NULL;
	last = NULL;
	count = 0;
}
template <class Type>
void unorderedLinkedList<Type>::initializeList() 
{
	destroyList();
}
template <class Type>
bool unorderedLinkedList<Type>::isEmptyList() const
{
	return(first == NULL);
}
template <class Type>
void unorderedLinkedList<Type>::print() const
{
	nodeType<Type> *curr;
	curr = first;

	while (curr != NULL)
	{
		cout << curr->info << " -> ";
		curr = curr->link;
	}
	cout << "NULL";
}
template <class Type>
int unorderedLinkedList<Type>::length() const
{
	return count;
}
template <class Type>
void unorderedLinkedList<Type>::destroyList() 
{
	nodeType<Type> *temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}
template <class Type>
Type unorderedLinkedList<Type>::back() const
{
	assert(last != NULL);
	return last->info;
}
template <class Type>
Type unorderedLinkedList<Type>::front() const
{
	assert(first != NULL);
	return first->info;
}

template <class Type>
unorderedLinkedList<Type>::~unorderedLinkedList()
{
	destroyList();

}
template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList(const unorderedLinkedList<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& elem) const
{
	nodeType<Type> *curr;
	bool found = false;

	curr = first;

	while (curr != NULL && !found)
		if (curr->info == elem)
			found = true;
		else
			curr = curr->link;
	return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& elem)
{
	nodeType<Type> *newnode;
	newnode = new nodeType<Type>;
	newnode->info = elem;
	newnode->link = first;
	first = newnode;
	count++;

	if (last == NULL)
		last = newnode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& elem)
{
	nodeType<Type> *newnode;
	newnode = new nodeType<Type>;
	newnode->info = elem;
	newnode->link = NULL;

	if (first == NULL)
	{
		first = newnode;
		last = newnode;
		count++;
	}
	else
	{
		last->link = newnode;
		last = newnode;
		count++;
	}
}


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& elem)
{
	nodeType<Type> *curr;
	nodeType<Type> *trailCurr;
	bool found;

	if (first == NULL)
		cout << "empty list."
		<< endl;
	else
	{
		if (first->info == elem)
		{
			curr = first;
			first = first->link;
			count--;
			if (first == NULL)
				last = NULL;
			delete curr;
		}
		else
		{
			found = false;
			trailCurr = first;
			curr = first->link;

			while (curr != NULL && !found)
			{
				if (curr->info != elem)
				{
					trailCurr = curr;
					curr = curr->link;
				}
				else
					found = true;
			}

			if (found)
			{
				trailCurr->link = curr->link;
				count--;

				if (last == curr)
					last = trailCurr;
				delete curr;
			}
			else
				cout << "The item to be deleted does not exist." << endl;
		}
	}
}
#endif