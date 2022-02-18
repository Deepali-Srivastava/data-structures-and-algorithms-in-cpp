/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "single.h"

using namespace std;

SingleLinkedList::SingleLinkedList()
{
	start = NULL;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& L)
{
	if( L.start == NULL )
	{
		start = NULL;
		return;
	}		
	
	Node *p1,*p2;
	p1 = L.start;
	p2 = start = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
}

SingleLinkedList::~SingleLinkedList()
{
	Node *p;
	while( start != NULL )
	{
		p = start->link;
		delete start;
		start = p;
	}
}

SingleLinkedList& SingleLinkedList :: operator=(const SingleLinkedList& L)
{
	if (this == &L)
		return *this;

	Node *p;
	while( start != NULL )
	{
		p = start->link;
		delete start;
		start = p;
	}
	
	if( L.start == NULL )
	{
		start = NULL;
		return *this;
	}	

	Node *p1,*p2;
		
	p1 = L.start;
	p2 = start = new Node(p1->info);
	p1 = p1->link;

	while( p1 != NULL )
	{		
		p2->link = new Node(p1->info);
		p2 = p2->link;
		p1 = p1->link;
	}
	return *this;
}

inline bool SingleLinkedList::isEmpty() const
{
	return start == NULL;
}

void SingleLinkedList::displayList() const
{
	
	if( isEmpty() )
	{
		cout << "List is empty\n";
		return;
	}
	
	cout << "List is :\n";
	Node *p = start;
	while( p != NULL )
	{
		cout << p->info << "  ";
		p = p->link;
	}
	cout << "\n\n";
}

int SingleLinkedList::countNodes() const
{
	Node *p = start;
	int n = 0;
	while( p!=NULL )
	{
		n++;
		p = p->link;
	}
	return n;
}

int SingleLinkedList::find(int x) const
{
	Node *p = start;
	int position = 1;
	while( p != NULL )
	{
		if( p->info == x )
			return position;
		position++;
		p = p->link;
	}
	return 0;
}

void SingleLinkedList::insertAtBeginning(int data)
{
	Node *temp = new Node(data);
	temp->link = start;
	start = temp;
}

void SingleLinkedList::insertAtEnd(int data)
{
	if( isEmpty() )
	{
		insertAtBeginning(data);
		return;
	}
	
	Node *temp = new Node(data);

	Node *p = start;
	while( p->link != NULL )
		p = p->link;
	
	p->link = temp;
}

void SingleLinkedList::createList()
{
	int i,n,data;
	
	cout << "Enter the number of nodes : ";
	cin >> n;
	
	if( n <= 0 )
		return;

	cout << "Enter the first element to be inserted : ";
	cin >> data;
	insertAtBeginning(data);
	
	Node *p = start;
	for( i=2; i<=n; i++ )
	{
		cout << "Enter the next element to be inserted : ";
		cin >> data;
		Node *temp = new Node(data);
	    p->link = temp;
	    p = temp;
	}
}

void SingleLinkedList::insertAfter(int data,int x)
{
	Node *p = start;
	while( p!= NULL )
	{
		if( p->info == x )
		    break;
		p = p->link;
	}
	if( p == NULL )
		cout << x << " not present in the list\n";
	else
	{
	    Node *temp = new Node(data);
	    temp->link = p->link;
	    p->link = temp;
	}
}

void SingleLinkedList::insertBefore(int data,int x)
{
	if( isEmpty() )
	{
		cout << "List is empty\n";
		return;
	}	
	
	/* x is in first node, new node is to be inserted before first node */
	if( x == start->info )
	{
		Node *temp = new Node(data);
		temp->link = start;
		start = temp;
		return;
	}	

	/* Find pointer to predecessor of node containing x */
	Node *p = start;
	while( p->link != NULL ) 
	{
		if( p->link->info == x )
			   break;	
		p = p->link;
	}
	if( p->link == NULL)
	    cout << x << " not present in the list\n";
	else
	{
	    Node *temp = new Node(data);
	    temp->link = p->link;
	    p->link = temp;
	}
}

