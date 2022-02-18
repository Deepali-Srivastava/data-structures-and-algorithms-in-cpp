/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

long int factorial(int n);
long int sum(int n);

int main()
{
	int num;
	
	cout << "Enter a number greater than or equal to 0 : ";
	cin >> num;

	cout << "Factorial of " << num << " is "  << factorial(num) << "\n";
	cout << "Sum of numbers from  1 to " << num << " is "  << sum(num) << "\n";
}

long int factorial(int n)
{
	if(n == 0)
		return 1;
	return n * factorial(n-1);
}

long int sum(int n)
{
	if(n == 1)
		return 1;
	return n + sum(n-1);
}

