/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

void print1(int n);
void print2(int n);

int main()
{
	int n;
	cout << "Enter the value of n : ";
	cin >> n;
	
	print1(n);
	cout << "\n";

	print2(n);
	cout << "\n";
}

void print1(int n)
{
	if( n == 0 )
	   return;
	cout << n << " ";	
	print1( n-1 );
}

void print2(int n)
{
	if( n == 0 )
	   return;
	print2( n-1 );
	cout << n << " ";	
}
