/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
using namespace std;

float power(float x , int n);

int main( )
{
	float x;
	int n;
	cout << "Enter x and n : ";
	cin >> x >> n;
	cout << power(x, n) << "\n";
}

float power(float x , int n)
{
	if(n == 0)
		return 1;
	else
		return x * power(x,n-1);
}

