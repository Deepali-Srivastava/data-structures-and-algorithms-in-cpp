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
	int x,j,temp,swaps;

	for( x=n-1; x>=1; x-- )
	{
		swaps = 0;
		for( j=0; j<x; j++ )
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swaps++;
			}
		}
		if( swaps == 0 ) /*If list is sorted*/
			break;
	}
}

//void sort(int a[], int n)
//{
//	int x,j,temp;
//
//	for( x=n-1; x>=1; x-- )
//	{
//		for( j=0; j<x; j++ )
//		 {
//			if(a[j] > a[j+1])
//			{
//				temp = a[j];
//				a[j] = a[j+1];
//				a[j+1] = temp;
//			}
//		}
//	}
//}

