/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

/*Display and find out the sum of series 1 + 2 + 3 + 4 + 5 +....... */

#include<iostream>
using namespace std;

int series(int n);
int rseries(int n);

int main( )
{
	int n;
	cout<<"Enter number of terms : ";
	cin>>n;
	
	cout<<"\b\b = "<<series(n)<<"\n";	/*  \b to erase last +sign */
	cout<<"\b\b = "<<rseries(n)<<"\n\n\n";
}/*End of main()*/

/*Iterative function*/
int series(int n)
{
	int i, sum=0;
	for(i=1; i<=n; i++)
	{
		cout<<i<<" + ";
		sum+=i;	
	}
	return sum;
}/*End of series()*/

/*Recursive function*/
int rseries(int n)
{
	int sum;
	if(n == 0)
		return 0;
	sum = (n + rseries(n-1));
	cout<<n<<" + ";
	return sum;
}/*End of rseries()*/

