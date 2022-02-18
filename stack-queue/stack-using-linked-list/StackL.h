/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class Stack
{
	Node *top;	

  public:
	Stack();
	Stack(const Stack& S);
	~Stack();
	Stack& operator=(const Stack& S);

	bool isEmpty() const;
	int size() const;
	void display() const;
	void push(int x);
	int pop();
	int peek() const;
};

