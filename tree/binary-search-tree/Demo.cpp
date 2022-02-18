/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "bst.h"

using namespace std;

int main()
{
	BinarySearchTree bst;
	int choice,x;
		
	while(true)
	{
		cout << "1.Display Tree\n";
		cout << "2.Search\n";
		cout << "3.Insert a new node\n";
		cout << "4.Delete a node\n";
		cout << "5.Preorder Traversal\n";
		cout << "6.Inorder Traversal\n";
		cout << "7.Postorder Traversal\n";
		cout << "8.Level order Traversal\n";
		cout << "9.Height of tree\n";
		cout << "10.Find Minimum key\n";
		cout << "11.Find Maximum key\n";
		cout << "12.Quit\n";
		cout << "Enter your choice : ";
		cin >> choice;

		if( choice == 12 )
			break;

		switch( choice )
		{
			case 1:
				bst.display();
				break;
			case 2: 
				cout << "Enter the key to be searched : ";
				cin >> x;
				
				if( bst.search(x) )
					cout << "Key found\n\n";
				else
					cout << "Key not found\n\n";
				break;
			 case 3:
				cout << "Enter the key to be inserted : ";
				cin >> x;
				bst.insert(x);
				break;
			 case 4:
			    cout << "Enter the key to be deleted : ";
			    cin >> x;
			    bst.del(x);
			    break;
			 case 5:
			    bst.preorder();
			    break;
			 case 6:
			    bst.inorder();
			    break;
			 case 7:
			    bst.postorder();
			    break;
			 case 8:
			    bst.levelOrder();
			    break;
			 case 9:
			    cout << "Height of tree is " << bst.height() << "\n\n";
			    break;
			 case 10:
			    cout << "Minimum key is " << bst.min() << "\n\n";
			    break;
			 case 11:
			    cout << "Maximum key is " << bst.max() << "\n\n";
			    break;
			 default:
				cout << "Wrong choice\n\n";
		}
	}
}


