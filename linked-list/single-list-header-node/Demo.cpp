/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "headerlist.h"

using namespace std;

int main()
{
	SingleLinkedListH list;
	list.createList();

	int choice,data,item,position;
	
	while(1)
	{
		cout << "\n";
		cout << "1.Display list\n";
		cout << "2.Insert a node at the end of the list\n";
		cout << "3.Insert a node before a specified node\n";
		cout << "4.Insert a node at a given position\n";
		cout << "5.Delete any node\n";
		cout << "6.Reverse the list\n";
		cout << "7.Quit\n";
		cout << "Enter your choice : ";
		cin >> choice;
		
		if( choice == 7 )
			break;

		switch(choice)
		{
		 case 1:
			list.displayList();
			break;
		 case 2:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			list.insertAtEnd(data);
			break;
		 case 3:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the element before which to insert : ";
			cin >> item;
			list.insertBefore(data,item);
			break;
		 case 4:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the position at which to insert : ";
			cin >> position;
			list.insertAtPosition(data,position);
			break;
		 case 5:
			cout << "Enter the element to be deleted : ";
			cin >> data;
			list.deleteNode(data);	
			break;  
		 case 6:
			list.reverseList();
			break;
		 default:
			 cout << "Wrong Choice\n";
			 break;
		}
	}
	cout << "Exiting \n";
}


