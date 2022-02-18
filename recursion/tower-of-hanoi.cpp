/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

void hanoi(int ndisk, char source, char temp, char dest);

int main( )
{
	int n;

	cout << "Enter the number of disks : ";
	cin >> n;
	
	hanoi(n, 'A', 'B', 'C');
}

void hanoi(int n, char source, char temp, char dest)4
{
	if( n == 1 )
	{
		cout << "Move Disk " << n << " from " << source << "-->" << dest << "\n";
		return;
	}
	hanoi(n-1, source, dest, temp);
	cout << "Move Disk " << n << " from " << source << "-->" << dest << "\n";
	hanoi(n-1, temp, source, dest);
}

