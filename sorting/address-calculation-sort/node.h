/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

class Node
{
	public:
		int info;
		Node *link;
		Node(int i) 
		{
			info = i;
			link = NULL;
		}
};
