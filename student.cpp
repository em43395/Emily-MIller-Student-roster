#include <iostream>
#include "student.h"

using namespace std;

// Constructor. Used to create instance of Student class assigning parameters to their corresponding properties 
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram program)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; ++i) 
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->program = program;

}

// Getters for retrieving private property values
string Student::getStudentID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourse() const 
{
	return (int*) daysInCourse;
}
DegreeProgram Student::getDegreeProgram() const { return program; }

// Setters for assigning private property values
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->lastName = lastName; }
void Student::setAge(int age) { this->lastName = lastName; }
void Student::setDaysInCourse(int daysInCourse[]) 
{
	for (int i = 0; i < 3; ++i) 
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void Student::setDegreeProgram(DegreeProgram program) { this->program = program; }

// Prints an instance of a Student
void Student::print() const 
{
	cout << getStudentID() << "\tFirst Name: " << getFirstName()
		<< "\tLast Name: " << getLastName() <<"\tEmailAddress: " << getEmailAddress() << "\tAge: " << getAge()
		<< "\tdaysInCourse: {" << getDaysInCourse()[0] << ", "
		<< getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} "
		<< "Degree Program: " << (program == SECURITY ? "Security" : program == NETWORK ? "Network" : "Software") << endl;
}