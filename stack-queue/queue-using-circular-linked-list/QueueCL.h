/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class Queue
{
	Node *rear;

  public:
	Queue();
	~Queue();
	Queue(const Queue& S);
		
	bool isEmpty() const;
	int size() const;
	void enqueue(int x);
	int dequeue();
	int peek() const;
	void display() const;
};

