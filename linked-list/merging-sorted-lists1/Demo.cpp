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
	SingleLinkedList list1 = SingleLinkedList();
	SingleLinkedList list2 = SingleLinkedList();
				
	list1.createList();
	list2.createList();
		
	list1.bubbleSortExLinks();
	list2.bubbleSortExLinks();
				
	cout << "First List - ";  list1.displayList();
	cout << "Second List - "; list2.displayList();
		
	SingleLinkedList list3;
	list1.mergeLists1(list2, list3);
	
	cout << "Merged List - "; list3.displayList();

	cout << "First List - ";  list1.displayList();
	cout << "Second List - "; list2.displayList();
}


