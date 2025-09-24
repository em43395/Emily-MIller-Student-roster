#include <iostream>
#include <sstream>
#include "roster.h"
using namespace std;

// Constructor (initializing lastIndex to -1 so on first incrementation we start at 0)
Roster::Roster() 
{
	lastIndex = -1;
}

// Destructor. Removes each student from classRosterArray one index at a time
Roster::~Roster() 
{
	for (int i = 0; i <= lastIndex; i++) 
	{
		delete classRosterArray[i];
	}
}

// Adds a new student to the classRosterArray at the location lastIndex + 1
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram program) 
{
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, program);
}

// Loops through classRosterArray and deletes a specific student with a studentID matching the ID that gets passed in
void Roster::remove(string studentID) 
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if ( classRosterArray[i] -> getStudentID() == studentID) 
		{
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex--];
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Error 101! Student with ID: " << studentID << " not found." << endl;
	}
}

// Loops through classRosterArray and prints the Student at each index
void Roster::printAll() 
{
	for (int i = 0; i <= lastIndex; i++) 
	{
		classRosterArray[i]->print();
	}
}

// Loops through classRosterArray and compares studentID's to the ID passed in to find matching student. The average days in course is calculated and printed for said student
void Roster::printAverageDaysInCourse(string studentID) 
{
	for (int i = 0; i <= lastIndex; ++i)  
	{
		if (classRosterArray[i]->getStudentID() == studentID) 
		{
			int* days = classRosterArray[i]->getDaysInCourse();
			cout << "StudentID " << studentID << ", Average days in course: "
				<< (days[0] + days[1] + days[2]) / 3 << endl;
		}	
	}
}

// Loops through all Students in classRosterArray and validates their email addresses, printing any invalid ones
void Roster::printInvalidEmails() 
{
	for (int i = 0; i <= lastIndex; i++) 
	{
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if (emailAddress.find(' ') != string::npos || emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos) 
		{
			cout << "Invalid email: " << emailAddress << endl;
		}
	}
}

// Loops through all Students in classRosterArray and prints students who's degreeProgram matches the program passed in
void Roster::printByDegreeProgram(DegreeProgram program) 
{
	for (int i = 0; i <= lastIndex; i++) 
	{
		if (classRosterArray[i]->getDegreeProgram() == program) 
		{
			classRosterArray[i]->print();
		}
	}
}


