#pragma once
#include <string>
#include "stack.h"

using namespace std;

class infixToPostfix
{
public:
	void setInfix(string);
	void showInfix();
	void showPostfix();
	int operation_precedence(char c);
private:
	void convertToPostfix();
	string  infx;
	string  pfx;
};

int infixToPostfix::operation_precedence(char c)//it calculates the precedence of operators,when we reach the operator we need to check the precedence 
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;

}

void infixToPostfix::setInfix(string infix)//this func sets the coming string to the infx
{
	infx = infix;
}


void infixToPostfix::showInfix()//it displays the infx string
{
	cout << infx;
	cout << endl;
}

void infixToPostfix::showPostfix()//it simply displays the pfx but because convertToPostfix() is private function we firstly call this func then display the pfx
{
	convertToPostfix();
	cout << pfx;
	cout << endl;
}

void infixToPostfix::convertToPostfix()
{
	//This function basically convert the infix notation to the postfix notation and to do this we are given an algorithm
	//
	stackType<char> op;// we define a stack
	op.push('S');//we initialize the stack with a random element so we can easily check when we are out of operators.
	int length = infx.length();
	pfx = "";//we initialize the pfx to an empty exp
	int i = 0;
	while(i < length) {// we first need a loop to reach all the elements
		//we check the every element 
		if ((infx[i] >= 'a' && infx[i] <= 'z') || (infx[i] >= 'A' && infx[i] <= 'Z'))//if its operand we push it to the stack
		{
			pfx += infx[i];
			i++;
		}
		else if (infx[i] == '(')//if its left parenthesis it means there is gonna be precedence,we simply push it to the stack
		{
			op.push(infx[i]);
			i++;
		}
		else if (infx[i] == ')')//if we reach the right parenthesis untill we reach '(' or reach the first element we pop all the elements  
			//from the stack and add them to the pfx and after that we check if there is still '(' and pop it from the stack 
		{
			while (op.top() != 'S' && op.top() != '(') {
				char c1 = op.top();
				op.pop();
				pfx += c1;
			}
			if (op.top() == '(')
				op.pop();
			i++;
		}
		else//if coming element is operator
		{
			while (op.top() != 'S' && operation_precedence(infx[i]) <= operation_precedence(op.top()))//Pop and add all of the operators from the stack to pfx that are above the most recent left
				//parentheses and have precedence greater than or equal to infx[i].
			{
				char c1 = op.top();
				op.pop();
				pfx += c1;
			}
			op.push(infx[i]);//push it to the stack
			i++;
		}

	}
	while (op.top() != 'S')// after all if there are some operator pop them from stack and add them to px
	{
		char c1 = op.top();
		op.pop();
		pfx += c1;
	}

}