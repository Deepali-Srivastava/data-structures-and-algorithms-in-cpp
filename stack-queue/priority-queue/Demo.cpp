/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"Node.h"
#include"PrQueue.h"

using namespace std;

int main()
{
	int choice,item,item_priority;
	PrQueue pq;

	while(1)
	{
		cout << "1.Insert a new element\n";
		cout << "2.Delete an element\n";
		cout << "3.Display the queue\n";
		cout << "4.Quit\n";
		cout << "Enter your choice : ";
		cin >> choice;

		if( choice == 4 )
			break;

		switch( choice )
		{
		 case 1:
			cout << "Input the item to be added in the queue : ";
			cin >> item;
			cout << "Enter its priority : ";
			cin >> item_priority;
			pq.enqueue(item, item_priority);
			break;
		 case 2:
			cout << "Deleted item is " << pq.dequeue() << "\n";			
			break;
		 case 3:
			pq.display();
			break;
		 default :
			cout << "Wrong choice\n";
		}
	}
}
