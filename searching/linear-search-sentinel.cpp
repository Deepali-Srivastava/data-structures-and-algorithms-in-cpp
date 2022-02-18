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

	cout << "Enter the elements : \n";
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
	a[n] = searchValue;

    int i = 0;
    while( searchValue != a[i] )
		i++;

    if( i < n )
		return i;
    else
		return -1;
}
