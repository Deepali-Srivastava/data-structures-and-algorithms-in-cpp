/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;
#include"heap.h"

int main()
{
	int i, choice, num;
	
	Heap tree;

	while(1)
	{
		cout << "1.Insert\n";
		cout << "2.Delete root\n";
		cout << "3.Display\n";
		cout << "4.Exit\n";
		cout << "Enter your choice : ";
		cin >> choice;

		if( choice == 4 )
			break;

		switch( choice )
		{
		 case 1:
			cout << "Enter the number to be inserted : ";
			cin >> num;
			tree.insert(num);
			break;
		 case 2:
			if( tree.isEmpty() )
				cout << "Tree is empty\n";
			else
			{
				num = tree.deleteRoot();
				cout << "Maximum element is " << num << "\n";
			}
			break;
		 case 3:
			tree.display();
			break;
 		 case 4:
			exit(1);
		 default:
			cout << "Wrong choice\n";
		}
	}
}
