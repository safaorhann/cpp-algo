#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include "huffman.h"
#include <fstream>
#include<stdlib.h>
/*

SAFA ORHAN
*/
using namespace std;

int freq(string s,char c)
{
	int count = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == c)
			count++;
	return count;
}

int main() 
{
	huffmanTree obj;
	string s="Hey, Jude, don’t make it bad"
		"Take a sad song and make it better"
		"Remember to let her into your heart"
		"Then you can start to make it better";
	string s1,s2;

	for (int i = 0; i < s.length(); i++)
	{
		s2 = s[i];
		if (!obj.search(s2)) {
			s1 = s[i];
			obj.insert(freq(s, s[i]),s1);
			s1.erase();
		}
	}
	obj.sortvector();
	obj.createHuffmanTree();
	ofstream codefile,asciifile;
	codefile.open("code.txt");
	for (int i = 0; i < s.length(); i++)
	{
		s2 = s[i];
		codefile << obj.get_code(s2)<<" ";
	}
	asciifile.open("ascii.txt");
	for (int i = 0; i < s.length(); i++)
	{
		char asci[100];
		int num = int(s[i]);
		_itoa_s(num, asci, 2);
		asciifile << asci << " ";
	}
	system("pause");
	return 0;
}