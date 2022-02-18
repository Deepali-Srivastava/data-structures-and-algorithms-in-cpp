/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


using namespace std;

class CircularLinkedList
{
	    Node *last;
		bool isEmpty() const;
		
	 public:
		CircularLinkedList();
		CircularLinkedList(const CircularLinkedList& L);
		~CircularLinkedList();
	
		void displayList() const;
		void insertInEmptyList(int data);
		void insertAtBeginning(int data);
		void insertAtEnd(int data);
		void insertAfter(int data,int x);
		void createList();
		void deleteNode(int x);
		void deleteFirstNode();
		void deleteLastNode();
		void concatenate(CircularLinkedList& list);
};

