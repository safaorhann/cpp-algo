#pragma once
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

template <class elemType>
struct nodeType
{
	elemType info;
	int count = 0;
	nodeType<elemType> *lLink;
	nodeType<elemType> *rLink;
};

template <class elemType>
class binarySearchTree
{
public:
	const binarySearchTree<elemType>& operator=(const binarySearchTree<elemType>&);
	bool isEmpty() const;
	void inorderTraversal() const;
	void preorderTraversal() const;
	void postorderTraversal() const;
	int treeHeight() const;
	int treeNodeCount() const;
	int treeLeavesCount() const;
	void destroyTree();
	binarySearchTree(const binarySearchTree<elemType>& otherTree);
	binarySearchTree();
	~binarySearchTree();
	bool search(const elemType& searchItem) const;
	void insert(const elemType& insertItem);
	void deleteNode(const elemType& deleteItem);
	void deleteFromTree(nodeType<elemType>* &p);
protected:
	nodeType<elemType>  *root;

private:
	void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
	void destroy(nodeType<elemType>* &p);
	void inorder(nodeType<elemType> *p) const;
	void preorder(nodeType<elemType> *p) const;
	void postorder(nodeType<elemType> *p) const;
	int height(nodeType<elemType> *p) const;
	int max(int x, int y) const;
	int nodeCount(nodeType<elemType> *p) const;
	int leavesCount(nodeType<elemType> *p) const;
};

template <class elemType>
binarySearchTree<elemType>::binarySearchTree()//constructure
{
	root = NULL;
}

template <class elemType>
bool binarySearchTree<elemType>::isEmpty() const//func to check whether tree is empty
{
	return (root == NULL);
}

template <class elemType>
void binarySearchTree<elemType>::inorderTraversal() const//func to travel and display the tree nodes
{
	inorder(root);
}

template <class elemType>
void binarySearchTree<elemType>::preorderTraversal() const//func to travel and display the tree nodes
{
	preorder(root);
}

template <class elemType>
void binarySearchTree<elemType>::postorderTraversal() const//func to travel and display the tree nodes
{
	postorder(root);
}

template <class elemType>
int binarySearchTree<elemType>::treeHeight() const//returns the height of tree
{
	return height(root);
}

template <class elemType>
int binarySearchTree<elemType>::treeNodeCount() const//returns the number of nodes in the tree
{
	return nodeCount(root);
}

template <class elemType>
int binarySearchTree<elemType>::treeLeavesCount() const//counts the leaves
{
	return leavesCount(root);
}

template <class elemType>
void  binarySearchTree<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)//func to copy a tree to another tree
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copiedTreeRoot->count = otherTreeRoot->count;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
} //end copyTree

template <class elemType>
void binarySearchTree<elemType>::inorder(nodeType<elemType> *p) const//recursive func for the display funcs since this is a tree
{
	if (p != NULL)
	{
		inorder(p->lLink);
		for (int i = 0; i < p->count; i++)
			cout << p->info << " ";
		inorder(p->rLink);
	}
}

