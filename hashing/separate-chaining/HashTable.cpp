/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"hashtable.h"

using namespace std;

HashTable :: HashTable(int tableSize)
{
	m = tableSize;
	n = 0;
    arr = new SingleLinkedList[m];
}

HashTable :: ~HashTable()
{
	delete[] arr;
}

int HashTable :: hash(int key)
{
	return key % m;
}

bool HashTable :: searchRecord(int key)
{
	int h = hash(key);

	Node *p = arr[h].search(key);

	if ( p != NULL )
	{
		cout << p->info;
		return true;
	}
	return false;
}

void HashTable :: insertRecord(StudentRecord newRecord)
{
	int key = newRecord.getstudentId();
    int h = hash(key);
	
	if( searchRecord(key) )
	{
		cout << " Duplicate key\n";
		return;
	}
	arr[h].insertAtBeginning(newRecord);
    n++;
}

void HashTable :: deleteRecord(int key)
{
	int h = hash(key);
	
	arr[h].deleteNode(key);
    n--;
}

void HashTable :: displayTable()
{
	for( int i=0; i<m; i++ )
    {
		cout << "[" << i << "]  -->  ";

		if( ! arr[i].isEmpty() )
			arr[i].displayList() ;
        else
           cout << "___" << "\n";
     }
}

