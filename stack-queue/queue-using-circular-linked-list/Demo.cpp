/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"Node.h"
#include"QueueCL.h"

using namespace std;

int main()
{
	int choice,x;
	Queue qu;

	while(1)
	{
		cout << "1.Insert an element in the queue\n" ;
        cout << "2.Delete an element from the queue\n";
        cout << "3.Display element at the front\n";
        cout << "4.Display all elements of the queue\n";
        cout << "5.Display size of the queue\n";
        cout << "6.Quit\n";
		cout << "Enter your choice : ";
		cin >> choice;

		if( choice == 6 )
			break;

		switch( choice )
		{
		case 1:
			cout << "Enter the element to be inserted : ";
			cin >> x;
			qu.enqueue(x);
			break;
		case 2:
			x = qu.dequeue();
			cout << "Element deleted is : "<< x << "\n\n";
			break;
		case 3:
			cout << "Element at the front is : " << qu.peek() << "\n\n";
			break;
		case 4:
			qu.display();
			break;
		case 5:
			cout << "Size of queue is " << qu.size() << "\n\n";
			break;
		default:
			cout << "Wrong choice\n\n";
		}
	}
}

