/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

#define MAX 100
#include"node.h"
#include"sorted.h"

void sort(int a[], int n);
int hashFn(int x, int large);

int main()
{
	int i, n, a[MAX];

	cout << "Enter the number of elements : ";
	cin >> n;

	for( i=0; i<n; i++ )
	{
		cout << "Enter element "  << i+1 << " : ";
		cin >> a[i];
	}
	
	sort(a,n);

	cout << "Sorted array is :\n";
	for( i=0; i<n; i++ )
		cout << a[i] << "  ";
	cout << "\n";
}
        
void sort(int a[], int n)
{
	SortedLinkedList list[6];
	
	int i;

	int large = 0;
    for (i = 0; i < n; i++)
    {
		if (a[i] > large)
			large = a[i];
    }
	        
	int x;
	for( i=0; i<n; i++ )
	{
		x = hashFn( a[i], large);
		list[x].insert(a[i]);
	}

	cout << "\n";

   /*Elements of linked lists are copied to array*/
   Node *p;
   i = 0;
   for (int j = 0; j <= 5; j++)
   {
		p = list[j].getStart();
        while( p != NULL )
        {
			a[i++] = p->info;
            p = p->link;
		}
    }
}
		    
int hashFn(int x, int large)
{
	float temp;
    temp = (float)x / large;
    return (int)(temp * 5);
}
	
