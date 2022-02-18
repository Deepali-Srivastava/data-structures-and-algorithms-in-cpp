/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"deque.h"
using namespace std;

int main()
{
	int choice,x;
	Deque dq;

	while(1)
	{
		cout << "1.Insert at the front end\n";
		cout << "2.Insert at the rear end\n";
		cout << "3.Delete from front end\n";
		cout << "4.Delete from rear end\n";
		cout << "5.Display first element\n";
		cout << "6.Display last element\n";
		cout << "7.Display all the elements of deque\n";
		cout << "8.Size of the deque\n";
		cout << "9.Quit\n";
		cout << "Enter your choice : ";
		cin >> choice;

		if( choice == 9 )
			break;

		switch( choice )
		{
		 case 1:
			cout << "Enter the element to be inserted at the front end : ";
			cin >> x;
			dq.insertFront(x);
			break;
		 case 2:
			cout << "Enter the element to be inserted at the rear end : ";
			cin >> x;
			dq.insertRear(x);
			break;
		 case 3:
			cout << "Element deleted from front end is : " << dq.deleteFront() << "\n";
			break;
		 case 4:
			cout << "Element deleted from rear end is : " << dq.deleteRear() << "\n";
			break;
		 case 5:
			cout << "Element at the front end is : " << dq.first() << "\n";
			break;
		 case 6:
			cout << "Element at the rear end is : " << dq.last() << "\n";
			break;
		 case 7:
			dq.display();
			break;
		 case 8:
			cout << "Size of the deque is " << dq.size();
			break;
		 case 9:
			exit(1);
		 default:
			cout << "Wrong choice\n";
		}
	}
}
