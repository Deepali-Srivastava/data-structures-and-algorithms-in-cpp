/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


class SingleLinkedList
{
	    Node *start;
		
		bool isEmpty() const;
		Node* findCycle();
		Node* merge1(Node *p1, Node *p2);
		Node* merge2(Node *p1, Node *p2);

	public:
		SingleLinkedList();
		SingleLinkedList(const SingleLinkedList& L);
		~SingleLinkedList();
		SingleLinkedList& operator=(const SingleLinkedList& L);
		void displayList() const;
		int countNodes() const;
		int find(int data) const;
		void insertAtBeginning(int data);
		void insertAtEnd(int data);
		void createList();
		void insertAfter(int data,int x);
		void insertBefore(int data,int x);
		void insertAtPosition(int data,int k);
		void deleteFirstNode();
		void deleteLastNode();
		void deleteNode(int data);
		void reverseList();
		void insertCycle(int x);
		bool hasCycle();
		void removeCycle();
		void bubbleSortExData();
		void bubbleSortExLinks();
		void mergeLists1(const SingleLinkedList& L, SingleLinkedList& mergeList);
		void mergeLists2(SingleLinkedList& L, SingleLinkedList& mergedList);
};

