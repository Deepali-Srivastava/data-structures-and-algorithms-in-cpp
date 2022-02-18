/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

class Deque
{
	static const int maxSize=10;
	int arr[maxSize];
	int front;	
	int rear;

  public:
	Deque();

	int isEmpty() const;
	int isFull() const;
	void insertFront(int x);
	void insertRear(int x);
	int deleteFront();
	int deleteRear();
	int first() const;
	int last() const;
	void display() const;
	int size() const;
};
