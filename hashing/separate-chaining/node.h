/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include "student.h"

class Node
{
	public:
		StudentRecord info;
		Node *link;

		Node(StudentRecord i) 
		{
			info = i;
			link = NULL;
		}
};
