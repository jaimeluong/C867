#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

// Default constructor
Student::Student() {
	studentId = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysInCourse[0] = 0;
	daysInCourse[1] = 0;
	daysInCourse[2] = 0;
	program = UNDECLARED;
}

// Constructor with parameters
Student::Student(string id, string first, string last, string email, int years, int days[], DegreeProgram option) {
	studentId = id;
	firstName = first;
	lastName = last;
	emailAddress = email;
	age = years;
	daysInCourse[0] = days[0];
	daysInCourse[1] = days[1];
	daysInCourse[2] = days[2];
	program = option;
}

// Print student information
void Student::print() {
	string degree;

	switch (program) {
	case SECURITY:
		degree = "Security";
		break;
	case NETWORK:
		degree = "Network";
		break;
	case SOFTWARE:
		degree = "Software";
		break;
	default:
		degree = "Undeclared";
		break;
	}

	cout << studentId << "	" << firstName << " " << lastName << "	" << age << "	" << getDaysInCourse()[0] << "," << getDaysInCourse()[1] << "," << getDaysInCourse()[2] << "	" << degree << endl;
}

// Getters
string Student::getStudentId() const {
	return studentId;
}
string Student::getFirstName() const {
	return firstName;
}
string Student::getLastName() const {
	return lastName;
}
string Student::getEmailAddress() const {
	return emailAddress;
}
int Student::getAge() const {
	return age;
}
int* Student::getDaysInCourse() {
	return daysInCourse;
}
DegreeProgram Student::getProgram() const {
	return program;
}

// Setters
void Student::setStudentId(string id) {
	studentId = id;
}
void Student::setFirstName(string first) {
	firstName = first;
}
void Student::setLastName(string last) {
	lastName = last;
}
void Student::setEmailAddress(string email) {
	emailAddress = email;
}
void Student::setAge(int years) {
	age = years;
}
void Student::setDaysInCourse(int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree) {
	for (int i = 0; i < 3; i++) {
		daysInCourse[0] = daysInCourseOne;
		daysInCourse[1] = daysInCourseTwo;
		daysInCourse[2] = daysInCourseThree;
	}
}
void Student::setProgram(DegreeProgram option) {
	program = option;
}