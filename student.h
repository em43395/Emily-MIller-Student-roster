#pragma once

#include <iostream>
#include "degree.h"
using namespace std;

// This class defines a Student
class Student 
{
	// Initializes the variables used in Student class
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse[3];
		DegreeProgram program;

	public:
		//constructor
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram program);

		// Getters
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const; 
		string getEmailAddress() const;
		int getAge() const;
		int* getDaysInCourse() const;
		DegreeProgram getDegreeProgram() const;

		// Setters
		void setStudentID(string studentID); 
		void setFirstName(string firstName); 
		void setLastName(string lastName); 
		void setEmailAddress(string emailAddress);
		void setAge(int age); 
		void setDaysInCourse(int daysInCourse[]);
		void setDegreeProgram(DegreeProgram program);

		// Prints Student
		void print() const;
};
