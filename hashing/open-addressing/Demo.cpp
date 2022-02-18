/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include<string>
#include"hashtable.h"

using namespace std;

int main()
{
	int id, choice, size;
	string name;
		
	cout << "Enter initial size of table : ";
    cin >> size;
			
	HashTable table(size);
		
	while(true)
	{
	   cout << "1.Insert a record \n";
	   cout << "2.Search a record \n";
	   cout << "3.Delete a record \n";
	   cout << "4.Display table  \n";
	   cout << "5.Exit \n";
	   cout << "Enter your choice : ";
       cin >> choice;

	   if( choice == 5 )
		   break;
	   
	   switch( choice )
	   {
			case 1 : 
				cout << "Enter student id : ";
                cin >> id;
				cout << "Enter student name : ";
                cin >> name;
				table.insertRecord(StudentRecord(id,name));
				break;
			case 2 : 
			    cout << "Enter a key to be searched : ";
			    cin >> id; 
			  				   
			    if( table.searchRecord(id) )
				    cout << "Key found \n";
				else
					cout << "Key not found \n";
				break;
			case 3: 
			    cout << "Enter a key to be deleted : ";
			    cin >> id;
			    table.deleteRecord(id);
			    break;
			case 4:
			    table.displayTable();
			    break;
			case 5:
			    exit(1);
				break;
			default:
				cout << "Wrong choice : \n";
		  }
	 }
}
    

