/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class Stack
{
	int maxSize;
	int *arr;
	int top;	

  public:
	Stack(int sz = 10);
	Stack(const Stack& S);
	~Stack();
	Stack& operator=(const Stack& S);

	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	void display() const;
	void push(int x);
	int pop();
	int peek() const;
};