/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 30
void sort(int a[], int n);
void buildHeapBottomUp(int a[], int n);
void restoreDown(int i, int a[], int n);

int main()
{
	int a[MAX], n;

	cout << "Enter the number of elements : ";
	cin >> n;
	
	for( int i=1; i<=n; i++ )
	{
		cout << "Enter element " << i << ": " ;
		cin >> a[i];
	}

	sort(a,n);
	
	cout << "Sorted array is : "; 
	for( int i=1; i<=n; i++ )
		cout << a[i] << " ";
	cout << "\n";
}

void sort(int a[], int n)
{
	buildHeapBottomUp(a,n);

	cout << "Heap is : \n";
	for( int i=1; i<=n; i++ )
		cout << a[i] << " ";
	cout << "\n";

	int maxValue;
    while(n > 1)
    {
		maxValue = a[1];
        a[1] = a[n];
        a[n] = maxValue;
        n--;
        restoreDown(1, a, n);
    }
}

void buildHeapBottomUp(int a[], int n)
{
	for( int i=n/2; i>=1; i-- )
		restoreDown(i, a, n);
}

void restoreDown(int i, int a[], int n)
{
	int k = a[i];
	
	int lchild = 2*i, rchild = lchild+1;
		
	while( rchild <= n )
	{
		if( k>=a[lchild] && k>=a[rchild] )  
		{
			a[i] = k;
			return;
		}
		else if( a[lchild] > a[rchild] )
		{
			a[i] = a[lchild]; 
			i = lchild;
		}
		else
		{
			a[i] = a[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}
	/*If number of nodes is even*/	
	if(lchild == n && k < a[lchild] ) 
	{
		a[i] = a[lchild];
		i = lchild;
	}
	a[i] = k;
}