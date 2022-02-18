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
	int i, j, temp;

	for( i=1; i<n; i++ )
	{
		temp = a[i]; 
		
		for( j=i-1; j>=0 && a[j]>temp; j-- )
			a[j+1] = a[j];
		a[j+1] = temp;
	}
}


