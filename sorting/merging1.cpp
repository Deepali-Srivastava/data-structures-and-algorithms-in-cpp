/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

void merge(int a[], int temp[], int low1, int up1, int low2, int up2);

int main()
{
	int a[] = {1,2,4,5,  3,6,7,8,12,16};
	int temp[10];	

	merge(a, temp, 0, 3, 4, 9);
	
	for( int i=0; i<10; i++)
		cout << temp[i] << "  ";
	cout << "\n";
}

/* a[low1]...a[up1] and a[low2]...a[up2] merged to temp[low1]..temp[up2] */
void merge(int a[], int temp[], int low1, int up1, int low2, int up2)
{
	int i = low1;  	
	int j = low2;  	
	int k = low1;  	

	while( i<=up1 && j<=up2 )
	{
		if( a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while( i<=up1 )
		temp[k++] = a[i++];
	
	while( j<=up2 )
		temp[k++] = a[j++];
}