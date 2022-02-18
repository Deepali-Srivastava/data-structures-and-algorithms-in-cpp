/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
using namespace std;

int fib(int n);		

int main( )
{
	int terms;
	cout << "Enter number of terms : ";
	cin >> terms;
	
	for(int i=0; i<terms; i++)
		cout << fib(i) << "   ";
	cout << "\n" ;
}

int fib(int n)		
{
	if( n == 0 )
		return 0;
	if( n == 1 )
		return 1;
	return fib(n-1) + fib(n-2) ;
}

