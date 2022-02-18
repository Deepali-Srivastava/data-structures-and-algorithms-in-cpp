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
	SingleLinkedList list1, list2;
	
	list1.createList();
	list2.createList();

	list1.displayList();
	list2.displayList();

	list1.concatenate(list2);

	list1.displayList();
	list2.displayList();
}
