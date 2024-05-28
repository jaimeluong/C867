#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

int main() {
	// Print project information
	cout << "C867 Scripting and Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "ID: 012117784" << endl;
	cout << "Name: Jaime Luong" << endl;
	cout << "" << endl;

	// Given student data
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jaime,Luong,jluon13@wgu.edu,25,30,40,50,SOFTWARE"
	};

	// Create and populate Roster with Students
	Roster* classRoster = new Roster(5);
	for (int i = 0; i < 5; i++) {
		classRoster->parse(studentData[i]);
	}

	// Start demonstrating program functionalities
	classRoster->printAll();
	cout << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	for (int i = 0; i < 5; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentId(i));
	}
	cout << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	classRoster->printAll();
	cout << endl;
	classRoster->remove("A3");
	classRoster->~Roster();
	delete classRoster;
}