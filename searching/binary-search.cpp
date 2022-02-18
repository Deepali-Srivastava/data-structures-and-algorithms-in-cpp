/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 50
int search(int a[], int n, int searchValue);

int main()
{
	int a[MAX], n, searchValue;

	cout << "Enter the number of elements : ";
	cin >> n;

	cout << "Enter the elements in sorted order : \n";
	for( int i=0; i<n; i++ )
		cin >> a[i];

	cout << "Enter the search value : ";
	cin >> searchValue;
	
	int index = search(a, n, searchValue);
	
	if( index == -1 )
		cout << searchValue << " not present in the array\n";
	else
		cout << searchValue << " present at index " << index << "\n";
}

int search(int a[], int n, int searchValue)
{
	int first=0, last=n-1, mid;

	while( first <= last )
	{
		mid = (first + last)/2;
		
		if( searchValue < a[mid] )
			last = mid-1;	/* Search in left half */
		else if( searchValue > a[mid] )
			first = mid+1;	/* Search in right half */
		else
			return mid;		/* searchValue present at index mid */
	 }
	 return -1;
}