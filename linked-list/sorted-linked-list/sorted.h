/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


class SortedLinkedList
{
	    Node *start;
		bool isEmpty() const;
					
	public:
		SortedLinkedList();
		SortedLinkedList(const SortedLinkedList& L);
		~SortedLinkedList();
		void displayList() const;
		int find(int data) const;
		void insert(int data);
		void createList();
};

