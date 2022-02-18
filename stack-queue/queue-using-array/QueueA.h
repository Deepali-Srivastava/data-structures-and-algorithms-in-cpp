/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

class Queue
{
	static const int maxSize = 10;
	int arr[maxSize];
	int front;	
	int rear;

  public:
	Queue();
	void enqueue(int x);
	int dequeue();
	int peek() const;
	int size() const;
	bool isEmpty() const;
	bool isFull() const;
	void display() const;
};

