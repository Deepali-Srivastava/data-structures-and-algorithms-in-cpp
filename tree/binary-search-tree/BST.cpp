/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "QueueA.h" 

#include "bst.h"

using namespace std;

BinarySearchTree :: BinarySearchTree()
{
	root = NULL;
}

bool BinarySearchTree :: isEmpty() const
{
	return root == NULL;
}

BinarySearchTree :: BinarySearchTree(const BinarySearchTree& T)
{
	root = copy( T.root );
}

Node* BinarySearchTree :: copy( Node *p ) 
{
	if( p == NULL )
		return NULL;
	
	Node *cp = new Node(p->info);
	cp->lchild = copy( p->lchild );
	cp->rchild = copy( p->rchild );
	return cp;
}

BinarySearchTree& BinarySearchTree :: operator=(const BinarySearchTree& T)
{
	if (this == &T)
		return *this;

	destroy(root);
	
	root = copy(T.root);
		
	return *this;
}

BinarySearchTree :: ~BinarySearchTree()
{
	destroy(root);
	root = NULL;
}

void BinarySearchTree :: destroy( Node *p )
{
	if( p == NULL)
		return;
	destroy( p->lchild );
	destroy( p->rchild );
	delete p;
}

bool BinarySearchTree :: search1(int x)
 {
	Node *p = root;
    while( p != NULL )
    {
		if (x < p->info)
			p = p->lchild; /*Move to left child*/
        else if (x > p->info)
            p = p->rchild;  /*Move to right child */
        else	/*x found*/
            return true;
    }
    return false;
}

bool BinarySearchTree :: search(int x)
{
	return search(root, x) != NULL ;
}
 
Node* BinarySearchTree :: search(Node *p, int x)
{
	if (p == NULL)
		return NULL; /*key not found*/
    if (x < p->info)/*search in left subtree*/
        return search(p->lchild, x);
    if (x > p->info)/*search in right subtree*/
        return search(p->rchild, x);
    return p; /*key found*/
}

void BinarySearchTree :: insert1(int x)
{       
	Node *p = root;
	Node *par = NULL;
		
	while( p != NULL )
	{
		par = p;
		if(x < p->info)
			p = p->lchild;	
		else if(x > p->info)
		    p = p->rchild;
		else
		{	
			cout << x << " already present in the tree";
			return;
		}
	}
		
	Node *temp = new Node(x);
    
	if(par == NULL)
	   root = temp;
	else if(x < par->info)
	   par->lchild = temp;
	else
	   par->rchild = temp;
}

void BinarySearchTree :: insert(int x)
{
	root = insert(root, x);
}

Node* BinarySearchTree :: insert(Node *p, int x)
{
	if (p == NULL)	
		p = new Node(x);
	else if ( x < p->info )	
		p->lchild = insert(p->lchild, x);
	else if ( x > p->info )	
		p->rchild = insert(p->rchild, x);  
	else
		cout << x << "already present in tree";
	return p;
}

void BinarySearchTree :: del(int x)
{
	root = del(root, x);
}

Node* BinarySearchTree :: del(Node *p, int x)
{
	Node *ch,*s;

	if( p == NULL )
	{
		cout << x << "  not found\n";
		return p;
	}
	
	if( x < p->info )  /*delete from left subtree*/
		p->lchild = del( p->lchild, x );
	else if( x > p->info ) /*delete from right subtree*/
	    p->rchild = del( p->rchild, x );
	else
	{
		/*key to be deleted is found*/
		if( p->lchild != NULL  &&  p->rchild != NULL )  /*2 children*/
		{
			s = p->rchild;
			while( s->lchild != NULL )
				s = s->lchild;
			p->info = s->info;
			p->rchild = del( p->rchild, s->info );
		}
		else   /*1 child or no child*/	
		{
			if( p->lchild != NULL ) /*only left child*/
				ch = p->lchild;
			else  /*only right child or no child*/
				ch = p->rchild;
			p = ch;
		}						
	}
	return p; 
}

