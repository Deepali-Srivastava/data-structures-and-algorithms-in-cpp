/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "node.h"
#include "sorted.h"

using namespace std;

int main()
{
	int choice,data,position;
	SortedLinkedList list;

	list.createList();

	while(1)
	{
		cout << "\n";
		cout << "1.Display list\n";
		cout << "2.Insert a new node\n";
		cout << "3.Search\n";
		cout << "4.Exit\n";
		cout << "Enter your choice : ";
		cin >> choice;
		if( choice == 4 )
			break;
		switch( choice )
		{
		 case 1:
			 list.displayList(); 
		  	 break;
		 case 2:
			 cout << "Enter the element to be inserted : ";
			 cin >> data;
			 list.insert(data);
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
		 default:
			cout << "Wrong choice\n";
		}
	}
}

