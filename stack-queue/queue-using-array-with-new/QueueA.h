/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

class Queue
{
	int maxSize;
	int *arr;
	int front;	
	int rear;

  public:
	Queue(int sz = 10);
	~Queue();
	Queue(const Queue& S);
	Queue& operator=(const Queue& S);
	
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	void enqueue(int x);
	int dequeue();
	int peek() const;
	void display() const;
};