template <class elemType>
void binarySearchTree<elemType>::preorder(nodeType<elemType> *p) const//recursive func for the display funcs since this is a tree
{
	if (p != NULL)
	{
		for (int i = 0; i < p->count; i++)
			cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

template <class elemType>
void binarySearchTree<elemType>::postorder(nodeType<elemType> *p) const//recursive func for the display funcs since this is a tree
{
	if (p != NULL)
	{
		postorder(p->lLink);
		postorder(p->rLink);
		for (int i = 0; i < p->count; i++)
			cout << p->info << " ";
	}
}

template <class elemType>
const binarySearchTree<elemType>& binarySearchTree<elemType>::operator=(const binarySearchTree<elemType>& otherTree)//operator= overloading it simply copies the tree to another tree
{
	if (this != &otherTree)
	{
		if (root != NULL)
			destroy(root);

		if (otherTree.root == NULL)
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}

	return *this;
}

template <class elemType>
void  binarySearchTree<elemType>::destroy(nodeType<elemType>* &p)//recursive func to destroy
{
	if (p != NULL)
	{
		if (p->count > 1)
			p->count--;
		else
		{
			destroy(p->lLink);
			destroy(p->rLink);
			delete p;
			p = NULL;
			p->count = 0;
		}
	}
}

template <class elemType>
void  binarySearchTree<elemType>::destroyTree()//destroys the tree
{
	destroy(root);
}

template <class elemType>
binarySearchTree<elemType>::binarySearchTree(const binarySearchTree<elemType>& otherTree)//constructure with parameter
{
	if (otherTree.root == NULL)
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binarySearchTree<elemType>::~binarySearchTree()//destructure
{
	destroy(root);
}

template<class elemType>
int binarySearchTree<elemType>::height(nodeType<elemType> *p) const//returns the height of tree
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binarySearchTree<elemType>::max(int x, int y) const//finds the max element 
{
	if (x >= y)
		return x;
	else
		return y;
}

template<class elemType>
int binarySearchTree<elemType>::nodeCount(nodeType<elemType> *p) const//recursive func to count the nodes
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template <class elemType>
int binarySearchTree<elemType>::leavesCount(nodeType<elemType> *p) const//recursive func to count leaves
{
	if (p == NULL)
		return 0;
	else
		if (p->lLink == NULL && p->rLink == NULL)
			return 1;
		else
			return leavesCount(p->lLink) + leavesCount(p->rLink);
}
template <class elemType>
void binarySearchTree<elemType>::insert(const elemType& insertItem)//func to insert a new element to tree
{
	nodeType<elemType> *curr;
	nodeType<elemType> *trailCurr;
	nodeType<elemType> *newNode;

	newNode = new nodeType<elemType>;
	trailCurr = new nodeType<elemType>;
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
		curr = root;

		while (curr != NULL)
		{
			trailCurr = curr;

			if (curr->info == insertItem)
			{
				curr->count++;
				return;
			}
			else if (curr->info > insertItem)
				curr = curr->lLink;
			else
				curr = curr->rLink;
		}

		if (trailCurr->info > insertItem)
		{
			trailCurr->lLink = newNode;
			trailCurr->lLink->count++;
		}
		else
		{
			trailCurr->rLink = newNode;
			trailCurr->rLink->count++;
		}
	}
}
template <class elemType>
void binarySearchTree<elemType>::deleteFromTree(nodeType<elemType>* &p)//deletes a node from tree
{
	nodeType<elemType> *curr;
	nodeType<elemType> *trailCurr;
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
			curr = p->lLink;
			trailCurr = NULL;

			while (curr->rLink != NULL)
			{
				trailCurr = curr;
				curr = curr->rLink;
			}

			p->info = curr->info;
			p->count = curr->count;

			if (trailCurr == NULL)
				p->lLink = curr->lLink;
			else
				trailCurr->rLink = curr->lLink;

			delete curr;
		}
	}
}
template <class elemType>
bool binarySearchTree<elemType>::search(const elemType& searchItem) const//search an item from tree whether its in the tree
{
	nodeType<elemType> *curr;
	bool found = false;

	if (root == NULL)
		cout << "empty tree..." << endl;
	else
	{
		curr = root;

		while (curr != NULL && !found)
		{
			if (curr->info == searchItem)
				found = true;
			else if (curr->info > searchItem)
				curr = curr->lLink;
			else
				curr = curr->rLink;
		}
	}

	return found;
}
template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType& deleteItem)//deletes an element from tree
{
	nodeType<elemType> *curr;
	nodeType<elemType> *trailCurr;
	bool found = false;

	if (root == NULL)
		cout << "Cannot delete from an empty tree."
		<< endl;
	else
	{
		curr = root;
		trailCurr = root;

		while (curr != NULL && !found)
		{
			if (curr->info == deleteItem)
				found = true;
			else
			{
				trailCurr = curr;

				if (curr->info > deleteItem)
					curr = curr->lLink;
				else
					curr = curr->rLink;
			}
		}

		if (curr == NULL)
			cout << "The item to be deleted is not in the tree."
			<< endl;
		else if (found)
		{
			if (curr == root)
				deleteFromTree(root);
			else if (trailCurr->info > deleteItem)
				deleteFromTree(trailCurr->lLink);
			else
				deleteFromTree(trailCurr->rLink);
		}
		else
			cout << "The item to be deleted is not in the tree."
			<< endl;
	}
}

#endif