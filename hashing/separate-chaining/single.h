/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include "node.h"

class SingleLinkedList
{
	    Node *start;
	
	public:
		SingleLinkedList();
		~SingleLinkedList();
		bool isEmpty() const;
		void displayList() const;
		Node* search(int x) const;
		void insertAtBeginning(StudentRecord data);
		void deleteNode(int data);
};

