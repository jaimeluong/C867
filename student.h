#pragma once

#include <iostream>
#include <string>
#include <array>
#include "degree.h"

using namespace std;

class Student {
public:
	// Default constructor
	Student();

	// Constructor with parameters
	Student(string id, string first, string last, string email, int years, int days[], DegreeProgram option);

	// Print student information
	void print();

	// Getters
	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysInCourse();
	DegreeProgram getProgram() const;

	// Setters
	void setStudentId(string id);
	void setFirstName(string first);
	void setLastName(string last);
	void setEmailAddress(string email);
	void setAge(int years);
	void setDaysInCourse(int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree);
	void setProgram(DegreeProgram option);

private:
	// Member variables describing student information
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram program;
};