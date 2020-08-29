#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

struct huffmanNode
{
	int frequency;
	string info;
	string code;
	huffmanNode *leftChild;
	huffmanNode *rightChild;
};

class huffmanTree
{
	vector<huffmanNode>huff_arr;
	vector<huffmanNode>::iterator iter;
	int count =0 ;
public:
	void insert(int f, string s);
	void createHuffmanTree();
	string get_code(string s);
	void display();
	void sortvector();
	bool search(string c);
};

void huffmanTree::insert(int f, string s)
{
	huffmanNode newnode;
	newnode.leftChild = newnode.rightChild = NULL;
	newnode.code = "";
	newnode.frequency = f;
	newnode.info = s;
	huff_arr.push_back(newnode);
}
void huffmanTree::createHuffmanTree()
{
	//iter = unique(huff_arr.begin(), huff_arr.end(), [](huffmanNode  &a, huffmanNode const &b) {return a.info != b.info; });
	//huff_arr.resize(distance(huff_arr.begin(), iter));
	while (!huff_arr.empty()) {
		vector<huffmanNode>::iterator pos = huff_arr.begin();
		huffmanNode newnode, *temp = new huffmanNode, *temp1 = new huffmanNode;
		*temp = huff_arr.front();
		huff_arr.erase(pos);
		pos = huff_arr.begin();
		*temp1 = huff_arr.front();
		huff_arr.erase(pos);
		newnode.frequency = temp->frequency + temp1->frequency;
		newnode.info = temp->info + temp1->info;
		newnode.code = "";
		newnode.leftChild = temp;
		newnode.rightChild = temp1;
		huff_arr.push_back(newnode);
		sort(huff_arr.begin(), huff_arr.end(), [](huffmanNode  &a, huffmanNode const &b) {return a.frequency < b.frequency; });
		if (huff_arr.size() == 1)
			break;
	}
	//cout<<huff_arr[0].rightChild->leftChild->rightChild->info<<endl;
	
}
string huffmanTree::get_code(string s)
{
	huffmanNode head = huff_arr[0];
	string temp, cod;
	bool found = 0;
	while (head.leftChild != NULL && head.rightChild != NULL)
	{
		found = false;
		temp = head.leftChild->info;
		string ss;
		if (temp == s && temp.length() == s.length())
			found = 1;
		else {
			for (int i = 0; i < temp.length(); i++)
			{
				ss = temp[i];
				if (ss == s)
					found = 1;

			}
		}
		if (found == 0)
		{
			cod += "1";
			head = *(head.rightChild);
		}
		else
		{
			cod += "0";
			head = *(head.leftChild);
		}
	}
	return cod;
}
bool huffmanTree::search(string c)
{
	for (int i = 0; i < huff_arr.size(); i++)
		if (huff_arr[i].info == c)
			return 1;
	return 0;
}
void huffmanTree::display()
{
	for (int i = 0; i < huff_arr.size(); i++)
	{
		cout << huff_arr[i].frequency << "" << huff_arr[i].info;
		cout << endl;
	}

}
void huffmanTree::sortvector()
{
	sort(huff_arr.begin(), huff_arr.end(), [](huffmanNode  &a, huffmanNode const &b) {return a.frequency < b.frequency; });
}