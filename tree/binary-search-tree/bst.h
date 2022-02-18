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

	void display(Node *p, int level) const;
	void preorder(Node *p) const;
	void inorder(Node *p) const;
	void postorder(Node *p) const;
	int height(Node *p) const;
	Node* copy(Node *p);
	void destroy(Node *p);
	Node* search(Node *p, int x);
	Node* max(Node *p);
	Node* min(Node *p);
	Node* insert(Node *p, int x);
	Node* del(Node *p, int x);
	
  public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& T);
	BinarySearchTree& operator=(const BinarySearchTree& T);

	bool isEmpty() const;
	void display() const;
	void preorder() const;
	void inorder() const;
	void postorder() const;
	int height() const; 
	void levelOrder() const;

	bool search(int x);
	bool search1(int x);
	int min();
	int max();
	int min1();
	int max1();
	void insert(int x);
	void insert1(int x);
	void del(int x);
	void delete1(int x);
};
