/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include"heap.h"

Heap :: Heap(int sz)
{
	maxSize = sz;
	a = new int[maxSize];
	n = 0;
	a[0] = MAX_VAL; 
}

Heap :: ~Heap()
{
	delete[] a;
}

bool Heap :: isEmpty()
{ 
	return n == 0;
}

void Heap :: display()
{       
	int i;
	if( n == 0 )
	{
		cout << "Heap is empty\n";
		return;
	}
	for( i=1; i<=n; i++ )
		cout << a[i] << " ";
	cout << "\n";

	cout << "Number of elements = " << n << "\n";
}
void Heap :: insert(int value)
{
	if( n == maxSize )
	{
		cout << "Can't insert more ";
		return;
	}
	n++;    
	a[n] = value;
	restoreUp(n);
}

void Heap :: restoreUp(int i)
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

int Heap :: deleteRoot()
{
	int maxValue = a[1];  
	a[1] = a[n]; 
	n--;   
	restoreDown(1);
	return maxValue;
}

void Heap :: restoreDown(int i)
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



