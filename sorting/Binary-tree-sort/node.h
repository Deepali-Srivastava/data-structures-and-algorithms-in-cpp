/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class Node
{
	public:
		int info;
		Node *lchild;
		Node *rchild;

		Node(int i) 
		{
			info = i;
			lchild = NULL;
			rchild = NULL;
		}
};


