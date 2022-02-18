/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"hashtable.h"

using namespace std;

#define EMPTY 0
#define DELETED 1
#define OCCUPIED 2

HashTable :: HashTable(int tableSize)
{
	m = tableSize;
    arr = new StudentRecord[m];
	status = new int[m];

	for( int i=0; i<m; i++ )
		status[i] = EMPTY;
    
	n = 0;
}

HashTable :: ~HashTable()
{
	delete[] arr;
	delete[] status;
}

int HashTable :: hash(int key)
{
	return key % m;
}

void HashTable :: insertRecord(StudentRecord newRecord)
{
	int key = newRecord.getstudentId();
    int h = hash(key);

    int location = h;

    for( int i=1; i<m; i++ )
    {
		if( status[location] == EMPTY || status[location] == DELETED  )
		{
			arr[location] = newRecord;
			n++;
			status[location] = OCCUPIED;
            return;
        }

        if( arr[location].getstudentId() == key )
		{
			cout << "Duplicate key \n";
		    return;
		}

        location = (h + i) % m;
     }
     cout << "Table is full : Record can't be inserted \n";
}

bool HashTable :: searchRecord(int key)
{
	int h = hash(key);
    int location = h;

    for( int i=1; i<m; i++)
    {
		if( status[location] == EMPTY || status[location] == DELETED )
			return false;
        if( arr[location].getstudentId() == key )
        {
			cout << arr[location] << "\n";
			return true; 
		}
        location = (h + i) % m;
     }
     return false;
}

void HashTable :: deleteRecord(int key)
{
	int h = hash(key);
    int location = h;

    for( int i=1; i<m; i++ )
    {
		if( status[location] == EMPTY || status[location] == DELETED  )
		{
			cout << "Key not found\n";
			return;
		}
        if( arr[location].getstudentId() == key )
        {
			status[location] = DELETED;
            n--;
            cout <<"Record " << arr[location] << " deleted\n";
			return;
        }
        location = (h + i) % m;
     }
}

void HashTable :: displayTable()
{
	for( int i=0; i<m; i++ )
    {
		cout << "[" << i << "]  -->  ";

        if( status[i] == OCCUPIED )
			cout << arr[i] << "\n";
        else
            cout << "___" << "\n";
     }
}
