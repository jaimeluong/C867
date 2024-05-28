#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

// Parse string of student data into a Student object
void Roster::parse(string row) {
	if (rosterIndex < classSize) {
		classRosterArray[rosterIndex] = new Student();

		int daysInCourseOne, daysInCourseTwo, daysInCourseThree;

		int start = 0;
		int end = row.find(',');
		classRosterArray[rosterIndex]->setStudentId(row.substr(start, end - start));

		start = end + 1;
		end = row.find(',', start);
		classRosterArray[rosterIndex]->setFirstName(row.substr(start, end - start));

		start = end + 1;
		end = row.find(',', start);
		classRosterArray[rosterIndex]->setLastName(row.substr(start, end - start));

		start = end + 1;
		end = row.find(',', start);
		classRosterArray[rosterIndex]->setEmailAddress(row.substr(start, end - start));

		start = end + 1;
		end = row.find(',', start);
		classRosterArray[rosterIndex]->setAge(stoi(row.substr(start, end - start)));

		start = end + 1;
		end = row.find(',', start);
		daysInCourseOne = stoi(row.substr(start, end - start));

		start = end + 1;
		end = row.find(',', start);
		daysInCourseTwo = stoi(row.substr(start, end - start));

		start = end + 1;
		end = row.find(',', start);
		daysInCourseThree = stoi(row.substr(start, end - start));

		classRosterArray[rosterIndex]->setDaysInCourse(daysInCourseOne, daysInCourseTwo, daysInCourseThree);

		start = end + 1;
		string option = row.substr(start, end - start);
		if (option == "SECURITY") {
			classRosterArray[rosterIndex]->setProgram(SECURITY);
		}
		else if (option == "NETWORK") {
			classRosterArray[rosterIndex]->setProgram(NETWORK);
		}
		else {
			classRosterArray[rosterIndex]->setProgram(SOFTWARE);
		}

		rosterIndex++;
	}
}

// Add Student object to Roster
void Roster::add(string id, string first, string last, string email, int years, int daysCourseOne, int daysCourseTwo, int daysCourseThree, DegreeProgram option) {
	int daysInCourseArray[3] = { daysCourseOne, daysCourseTwo, daysCourseThree };
	classRosterArray[classSize] = new Student(id, first, last, email, years, daysInCourseArray, option);
}

// Remove student from roster given Student ID
void Roster::remove(string id) {
	bool found = false;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentId() == id) {
				classRosterArray[i] = nullptr;
				found = true;
			}
		}
	}

	if (found) {
		cout << "Student with ID of " << id << " removed from roster" << endl;
	}
	else {
		cout << "No student with ID of " << id << " found in roster" << endl;
	}
}

// Print all student data in roster
void Roster::printAll() {
	cout << "Printing all student data in roster" << endl;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

// Print the average days in courses given Student ID
void Roster::printAverageDaysInCourse(string id) {
	bool found = false;
	int average;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getStudentId() == id) {
			average = (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << "Student with ID of " << id << " has an average of " << average << " days in course" << endl;
		}
	}
}

// Print invalid emails throughout roster
void Roster::printInvalidEmails() const {
	for (int i = 0; i < classSize; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << "The email address " << classRosterArray[i]->getEmailAddress() << " is invalid, belonging to student with ID of " << classRosterArray[i]->getStudentId() << endl;
		}
	}
}

// Constructor with parameters
Roster::Roster(int size) {
	classSize = size;
	rosterIndex = 0;
	for (int i = 0; i < classSize; i++) {
		classRosterArray[i] = new Student();
	}
}

// Getter for Student ID given position in roster
string Roster::getStudentId(int index) const {
	string studentId = classRosterArray[index]->getStudentId();
	return studentId;
}

// Print students in given degree program
void Roster::printByDegreeProgram(DegreeProgram option) {
	string degree;

	switch (option) {
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

	cout << "Students in " << degree << " program" << endl;

	bool found = false;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getProgram() == option) {
			classRosterArray[i]->print();
			found = true;
		}
	}
	if (!found) {
		cout << "No students in " << degree << " program found" << endl;
	}
}

// Destructor
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}