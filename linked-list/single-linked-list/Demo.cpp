/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "single.h"

using namespace std;

int main()
{
	SingleLinkedList list;
	list.createList();

	int choice,data,x,position;
	
	while(1)
	{
		cout<< "\n";
		cout << "1.Display list\n";
		cout << "2.Count the number of nodes\n";
		cout << "3.Search for an element\n";
		cout << "4.Insert in empty list/Insert in beginning of the list\n";
		cout << "5.Insert a node at the end of the list\n";
		cout << "6.Insert a node after a specified node\n";
		cout << "7.Insert a node before a specified node\n";
		cout << "8.Insert a node at a given position\n";
		cout << "9.Delete first node\n";
		cout << "10.Delete last node\n";
		cout << "11.Delete any node\n";
		cout << "12.Reverse the list\n";
		cout << "13.Insert Cycle\n";
		cout << "14.Detect Cycle\n";
		cout << "15.Remove cycle\n";
		cout << "16.Bubble sort by exchanging data\n";
		cout << "17.Bubble sort by exchanging links\n";
		cout << "18.MergeSort\n";
		cout << "19.Quit\n";
		
		cout << "Enter your choice : ";
		cin >> choice;
		
		if( choice == 19 )
			break;

		switch( choice )
		{
		 case 1:
			list.displayList();
			break;
		 case 2:
			cout<<"Number of nodes is " << list.countNodes() << "\n";
			break;
		 case 3:
			cout << "Enter the element to be searched : ";
			cin >> data;
			position = list.find(data);
			if( position == 0 )
				cout << data << " not in list\n";
			else
				cout << data << " present at position " << position << "\n";
			break;
		 case 4:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			list.insertAtBeginning(data);
			break;
		 case 5:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			list.insertAtEnd(data);
			break;
		 case 6:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the element after which to insert : ";
			cin >> x;
			list.insertAfter(data,x);
			break;
		 case 7:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the element before which to insert : ";
			cin >> x;
			list.insertBefore(data,x);
			break;
		 case 8:
			cout << "Enter the element to be inserted : ";
			cin >> data;
			cout << "Enter the position at which to insert : ";
			cin >> position;
			list.insertAtPosition(data,position);
			break;
		 case 9:
		    list.deleteFirstNode();
			break;
		 case 10:
			list.deleteLastNode();
			break;
		 case 11:
			cout << "Enter the element to be deleted : ";
			cin >> data;
			list.deleteNode(data);	
			break;  
		 case 12:
			list.reverseList();
			break;
		 case 13:
		    cout << "Enter the element at which the cycle has to be inserted : ";
		    cin >> data;
		    list.insertCycle(data);
		    break;
		 case 14:
		    if( list.hasCycle() )
			    cout << "List has a cycle\n";
		    else
			    cout << "List does not have a cycle\n";
			break;
		 case 15:
		    list.removeCycle();
		    break;
		 case 16:
		    list.bubbleSortExData();
		    break;
		 case 17:
		    list.bubbleSortExLinks();
		    break;
		 case 18:
		    list.mergeSort();
		    break;
		 default:
			 cout << "Wrong Choice\n";
			 break;
		}
	}
	cout << "Exiting \n";
}


