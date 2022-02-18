/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
#include<string>
#include"student.h"

using namespace std;

StudentRecord :: StudentRecord()
{ }

StudentRecord :: StudentRecord(int i, string name)
{
	studentId = i;
    studentName = name;
}

int StudentRecord :: getstudentId()
{
	return studentId;
}

void StudentRecord :: setstudentId(int i)
{
	studentId = i;
}
        
ostream& operator<<(ostream& out, const StudentRecord& st)
{
	out << " " << st.studentId << " " << st.studentName << "  " ;
	return out;
}
