/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


class Node
{
	public:
		int info;
		Node *prev;
		Node *next;

		Node(int i) 
		{
			info = i;
			prev = NULL;
			next = NULL;
		}
};