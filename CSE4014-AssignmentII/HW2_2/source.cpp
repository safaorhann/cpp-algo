#include "graph.h"
#include <iostream>
#include <string>
#include <fstream>
/*
 
SAFA ORHAN
*/
using namespace std;

int main()
{
	Graph obj(10);
	string s;
	ifstream infile; 
	infile.open("safaORHAN.txt"); 

	if (!infile)
	{
		cout << "Can't open the file." << endl;
		return true;
	}
	getline(infile, s); 
	while (infile) 
	{
		obj.matrix(s);
		getline(infile, s);
	}
	infile.close(); 
	obj.createGraph();
	obj.printGraph();
	obj.bfsTraverse();
	obj.dfsTraverse();

	system("pause");
	return 0;
}