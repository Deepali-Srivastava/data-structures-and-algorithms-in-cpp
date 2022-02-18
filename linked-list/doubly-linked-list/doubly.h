/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class DoublyLinkedList
{
	    Node *start;
	    bool isEmpty() const;
	 
   public:
		DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList& L);
		~DoublyLinkedList();
		
		void displayList() const;
		void insertInEmptyList(int data);
		void insertAtBeginning(int data);
		void insertAtEnd(int data);
		void insertAfter(int data,int x);
		void insertBefore(int data,int x);
		void createList();
		void deleteNode(int x);
		void deleteFirstNode();
		void deleteLastNode();
		void reverseList();
};
