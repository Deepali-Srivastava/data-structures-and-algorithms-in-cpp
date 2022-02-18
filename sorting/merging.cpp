/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 20

void merge(int a1[], int a2[], int temp[], int n1, int n2);

int main()
{
	int a1[MAX], a2[MAX], temp[2*MAX], n1, n2, i;

	cout << "Enter the number of elements in array1 : ";
	cin >> n1;
	cout << "Enter all the elements in sorted order :\n";
	for(i=0; i<n1; i++)
	{
		cout << "Enter element " << i+1 << " : ";
		cin >> a1[i];
	}
	
	cout << "Enter the number of elements in array2 : ";
	cin >> n2;
	cout << "Enter all the elements in sorted order :\n";
	for(i=0; i<n2; i++)
	{
		cout << "Enter element " << i+1 << " : ";
		cin >> a2[i];
	}
	
	merge( a1, a2, temp, n1, n2);
	
	cout << "\n\nMerged array  : ";
	for( i=0; i<n1+n2; i++)
		cout << temp[i] << "  ";
	cout << "\n";
}

void merge(int a1[], int a2[], int temp[], int n1, int n2)
{
	int i = 0;  	/* Index for first array */
	int j = 0;  	/* Index for second array */
	int k = 0;  	/* Index for merged array */

	while( i<=n1-1  && j<=n2-1 )
	{
		if( a1[i] < a2[j])
			temp[k++] = a1[i++];
		else
			temp[k++] = a2[j++];
	}

	/* Put remaining elements of a1 into temp */
	while( i <= n1-1 )
		temp[k++] = a1[i++];
	
	/* Put remaining elements of a2 into temp */
	while( j <= n2-1 )
		temp[k++] = a2[j++];
}