void SingleLinkedList::insertAtPosition(int data,int k)
{
	Node *temp;
	if( k == 1 )
	{
		temp = new Node(data);
		temp->link = start; 
		start = temp;
		return;
	}
	Node *p = start;
	int i;
	for( i = 1; i < k-1 && p!=NULL; i++ ) /* Find a pointer to (k-1)th node */
		p = p->link;
	
	if( p == NULL )
		cout << "You can insert only upto " << i << "th position\n";
	else
	{
		temp = new Node(data);
		temp->link = p->link;
		p->link = temp;
	}	
}

void SingleLinkedList::deleteFirstNode()
{
	if( isEmpty() )
		return;
	
	Node *temp = start;
	start = start->link;
	delete temp;
}

void SingleLinkedList::deleteLastNode()
{
	if( isEmpty() )
		return;
	
	if( start->link == NULL )
	{
       delete start;
	   start = NULL;
	   return;
    }
	
	Node *p = start;
	while ( p->link->link != NULL )
		p = p->link;
	
	delete p->link;
	p->link = NULL;
}

void SingleLinkedList::deleteNode(int x)
{
	if( isEmpty() )
	{
		cout << "List is empty\n";
		return;
	}
	
	Node *temp;

	/* Deletion of first node */
	if( start->info == x )
	{
		temp = start;
		start = start->link;  
		delete temp;
		return;
	}

	/* Deletion in between or at the end */
	Node *p = start;
	while( p->link != NULL )
	{
		if( p->link->info == x )   
			break;
		p = p->link;
	}
			
	if( p->link == NULL)
		cout << "Element " << x << " not present in the list\n";
	else
	{
		temp = p->link;
		p->link = temp->link;
		delete temp;
	}
}

		
void SingleLinkedList::reverseList()
{
	Node *prev, *p, *next;
	prev = NULL;
   	p = start;
	while( p != NULL )
	{
		next = p->link;
		p->link = prev;
		prev = p;
		p = next;
	}
	start = prev;
}


bool SingleLinkedList :: hasCycle()
{
	if( findCycle() == NULL )
		return false;
    else
        return true;
}

Node* SingleLinkedList :: findCycle()
{
	if( start == NULL || start->link == NULL )
		return NULL;

    Node *slowP = start;
    Node *fastP = start;

    while( fastP != NULL && fastP->link != NULL )
    {
		slowP = slowP->link;
        fastP = fastP->link->link;
        if( slowP == fastP )
			return slowP;
	}
	return NULL;
}

void SingleLinkedList :: removeCycle()
{
	Node *c = findCycle();
	
	if( c == NULL )
	    return;
	
	cout << "Node at which the cycle was detected is " << c->info << "\n";
			
	Node *p = c, *q = c;	
	int lenCycle = 0;
	do
	{
	   lenCycle++;
	   q = q->link;
	}while(p != q);
	cout << "Length of cycle is : " << lenCycle << "\n";
		
	int lenRemList = 0;
	p = start;
	while (p != q)
	{
		lenRemList++;
		p = p->link;
		q = q->link;
	}
		
	cout << "Number of nodes not included in the cycle are : " << lenRemList << "\n";
		
	int lengthList = lenCycle + lenRemList;
	cout << "Length of the list is : " << lengthList << "\n";
		
	p = start;
	for(int i = 1; i <= lengthList-1; i++)
		p = p->link;
	p->link = NULL;

	cout << "Cycle removed from the list \n\n";
}

void SingleLinkedList :: insertCycle(int x)
{
	if( start == NULL )
		return;
	  
	Node *p = start, *px = NULL, *prev = NULL;		
	 
	while (p!=NULL)
	{
		if (p->info == x)
			px = p;
		prev = p;
		p = p->link;
	}
	if (px != NULL)
		prev->link = px;
	else
	    cout << x << " not present in list" << "\n";
}


