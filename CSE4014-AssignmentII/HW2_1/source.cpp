#include <iostream>
#include "binaryTree.h"
/*

SAFA ORHAN
*/
using namespace std;

int main()
{
	binarySearchTree<char> Root;

	Root.insert('a');
	Root.insert('b');
	Root.insert('c');
	Root.insert('f');
	Root.insert('s');
	Root.insert('b');
	Root.insert('h');
	Root.insert('f');
	Root.insert('a');
	Root.insert('a');

	cout << endl << "Preorder traverse: ";
	Root.preorderTraversal();
	cout << endl;

	cout << "Height: " << Root.treeHeight()<< endl;
	cout << "Number of Nodes: "<< Root.treeNodeCount() << endl;
	
	Root.deleteNode('a');
	cout << "after deleting 'a' for one time" << endl;
	Root.preorderTraversal();


	system("pause");
	return 0;
}