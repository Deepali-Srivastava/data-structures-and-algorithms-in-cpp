/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class Node
{
   public:
	 int info;
	 Node *link;
	 int priority;
	 
	 Node(int i, int pri) 
	 {
		info = i;
		priority = pri;
		link = NULL;
	 }
};