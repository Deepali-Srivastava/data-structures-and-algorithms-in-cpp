/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"

class BinarySearchTree
{ 
 private:
	Node *root;
	static int k;

	void display(Node *p, int level) const;
	void inorder(Node *p) const;
	Node* copy(Node *p);
	void destroy(Node *p);
	Node* insert(Node *p, int x);
	Node* del(Node *p, int x);
	void inorder1(Node *p, int a[]) const ;
	
  public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& T);
	BinarySearchTree& operator=(const BinarySearchTree& T);

	bool isEmpty() const;
	void display() const;
	void inorder() const;
	void inorder1(int a[]) const;

	void insert(int x);
	void del(int x);
};
