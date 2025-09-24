#pragma once

#include <iostream>
#include "student.h"
using namespace std;

// This class defines the roster that holds all instances of the Students class and contains functions that operate logic on this roster
class Roster 
{
	private:
		int lastIndex; // Tracks previous index for incremementing and adding new students

	public:	
		Roster(); // Constructor
		~Roster(); // Destructor

		Student* classRosterArray[5]; // List of Students

		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram program); // Adds a Student to classRosterArray[]

		void remove(string studentID); // Removes a student from classRosterArray

		void printAll(); // Prints roster

		void printAverageDaysInCourse(string studentID); // Prints average days in course

		void printInvalidEmails(); // Prints invalid emails

		void printByDegreeProgram(DegreeProgram program); // Prints Students in specific degree program
};