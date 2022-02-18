/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 20
void sort(int a[], int n);

int main()
{
	int a[MAX], n;

	cout << "Enter the number of elements : ";
	cin >> n;
	
	for( int i=0; i<n; i++ )
	{
		cout << "Enter element " << i+1 << ": " ;
		cin >> a[i];
	}

	sort(a,n);
	
	cout << "Sorted array is : "; 
	for( int i=0; i<n; i++ )
		cout << a[i] << " ";
	cout << "\n";
}

void sort(int a[], int n)
{
	int i, j, h, temp;
	
	cout << "\nEnter maximum increment (odd value) : " ;
	cin >> h;
	
	while( h>=1 )
	{
		for( i=h; i<n; i++ )
		{
			temp = a[i];
			for( j=i-h; j>=0 && temp<a[j]; j=j-h )
				a[j+h] = a[j];
			a[j+h] = temp;
		}
		h = h-2; 
	}
}
