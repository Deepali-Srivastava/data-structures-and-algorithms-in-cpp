/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class StackChar
{
	static const int maxSize = 10;
	char arr[maxSize];
	int top;	

  public:
	StackChar();
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	void display() const;
	void push(char x);
	char pop();
	char peek() const;
};
