/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "Node.h"
#include "StackChar.h"

using namespace std;
#define MAX 100

bool isValid(char expr[]);
bool matchParentheses(char leftPar, char rightPar);

int main()
{
	char expression[MAX];
	
	cout<<"Enter an expression with parentheses : ";
	gets(expression);

	if( isValid(expression) )
		cout<<"Valid expression\n";
	else
		cout<<"Invalid expression\n";
}


bool isValid(char expr[])
{
	Stack st;
		  	    
    for ( int i = 0; i < strlen(expr); i++)
	{
		if ( expr[i] == '(' || expr[i] == '{' || expr[i] == '[' )
	  		st.push(expr[i]);
		
		if ( expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
	  		if ( st.isEmpty() )    
	  		{
	  			cout << "Right parentheses are more than left parentheses\n";
	  			return false;
	  		}
	  		else
	  		{
	  			char ch = st.pop();
	  			if ( !matchParentheses( ch,expr[i]) ) 
	  			{
	  				cout << "Mismatched parentheses are : "; 
	  				cout << ch << " and "  << expr[i] << "\n";	
	  				return false;
	  			}
		    }
	  }

	  if( st.isEmpty() ) 
	  {
			cout << "Balanced Parentheses\n"; 
	  		return true;
	  }
	  else 
	  {
			cout << "Left parentheses are more than right parentheses\n";	
	  		return false;
	  }
}

bool matchParentheses(char leftPar, char rightPar)
{
	if( leftPar == '[' && rightPar == ']' )
		return true;
    if( leftPar == '{' && rightPar == '}' )
		return true;
    if( leftPar == '(' && rightPar == ')' )
		return true;
    return false;
}


