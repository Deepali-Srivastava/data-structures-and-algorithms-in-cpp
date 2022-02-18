/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


class SingleLinkedListH
{
	    Node *head;
		bool isEmpty() const;
		
	public:
		SingleLinkedListH();
		SingleLinkedListH(const SingleLinkedListH& L);
		~SingleLinkedListH();
		void createList();
		void displayList() const;
		void insertAtEnd(int data);
		void insertBefore(int data,int x);
		void insertAtPosition(int data,int position);
		void deleteNode(int x);
		void reverseList();
};



