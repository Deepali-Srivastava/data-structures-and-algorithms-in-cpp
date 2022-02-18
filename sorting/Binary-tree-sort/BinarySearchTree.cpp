/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>

#include "bst.h"

using namespace std;

int BinarySearchTree :: k;   

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
	
	Node *cp = new Node( p->info );

	cp->lchild = copy( p->lchild );
	cp->rchild = copy( p->rchild );
	return cp;
}

BinarySearchTree& BinarySearchTree :: operator=(const BinarySearchTree& T)
{
	if( this == &T )
		return *this;

	if( T.root == NULL )
	{
		root = NULL;
		return *this;
	}		
	
	destroy(root);
	
	root = copy(T.root);
		
	return *this;
}


BinarySearchTree :: ~BinarySearchTree()
{
	destroy(root);
	root = NULL;
}

/* Nodes destroyed using postorder traversal */
void BinarySearchTree :: destroy( Node *p )
{
	if( p == NULL)
		return;
	destroy( p->lchild );
	destroy( p->rchild );
	delete p;
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
	else 
		p->rchild = insert(p->rchild, x);  
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

void BinarySearchTree :: inorder1(int a[]) const
{
	k = 0;
	inorder1(root,a);
}

void BinarySearchTree :: inorder1(Node *p, int a[]) const
{
	if( p == NULL )	
		return;
	inorder1(p->lchild,a);
	a[k++] = p->info;
	inorder1(p->rchild,a);
}
