/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 100
#include"bst.h"

void sort(int a[], int n);
	
int main()
{
	int a[MAX], n, i;
	
	cout << "Enter the number of elements : ";
	cin >> n;

	for( i=0; i<n; i++ )
	{
		cout << "Enter element " << i+1 << " : ";
		cin >> a[i];
	}

	sort(a,n);
    
	cout<<"\nSorted array is :\n";
	for( i=0; i<n; i++ )
		cout<<a[i] << " ";
	cout << "\n";
}

void sort(int a[], int n)
{
	BinarySearchTree tree;

    for( int i = 0; i < n; i++ )
		tree.insert( a[i] );
    tree.inorder1( a );
}
