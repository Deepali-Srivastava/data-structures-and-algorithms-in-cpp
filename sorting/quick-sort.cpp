/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 20
void sort(int a[], int n);
void sort(int a[], int low, int up);
int partition(int a[], int low, int up);

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
	sort(a, 0, n-1);
}

void sort( int a[], int low, int up )
{
	if( low >= up )
		return;
	int p = partition(a, low, up);
	sort(a, low, p-1); /* Sort left sublist */
	sort(a, p+1, up);  /* Sort right sublist */
}

int partition(int a[], int low, int up)
{	
	int pivot = a[low];

	int i = low+1; /* moves from left to right */
	int j = up;    /* moves from right to left */

	int temp;
	
	while( i <= j )
	{
		while( a[i] < pivot && i < up )    
			i++;
		
		while( a[j] > pivot )	
			j--;
		
		if( i < j ) /* swap a[i] and a[j] */
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else /* found proper place for pivot */
			break;
	}

	/* Proper place for pivot is j */
	a[low] = a[j];
	a[j] = pivot;
	
	return j;
}



