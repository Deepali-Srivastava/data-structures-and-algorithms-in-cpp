/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "doubly.h"

using namespace std;

int main()
{
	DoublyLinkedList list;
	list.createList();

	int choice,data,x;
	
	while(1)
	{
		cout << "\n";
		cout << "1.Display list\n";
		cout << "2.Insert in empty list\n";
		cout << "3.Insert in beginning of the list\n";
		cout << "4.Insert a node at the end of the list\n";
		cout << "5.Insert a node after a specified node\n";
		cout << "6.Insert a node before a specified node\n";
		cout << "7.Delete first node\n";
		cout << "8.Delete last node\n";
		cout << "9.Delete any node\n";
		cout << "10.Reverse the list\n";
		cout << "11.Quit\n";
				
		cout << "Enter your choice : ";
		cin >> choice;
		
		if( choice == 11 )
			break;

		switch(choice)
		{
		 case 1:
			list.displayList();
			break;
		 case 2:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			list.insertInEmptyList(data);
			break;
		 case 3:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			list.insertAtBeginning(data);
			break;
		 case 4:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			list.insertAtEnd(data);
			break;
		 case 5:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the element after which to insert : ";
			cin >> x;
			list.insertAfter(data,x);
			break;
		 case 6:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the element before which to insert : ";
			cin >> x;
			list.insertBefore(data,x);
			break;
		 case 7:
		    list.deleteFirstNode();
			break;
		 case 8:
			list.deleteLastNode();
			break;
		 case 9:
			cout << "Enter the element to be deleted : ";
			cin >> data;
			list.deleteNode(data);	
			break;  
		 case 10:
			list.reverseList();
			break;
		 default:
			 cout << "Wrong Choice\n";
			 break;
		}
	}
	cout << "Exiting \n";
}


