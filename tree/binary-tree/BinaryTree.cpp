/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "queue.h" 
#include "binarytree.h"

using namespace std;

BinaryTree :: BinaryTree()
{
	root = NULL;
}

bool BinaryTree :: isEmpty() const
{
	return root == NULL;
}

void BinaryTree :: display() const
{
	display(root,0);
	cout<<"\n";
}

void BinaryTree :: display(Node *p, int level) const
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

void BinaryTree :: preorder() const
{
	preorder(root);
	cout<<"\n";
}

void BinaryTree :: preorder(Node *p) const
{
	if( p == NULL )	
		return;
	cout << p->info << " ";
	preorder(p->lchild);
	preorder(p->rchild);
}

void BinaryTree :: postorder() const
{
	postorder(root);
	cout<<"\n";
}

void BinaryTree :: postorder(Node *p) const
{
	if( p == NULL )	
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	cout << p->info << " ";
}

void BinaryTree :: inorder() const
{
	inorder(root);
	cout<<"\n";
}

void BinaryTree :: inorder(Node *p) const
{
	if( p == NULL )	
		return;
	inorder(p->lchild);
	cout << p->info << " ";
	inorder(p->rchild);
}

void BinaryTree :: levelOrder() const
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
		if( p->rchild != NULL )
			qu.enqueue(p->rchild);
	} 
	cout<<"\n";
}


int BinaryTree :: height() const
{
	return height(root);
}

int BinaryTree :: height(Node *p) const
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

void BinaryTree :: createTree()
{
	root = new Node('P');
    root->lchild = new Node('Q');
    root->rchild = new Node('R');
    root->lchild->lchild = new Node('A');
    root->lchild->rchild = new Node('B');
    root->rchild->lchild = new Node('X');
}