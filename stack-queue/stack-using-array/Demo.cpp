/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "StackA.h"

using namespace std;

int main()
{
	int choice,x;
	
	Stack stack;
		
	while(1)
	{
		cout << "1.Push an element on the stack\n";
		cout << "2.Pop an element from the stack\n";
		cout << "3.Display the top element\n";
		cout << "4.Display all stack elements\n";
		cout << "5.Display size of the stack\n"; 
		cout << "6.Quit\n";
		cout << "Enter your choice : ";
		cin >> choice;
		
		if( choice == 6 )
			break;

		switch(choice)
		{
		 case 1 :
			cout << "Enter the element to be pushed : ";
			cin >> x;
			stack.push( x );
			break;
		 case 2:
			x = stack.pop();
			cout << "Popped element is : "<< x <<"\n\n";
			break;
		 case 3:
			cout << "Element at the top is : "<< stack.peek() << "\n\n";
			break;
		 case 4:
			stack.display();
			break;
		 case 5:
			cout << "Size of stack " << stack.size() << "\n\n";
			break;
		 default:
			cout << "Wrong choice\n\n";
		}
	}
}




