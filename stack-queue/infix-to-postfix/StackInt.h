/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class StackInt
{
	static const int maxSize = 10;
	int arr[maxSize];
	int top;	

  public:
	StackInt();
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	void display() const;
	void push(int x);
	int pop();
	int peek() const;
};