void BinarySearchTree ::delete1(int x)
{
	Node *p = root;
	Node *par = NULL;

    while( p != NULL )
	{
		if( x == p->info )
			break;
		par = p;
		if(x < p->info)
			p = p->lchild;	
		else 
		    p = p->rchild;
	}

	if( p == NULL )
	{
		cout << x << " not found\n";
		return;
	}
		
	/*Case C: 2 children*/
	/*Find inorder successor and its parent*/
    Node *s,*ps;
	if( p->lchild != NULL && p->rchild != NULL )
	{
		ps = p;
		s = p->rchild;

		while( s->lchild != NULL )
		{
			ps = s;
			s = s->lchild;
		}
		p->info = s->info; 
		p = s;
		par = ps;
	}	

	/*Case B and Case A : 1 or no child*/
	Node *ch;
	if( p->lchild != NULL ) /*node to be deleted has left child */
		ch = p->lchild;
	else                /*node to be deleted has right child or no child*/
		ch = p->rchild;

    if( par == NULL )   /*node to be deleted is root node*/
	    root = ch;
    else if( p == par->lchild )/*node is left child of its parent*/
	    par->lchild = ch;
    else       /*node is right child of its parent*/
	    par->rchild = ch;
}

int BinarySearchTree :: min1()
{
	if( isEmpty() )
		throw runtime_error("Tree is empty");
    
	Node *p = root;
    while( p->lchild != NULL )
		p = p->lchild;
    return p->info;
}

int BinarySearchTree :: max1()
{
	if( isEmpty() )
		throw runtime_error("Tree is empty");
    
	Node *p = root;
    while( p->rchild != NULL )
		p = p->rchild;
    return p->info;
}

int BinarySearchTree :: min()
{
	if( isEmpty() )
		throw runtime_error("Tree is empty");
    return min(root)->info;
}

Node* BinarySearchTree :: min(Node *p)
{
	if (p->lchild == NULL)
		return p;
    return min(p->lchild);
}

int BinarySearchTree :: max()
{
	if( isEmpty() )
		throw runtime_error("Tree is empty");
    return max(root)->info;
}

Node* BinarySearchTree :: max(Node *p)
{
	if( p->rchild == NULL )
		return p;
    return max( p->rchild );
}

void BinarySearchTree :: display() const
{
	display(root,0);
	cout<<"\n";
}

void BinarySearchTree :: display(Node *p, int level) const
{
	if( p == NULL )
		return;
	
	display(p->rchild, level+1);
	cout << "\n";
	
	for( int i = 0; i < level; i++ )
		cout << "    ";
	cout << p->info;
	
	display(p->lchild, level+1);
}

void BinarySearchTree :: preorder() const
{
	preorder(root);
	cout<<"\n";
}

void BinarySearchTree :: preorder(Node *p) const
{
	if( p == NULL )	
		return;
	cout << p->info << " ";
	preorder(p->lchild);
	preorder(p->rchild);
}

void BinarySearchTree :: postorder() const
{
	postorder(root);
	cout<<"\n";
}

void BinarySearchTree :: postorder(Node *p) const
{
	if( p == NULL )	
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	cout << p->info << " ";
}

void BinarySearchTree :: inorder() const
{
	inorder(root);
	cout<<"\n";
}

void BinarySearchTree :: inorder(Node *p) const
{
	if( p == NULL )	
		return;
	inorder(p->lchild);
	cout << p->info << " ";
	inorder(p->rchild);
}

void BinarySearchTree :: levelOrder() const
{
	if( isEmpty() )
	{
		cout << "Tree is empty";
		return;
	}
			
	Queue<Node *> qu; 
	qu.enqueue(root);
	
	Node *p;
	while( !qu.isEmpty() ) 
	{
		p = qu.dequeue();
		cout << p->info << " ";
		if( p->lchild != NULL )
			qu.enqueue(p->lchild);
		if ( p->rchild != NULL )
			qu.enqueue(p->rchild);
	} 
	cout<<"\n";
}

int BinarySearchTree :: height() const
{
	return height(root);
}

int BinarySearchTree :: height(Node *p) const
{
	if( p == NULL )
		return 0;

    int hL = height(p->lchild);
    int hR = height(p->rchild);

    if (hL > hR)
		return 1 + hL;
    else
		return 1 + hR;
}

