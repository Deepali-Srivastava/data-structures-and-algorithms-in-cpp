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
	int i,j, minIndex, temp;

	for( i=0; i<n-1; i++ )
	{
		/* Find the index of smallest element */
		minIndex = i;
		for( j=i+1; j<n ; j++ )
		{
			if( a[minIndex] > a[j] )
				minIndex = j;
		}
		if( i != minIndex )
		{
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp ;
		}
	}
}






