/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

void buildHeapTopDown(int a[], int n);
void buildHeapBottomUp(int a[], int n);
void restoreUp(int i, int a[]);
void restoreDown(int i, int a[], int n);

int main()
{
	int a1[] = {99999,1,4,5,7,9,10};
	int n1 = 6;
		
	buildHeapBottomUp(a1,n1);
		
	for( int i = 1; i <= n1; i++ )
		cout << a1[i] << " ";
	cout << "\n";
		
	int a2[] = {99999,1,4,5,7,9,10};
	int n2 = 6;
		
	buildHeapTopDown(a2,n2);
	for (int i = 1; i <= n2; i++ )
		cout << a2[i] << " ";
	cout << "\n";
}

void buildHeapBottomUp(int a[], int n)
{
	for (int i=n/2; i>=1; i--)
		restoreDown(i, a, n);
}

void buildHeapTopDown(int a[], int n)
{
	for (int i=2; i<=n; i++)
		restoreUp(i, a);
}

void restoreUp(int i, int a[])
{
	int k = a[i];  
	int iparent = i/2;
	
	while( a[iparent] < k  )  /* No sentinel - while(iparent>=1 && a[iparent]<k) */
	{
		a[i] = a[iparent];
		i = iparent;
		iparent = i/2;
	}
	a[i] = k; 
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


