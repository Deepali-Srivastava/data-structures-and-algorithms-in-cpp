/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
using namespace std;
#include"node.h"

Node* sort(Node *start);
int digitsInLargest(Node *start);
int digit(int n, int k);

int main()
{
	Node *temp, *p;
	int n, item;

	cout << "Enter the number of elements in the list : ";
	cin >> n;
	
	Node *start = NULL;

	for( int i=0; i<n; i++ )
	{
		cout << "Enter element " << i+1 << " : ";
		cin >> item;

		/* Inserting elements in the linked list */
		temp = new Node(item);
		
		if( start == NULL ) /* Inserting first element */
			start = temp;
		else
		{
			p = start;
			while( p->link != NULL )
				p = p->link;
			p->link = temp;
		}
	}

	start = sort(start);
	cout << "Sorted list is :\n";
	
	p=start;
	while(p !=NULL)
	{
		cout << p->info << "  ";
		p = p->link;
	}
	cout << "\n";
}

Node* sort(Node *start)
{
	Node *rear[10], *front[10];

	int leastSigPos = 1;
    int mostSigPos = digitsInLargest( start );

    int i, dig;
    Node *p;

	for( int k = leastSigPos; k <= mostSigPos; k++ ) 
	{
		/* Make all the queues empty at the beginning of each pass */
		for(i=0; i<=9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL;
		}
		
		for( p=start; p!=NULL; p=p->link )
		{
			/* Find kth digit from right in the number */
			dig = digit(p->info, k);
		
			/* Insert the node in Queue(dig) */
			if(front[dig] == NULL)			
				front[dig] = p ;
			else
				rear[dig]->link = p;
			rear[dig] = p;
		}
		
		/* Join all the queues to form the new linked list */
		i=0;
		while(front[i] == NULL) /* Finding first non empty queue */
			i++;

		start = front[i];	
		while( i<=8 ) 
		{
			if( rear[i+1] != NULL ) /* if (i+1)th  queue is not empty */
				rear[i]->link = front[i+1]; /* join end of ith queue to start of (i+1)th queue*/
			else
				rear[i+1] = rear[i];  /* continue with rear[i] */
			i++;
		}
		rear[9]->link = NULL;
	}
	return start;
}
                      
/* Returns number of digits in the largest element of the list */
int digitsInLargest(Node *start)
{
	/* Find largest element */
	Node *p = start;
	int large = 0;
	while(p != NULL)
	{
		if(p->info > large)
			large = p->info;
		p = p->link;
	}
	
	/*Find number of digits in largest element*/
	int ndigits = 0;
	while( large != 0 )
	{
		ndigits++;
		large /= 10;
	}
	return ndigits;
} 
       
/*Returns kth digit from right in n*/
int digit(int n, int k)
{
	int d=0, i;
	for(i=1; i<=k; i++)
	{
		d = n % 10 ;
		n /= 10;
	}
	return d;
}

        

