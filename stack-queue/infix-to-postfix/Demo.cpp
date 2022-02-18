/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"StackInt.h"
#include"StackChar.h"

using namespace std;

void infixToPostfix(char infix[], char postfix[]);
int evaluatePostfix(char postfix[]);
int precedence(char symbol);
int power(int b, int a);

int main()
{
	char infix[20], postfix[20];

	cout << "Enter infix expression : ";
	cin >> infix;

	infixToPostfix(infix, postfix);

	cout << "Postfix expression is : " << postfix << "\n";
	
	cout << "Value of expression is : " << evaluatePostfix(postfix) << "\n";
}

void infixToPostfix(char infix[], char postfix[])
{
	StackChar stack;

	unsigned int i,p=0;
	char next, symbol;	
	
	for(i=0; i<strlen(infix); i++)
	{
		symbol = infix[i];
		
		if (symbol == ' ' || symbol == '\t')  /*ignore blanks and tabs*/
			continue;

		switch( symbol )
		{
			case '(':
				stack.push( symbol );
				break;
			case ')':
				while( (next=stack.pop())!='(' )
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while( !stack.isEmpty( ) &&  precedence(stack.peek())>= precedence(symbol) )
					postfix[p++] = stack.pop();
				stack.push(symbol);
				break;
			default: /* operand */
			     postfix[p++] = symbol;
		}
	}
	while( !stack.isEmpty( ) ) 
		postfix[p++] = stack.pop();
	postfix[p]='\0'; 
}

int precedence(char symbol)
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default :
		return 0;
	}
}

int evaluatePostfix(char postfix[])
{
	StackInt stack;
	int a,b,temp;

	for(int i=0; i<strlen(postfix); i++)
	{
		if( postfix[i]<='9' && postfix[i]>='0' )
			stack.push( postfix[i] - '0' );
		else
		{
			a = stack.pop();
			b = stack.pop();
			switch( postfix[i] )
			{
			case '+':
				temp = b+a; break;
			case '-':
				temp = b-a; break;
			case '*':
				temp = b*a; break;
			case '/':
				temp = b/a; break;
			case '%':
				temp = b%a; break;
			case '^':
				temp = power(b,a);
			}
			stack.push( temp );
		}
	}
	return stack.pop();
}

int power(int b, int a)
{
	for(int i=1; i<=a; i++)
		b *= b;
	return b;
}