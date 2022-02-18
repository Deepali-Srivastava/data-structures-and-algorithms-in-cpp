/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include"student.h"
using namespace std;

class HashTable
{
	 StudentRecord *arr;
     int m;  //size of the array
     int n;  //number of records
	 int *status;
	 int hash(int key);
  
  public:
	 HashTable(int tableSize=11);
     ~HashTable();
	 void insertRecord(StudentRecord newRecord);
	 bool searchRecord(int key);
     void deleteRecord(int key);
	 void displayTable();
};