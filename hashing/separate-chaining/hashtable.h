/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"single.h"
using namespace std;

class HashTable
{
	 SingleLinkedList *arr;
     int m;  //size of the array
     int n;  //number of records
	 int hash(int key);
  
  public:
	 ~HashTable();
	 HashTable(int tableSize=11);
     void insertRecord(StudentRecord newRecord);
	 bool searchRecord(int key);
	 void deleteRecord(int key);
     void displayTable();
};