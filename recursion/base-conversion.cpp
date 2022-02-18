/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/


#include<iostream>
using namespace std;

void toBinary(int n);
void convertBase(int n, int base);

int main()
{
	int num;
	
	cout << "Enter a positive decimal number : ";
	cin >> num;

	cout << "Binary form ";       toBinary(num); 	    cout<<"\n";
	cout << "Binary form ";       convertBase(num, 2); 	cout<<"\n";
	cout << "Octal form ";        convertBase(num, 8);	cout<<"\n";
	cout << "Hexadecimal form ";  convertBase(num, 16);	cout<<"\n";
}

void toBinary(int n)
{
	if( n == 0 )
		return;

	toBinary(n/2);
    cout << n%2;
}

void convertBase(int n, int base)
{
	int remainder;
	
	if( n == 0 )
		return;
	convertBase(n/base, base);
	
	remainder =	n % base;
	if( remainder < 10 )
		cout << remainder;	
	else
		cout << remainder - 10 + 'A' ;
}


