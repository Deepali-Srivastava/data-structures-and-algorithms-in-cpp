/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"

class BinaryTree
{ 
 private:
	Node *root;
	
	void display(Node *p, int level) const;
	void preorder(Node *p) const;
	void inorder(Node *p) const;
	void postorder(Node *p) const;
	int height(Node *p) const;
	
  public:
	BinaryTree();
	
	bool isEmpty() const;
	void display() const;
	void preorder() const;
	void inorder() const;
	void postorder() const;
	int height() const; 
	void levelOrder() const;
	void createTree(); 
};