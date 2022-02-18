/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "circular.h"

using namespace std;

int main()
{
	CircularLinkedList list;
	list.createList();

	int choice,data,item;
	
	while(1)
	{
		cout << "1.Display list\n";
		cout << "2.Insert in empty list\n";
		cout << "3.Insert in the beginning of the list\n";
		cout << "4.Insert at the end of the list\n";
		cout << "5.Insert a node after a specified node\n";
		cout << "6.Delete first node\n";
		cout << "7.Delete last node\n";
		cout << "8.Delete any node\n";
		cout << "9.Quit\n";
		
		cout << "Enter your choice : ";
		cin >> choice;

		if(choice==9)
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
			cin >> item;
			list.insertAfter(data,item);
			break;
		 case 6:
		    list.deleteFirstNode();
			break;
		 case 7:
			list.deleteLastNode();
			break;
		 case 8:
			cout << "Enter the element to be deleted : ";
			cin >> data;
			list.deleteNode(data);	
			break;  
		 default:
			 cout << "Wrong Choice\n";
			 break;
		}
	}
	cout << "Exiting \n";
}







			    
			
			