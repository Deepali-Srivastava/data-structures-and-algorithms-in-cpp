/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include "binarytree.h"

using namespace std;

int main()
{
	BinaryTree bt;
	bt.createTree();

	bt.display();
	cout << "\n";
		
	cout << "Preorder : \n";
	bt.preorder(); 
	cout << "\n";

	cout << "Inorder : \n";
	bt.inorder();
	cout << "\n";

	cout << "Postorder : \n";
	bt.postorder();
	cout << "\n";
	
	cout << "Level order : \n";
	bt.levelOrder();
	cout << "\n";
		
	cout << "Height of tree is " << bt.height() << "\n";
}







			    
			
			