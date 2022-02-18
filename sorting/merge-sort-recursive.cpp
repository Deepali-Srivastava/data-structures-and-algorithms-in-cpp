/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 20

void sort( int a[], int n );
void sort( int a[], int low, int up );
void merge( int a[], int temp[], int low1, int up1, int low2, int up2 );
void copy( int a[], int temp[], int low, int up );

int main()
{
	int i, n, a[MAX];
	
	cout << "Enter the number of elements : ";
	cin >> n;
	
	for( i=0; i<n; i++ )
	{
		cout << "Enter element " << i+1 << " : ";
		cin >> a[i];
	}

	sort(a,n);

	cout << "\nSorted array is :\n";
	for( i=0; i<n; i++ )
		cout << a[i] << "  ";
	cout << "\n";
}

void sort(int a[], int n)
{
	sort(a, 0, n-1);
}

void sort(int a[], int low, int up)
{
	int mid, temp[MAX];

	if( low == up ) /* if only one element */
		return;
	
	mid = (low+up) / 2;
	sort( a, low , mid );  /* Sort a[low]....a[mid] */
	sort( a, mid+1, up );  /* Sort a[mid+1]....a[up] */

	/* Merge a[low]...a[mid] and a[mid+1]....a[up] to temp[low]...temp[up] */
	merge( a, temp, low, mid, mid+1, up ); 

	/* Copy temp[low]...temp[up] to a[low]...a[up] */ 
	copy( a, temp, low, up );	
}

/* a[low1]...a[up1] and a[low2]...a[up2] merged to temp[low1]..temp[up2] */
void merge(int a[], int temp[], int low1, int up1, int low2, int up2)
{
	int i = low1;  	
	int j = low2;  	
	int k = low1;  	

	while( i<=up1 && j<=up2 )
	{
		if( a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while( i<=up1 )
		temp[k++] = a[i++];
	
	while( j<=up2 )
		temp[k++] = a[j++];
}

void copy( int a[], int temp[], int low, int up )
{
	int i;
	for( i=low; i<=up; i++)
		a[i] = temp[i];
}
