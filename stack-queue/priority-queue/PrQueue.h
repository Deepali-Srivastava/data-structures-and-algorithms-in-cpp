/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class PrQueue
{
	Node *front;
	
   public:
	PrQueue();
	~PrQueue();
	void enqueue(int item, int item_priority);
	int dequeue();
	int isEmpty() const;
	void display() const;
};