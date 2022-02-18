/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
using namespace std;

int sumDigits(long int n);

int main( )
{
	long int num;
	cout << "Enter a number : ";
	cin >> num;
	cout << "Sum of digits of " << num << " is " << sumDigits(num) << "\n";
}

int sumDigits(long int n)
{
	if( n/10 == 0 ) 
		return n;
	return sumDigits(n/10) + n%10;		
}

