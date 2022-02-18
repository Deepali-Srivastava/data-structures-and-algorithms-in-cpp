/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<iostream>
using namespace std;

class StudentRecord
{
	  int studentId;
      string studentName;
	
   public:
	  StudentRecord();
	  StudentRecord(int i, string name);
      int getstudentId();
      void setstudentId(int i);
      friend ostream& operator<<(ostream& out, const StudentRecord& st);
};
