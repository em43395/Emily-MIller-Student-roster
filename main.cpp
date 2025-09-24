#include <iostream>
#include "roster.h"
#include <sstream>
#include <string>
#include "degree.h"

using namespace std;

// Main program that executes logic for this application
int main()
{
	// Title info
	cout << "Course: Scripting and Programming - Applications C867\n";
	cout << "Language: C++\n";
	cout << "StudentID: 012260948\n";
	cout << "Name: Emily Miller\n";

	// Define table of student info
	const string studentData[] = 
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Emily,Miller,emil736@wgu.edu,26,15,20,25,SOFTWARE"
	};


	// Create instance of Roster class
	Roster classRoster;


	// Adds each student to the classRoster
	for (int i = 0; i < 5; ++i) 
	{
		string student = studentData[i];

		string studentID, firstName, lastName, emailAddress, programStr;
		int age, days[3];
		DegreeProgram degreeProgram;

		stringstream ss(student);

		getline(ss, studentID, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, emailAddress, ',');

		string temp;
		getline(ss, temp, ',');
		age = stoi(temp);

		getline(ss, temp, ',');
		days[0] = stoi(temp);

		getline(ss, temp, ',');
		days[1] = stoi(temp);

		getline(ss, temp, ',');
		days[2] = stoi(temp);

		getline(ss, programStr, ',');

		// Convert degreeProgramStr to enum value
		if (programStr == "SECURITY")
		{
			degreeProgram = SECURITY;
		}
		else if (programStr == "NETWORK") 
		{
			degreeProgram = NETWORK;
		}
		else if (programStr == "SOFTWARE")
		{
			degreeProgram = SOFTWARE;
		}

		classRoster.add(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
	}

	cout << "                                            Student Information" << endl;
	
	// Print all students
	classRoster.printAll();

	cout << endl;
	cout << endl;
	cout << "Invalid Email Addresses:" << endl;
	cout << endl;

	// Print invalid email addresses provided by students
	classRoster.printInvalidEmails();

	cout << endl;
	cout << endl;
	cout << "Average days to complete a course by student:" << endl;
	cout << endl;


	// Prints each student's average number of days to complete a course based on 3 previous courses
	for (int i = 0; i < 5; ++i) 
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	cout << endl;
	cout << endl;
	cout << "Student(s) by Degree Program:" << endl;
	cout << endl;

	// Prints students by selected degree program, in this case, software
	classRoster.printByDegreeProgram(SOFTWARE);

	// Remove the student with A3 student I.D.
	classRoster.remove("A3");

	cout << endl;
	cout << endl;
	cout << "                                            Student Information (after student(s) removed)" << endl;

	// Print the roster again, this time A3 will not be there
	classRoster.printAll();

	cout << endl;
	cout << endl;

	// Duplicate request to remove A3, will return error message 
	classRoster.remove("A3");

	return 0;
}
