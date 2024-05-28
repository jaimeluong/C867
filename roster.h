#pragma once

#include <iostream>
#include <string>
#include <array>
#include "student.h"

using namespace std;

class Roster {
public:
	// Parse string of student data into a Student object
	void parse(string row);

	// Add Student object to Roster
	void add(string id, string first, string last, string email, int years, int daysCourseOne, int daysCourseTwo, int daysCourseThree, DegreeProgram option);

	// Remove student from roster given Student ID
	void remove(string id);

	// Print all student data in roster
	void printAll();

	// Print the average days in courses given Student ID
	void printAverageDaysInCourse(string id);

	// Print invalid emails throughout roster
	void printInvalidEmails() const;

	// Constructor with parameters
	Roster(int classSize);

	// Getter for Student ID given position in roster
	string getStudentId(int index) const;

	// Print students in given degree program
	void printByDegreeProgram(DegreeProgram option);

	// Destructor
	~Roster();

	// Create roster array pointing to 5 Student objects
	Student* classRosterArray[5];

	// Class size and roster index variables
	int classSize;
	int rosterIndex;
};