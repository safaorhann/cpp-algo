#pragma once
#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include "binaryTree.h"

using namespace std;

template <class elemType>
class binarySearchTree : public binaryTree<elemType>
{
private:
	void deleteFromTree(nodeType<elemType>* &p);
public:
	bool search(const elemType& searchItem) const;
	void insert(const elemType& insertItem);
	void deleteNode(const elemType& deleteItem);
};


template <class elemType>
bool binarySearchTree<elemType>::search(const elemType& searchItem) const
{
	nodeType<elemType> *current;
	bool found = false;

	if (root == NULL)
		cout << "Cannot search an empty tree." << endl;
	else
	{
		current = root;

		while (current != NULL && !found)
		{
			if (current->info == searchItem)
				found = true;
			else if (current->info > searchItem)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}

	return found;
} //end search

template <class elemType>
void binarySearchTree<elemType>::insert(const elemType& insertItem)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	nodeType<elemType> *newNode;

	newNode = new nodeType<elemType>;
	trailCurrent = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	if (root == NULL)
	{
		root = newNode;
		newNode->count++;
	}
	else
	{
		current = root;

		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				current->count++;
				return;
			}
			else if (current->info > insertItem)
				current = current->lLink;
			else
				current = current->rLink;
		}

		if (trailCurrent->info > insertItem)
		{
			trailCurrent->lLink = newNode;
			trailCurrent->lLink->count++;
		}
		else
		{
			trailCurrent->rLink = newNode;
			trailCurrent->rLink->count++;
		}
	}
}//end insert

template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType& deleteItem)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	bool found = false;

	if (root == NULL)
		cout << "Cannot delete from an empty tree."
		<< endl;
	else
	{
		current = root;
		trailCurrent = root;

		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->info > deleteItem)
					current = current->lLink;
				else
					current = current->rLink;
			}
		}

		if (current == NULL)
			cout << "The item to be deleted is not in the tree."
			<< endl;
		else if (found)
		{
			if (current == root)
				deleteFromTree(root);
			else if (trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->lLink);
			else
				deleteFromTree(trailCurrent->rLink);
		}
		else
			cout << "The item to be deleted is not in the tree."
			<< endl;
	}
} //end deleteNode

template <class elemType>
void binarySearchTree<elemType>::deleteFromTree(nodeType<elemType>* &p)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	nodeType<elemType> *temp;

	if (p == NULL)
		cout << "The node to be deleted is NULL." << endl;
	else if (p->lLink == NULL && p->rLink == NULL)
	{
		if (p->count > 1)
			p->count--;
		else
		{
			temp = p;
			p = NULL;
			delete temp;
			p->count = 0;
		}
	}
	else if (p->lLink == NULL)
	{
		if (p->count > 1)
			p->count--;
		else
		{
			temp = p;
			p = temp->rLink;
			delete temp;
		}
	}
	else if (p->rLink == NULL)
	{
		if (p->count > 1)
			p->count--;
		else
		{
			temp = p;
			p = temp->lLink;
			delete temp;
		}
	}
	else
	{
		if (p->count > 1)
			p->count--;
		else
		{
			current = p->lLink;
			trailCurrent = NULL;

			while (current->rLink != NULL)
			{
				trailCurrent = current;
				current = current->rLink;
			}

			p->info = current->info;
			p->count = current->count;

			if (trailCurrent == NULL)
				p->lLink = current->lLink;
			else
				trailCurrent->rLink = current->lLink;

			delete current;
		}
	}
} //end deleteFromTree

#endif