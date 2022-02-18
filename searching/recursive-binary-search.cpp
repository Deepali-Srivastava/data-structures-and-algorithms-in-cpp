/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 50
int search(int a[], int n, int searchValue);
int search(int a[], int first, int last, int searchValue);

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
	return search(a, 0, n-1, searchValue);
}

int search(int a[], int first, int last, int searchValue)
{
	if( first > last )
		return -1;
	
	int mid = (first + last) / 2;

    if( searchValue > a[mid] ) 			/*Search in right half */
		return search(a, mid+1, last, searchValue);
    else if (searchValue < a[mid])		/*Search in left half */
        return search(a, first, mid-1, searchValue);
    else
		return mid;
}