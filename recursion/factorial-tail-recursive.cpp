/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

/*Find the factorial of a number by tail recursive method*/

#include<iostream>
using namespace std;

long TailRecursiveFact(int n);
long TRfact(int n, int result);

int main()
{
	int num;
	cout<<"Enter a number : ";
	cin>>num;
	if(num<0)
		cout<<"No factorial for negative number\n";
	cout<<"Factorial of "<<num<<" is "<<TailRecursiveFact(num)<<"\n";
}

/*Tail recursive*/
long TRfact(int n, int result)
{
	if( n==0)
		return result;
	return TRfact(n-1, n*result);
}/*End of TRFact()*/

/*Helper function for tail recursive function*/
long TailRecursiveFact(int n)
{
	return TRfact(n, 1);
}/*End of TailRecursiveFact()*/


