/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
using namespace std;

class Heap
{
	static const int MAX_VAL = 99999; 
	int *a;
	int maxSize;
	int n;  

	void restoreUp(int loc);
	void restoreDown(int i);

  public:
	Heap(int sz=20);
	~Heap();
	bool isEmpty();
	void display();
	void insert(int value);
	int deleteRoot();
};

