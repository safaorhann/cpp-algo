#pragma once
#ifndef H_graph
#define H_graph
#include "linkedListIterator.h"
#include "unorderedLinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cfloat>
#include <string>


using namespace std;

class Graph //class to create graph structure 
{
public:
	bool isEmpty() const;//checks the graph if it is empty
	void clearGraph();//deletes  the graph
	void printGraph() const;//displays the graph
	void createGraph();//creates the graph
	void matrix(string s);//creates a matrix from a given string
	void dfsTraverse();//alghorithm tp travel the graph
	void bfsTraverse();//alghorithm tp travel the graph
	Graph(int size);//constructure
	~Graph();//destructure

protected:
	unorderedLinkedList<int> *graphList;
	int maxSize;
	int gSize;
	double *thesmallestWeight;
	double **weights;
	double aMatrix[10][10];

private:
	void dfs(int v, bool done[]);
	void bfs(int v, bool done[]);
};

bool Graph::isEmpty() const
{
	return (gSize == 0);
}

void Graph::clearGraph()
{
	int i;

	for (i = 0; i < gSize; i++)
		graphList[i].destroyList();

	gSize = 0;
}

void Graph::printGraph() const
{
	int i;

	cout << "Adjacency List"<<endl;
	for (i = 0; i < gSize; i++)
	{
		cout << i << ": ";
		graphList[i].print();
		cout << endl;
	}

	cout << endl;
	cout << "Weight Matrix"<<endl;
	for (int i = 0; i < gSize; i++) {
		for (int j = 0; j < gSize; j++)
			if (weights[i][j] == DBL_MAX)
				cout << "inf \t";
			else
				cout << weights[i][j] << "\t";
		cout << endl;
	}
}

void Graph::matrix(string s)
{
	gSize = 10;
	string s1, s2;
	int temp1, temp2, temp3;
	char c = s[0];
	s2 += c;
	temp3 = stoi(s2);
	for (int i = 0; i < gSize; i++)
		aMatrix[temp3][i] = DBL_MAX;
	aMatrix[temp3][temp3] = 0;
	for (size_t i = 2; i < s.length(); i++)
	{
		if (s[i] != ' ')
			s1 += s[i];
	}
	temp1 = stoi(s1);
	for (int i = 0; i < gSize; i++)
	{
		temp2 = temp1 % 10;
		aMatrix[temp3][temp2] = 1;
		temp1 /= 10;
		if (temp1 == 0)
			return;
	}

}

void Graph::createGraph()
{
	gSize = 10;
	for (int i = 0; i < gSize; i++)
	{
		for (int j = 0; j < gSize; j++)
		{
			weights[i][j] = aMatrix[i][j];
			if (aMatrix[i][j] != 0 && aMatrix[i][j] != DBL_MAX)
				graphList[i].insertLast(j);
		}
	}
}

void Graph::dfsTraverse()
{
	bool *done = new bool[gSize];
	for (int i = 0; i < gSize; i++)
		done[i] = false;
	dfs(0, done);
}

void Graph::bfsTraverse()
{
	bool *done = new bool[gSize];
	for (int i = 0; i < gSize; i++)
		done[i] = false;
	bfs(0, done);
}

Graph::Graph(int size = 0)
{
	maxSize = size;
	gSize = 0;
	graphList = new unorderedLinkedList<int>[size];
	weights = new double*[size];

	for (int i = 0; i < size; i++)
		weights[i] = new double[size];

	thesmallestWeight = new double[size];
}

Graph::~Graph()
{
	for (int i = 0; i < gSize; i++)
		delete[] weights[i];

	delete[] weights;
	delete thesmallestWeight;
	clearGraph();
}

void Graph::dfs(int vertex, bool done[])
{
	int k;
	cout << "\nDFS: ";
	cout << vertex << " -> ";
	int temp = vertex;
	for (int i = 1; i < gSize; i++)
	{
		k = 0;
		while (aMatrix[temp][k] == DBL_MAX || aMatrix[temp][k] == 0)
			k++;
		if (done[k] == false)
		{
			cout << k << " -> ";
			temp = k;
		}
		else
		{
		start:
			if (k < gSize)
				k++;
			else
			{
				vertex = temp;
				k = 0;
			}
			if (aMatrix[vertex][k] == 1 && done[k] == false)
			{
				cout << k << " -> ";
				temp = k;
			}
			else
				goto start;

		}
		done[k] = true;
	}
	cout << "NULL" << endl;
}

void Graph::bfs(int vertex, bool done[])
{
	int j, k, z; j = k = z = 0;
	cout << "\nBFS: ";
	cout << vertex << " -> ";
	int temp = vertex;
	for (int i = 1; i < gSize - 1; i++)
	{
	start:
		while ((aMatrix[temp][j] == DBL_MAX || aMatrix[temp][j] == 0) && j < gSize)
			j++;
		if (j < gSize)
		{
			if (done[j] == false)
			{
				cout << j << " -> ";
			}
			else
				goto start2;
			done[j] = true;
			j++;
		}
		else
		{
		start2:
			j = 0;
			while (done[k] == false)
				k++;
			temp = k;
			if (k < gSize - 1)
				k++;
			else
			{
				k = 0;
				while (done[k] == false)
					k++;
				goto start;
			}
			goto start;
		}
	}
	j = 1;
	while (done[j] == true)
		j++;
	cout << j << " -> ";
	cout << "NULL" << endl;
}
#endif