void SingleLinkedList::bubbleSortExData()
{
	Node *end, *p, *q;
	
	for( end = NULL; end != start->link; end = p)
	{
  		for( p = start; p->link != end; p = p->link)
		{
			q = p->link;
			if( p->info > q->info )
			{
				int temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
}

void SingleLinkedList :: bubbleSortExLinks()
{
	Node *end,*r,*p,*q,*temp;
		
	for( end = NULL; end != start->link; end = p )
	{
  		for( r = p = start; p->link != end; r = p, p = p->link )
		{
			q = p->link;
			if( p->info > q->info )
			{
				p->link = q->link;
				q->link = p;
				if( p != start )
                    r->link = q;
				else
					start = q;
				temp = p;
				p = q;
				q = temp;
			}
		}
	}
}

void SingleLinkedList :: mergeLists1(const SingleLinkedList& L, SingleLinkedList& mergedList)
{
	mergedList.start = merge1(start, L.start);
}

Node* SingleLinkedList ::merge1(Node *p1, Node *p2)
{
	Node *startM;

    if (p1->info <= p2->info)
    {
		startM = new Node(p1->info);
        p1 = p1->link;
    }
    else
    {
		startM = new Node(p2->info);
        p2 = p2->link;
    }

    Node *pM = startM;

    while (p1 != NULL && p2 != NULL)
    {
		if (p1->info <= p2->info)
        {
			pM->link = new Node(p1->info);
            p1 = p1->link;
        }
        else
        {
			pM->link = new Node(p2->info);
            p2 = p2->link;
        }
        pM = pM->link;
     }

     /*If second list has finished and elements left in first list*/
     while (p1 != NULL)
     {
		pM->link = new Node(p1->info);
        p1 = p1->link;
        pM = pM->link;
     }

     /*If first list has finished and elements left in second list*/
     while (p2 != NULL)
     {
		pM->link = new Node(p2->info);
        p2 = p2->link;
        pM = pM->link;
     }
     return startM;
}

void SingleLinkedList :: mergeLists2(SingleLinkedList& L, SingleLinkedList& mergedList)
{
	mergedList.start = merge2(start, L.start);
	start = NULL;  
	L.start = NULL; 
}

Node* SingleLinkedList :: merge2(Node *p1, Node *p2)
{
	Node *startM;

    if (p1->info <= p2->info)
    {
		startM = p1;
        p1 = p1->link;
    }
    else
	{
		startM = p2;
        p2 = p2->link;
    }

    Node *pM = startM;

    while (p1 != NULL && p2 != NULL)
    {
		if (p1->info <= p2->info)
        {
			pM->link = p1;
            pM = pM->link;
            p1 = p1->link;
        }
        else
        {
			pM->link = p2;
            pM = pM->link;
            p2 = p2->link;
        }
     }

     if (p1 == NULL)
		pM->link = p2;
     else
		pM->link = p1;
     
	 return startM;
}

void SingleLinkedList :: mergeSort()
{
	start = mergeSortRec(start);
}


Node* SingleLinkedList :: mergeSortRec(Node* listStart)
{
	if (listStart == NULL || listStart->link == NULL)/*if list empty or has one element*/
		return listStart;

    /*if more than one element*/
    Node* start1 = listStart;
    Node* start2 =divideList(listStart);
    start1 = mergeSortRec(start1);
    start2 = mergeSortRec(start2);
    Node* startM = merge2(start1, start2);
    return startM;
}

Node* SingleLinkedList :: divideList(Node* p)
{
	Node* q = p->link->link;
    while (q != NULL && q->link != NULL)
    {
		p = p->link;
        q = q->link->link;
    }
    Node *start2 = p->link;
    p->link = NULL;
    return start2;
}
       

