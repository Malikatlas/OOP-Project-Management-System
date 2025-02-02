#pragma once
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Instructor:public Person {
private:
	string employeeID;               // Unique Indentifier
	string department;               // Department Name
	vector<string> assignedCourses;  // List of courses assigned to the Instructor
	


public:
	// Constructor
	Instructor(const string& name, const string& ID, const string& email, const string& employeeID, const string& department):
		Person(name, ID, email),employeeID(employeeID),department(department){}

	// Setter Methods(Instructor - specific)
	void createAssignment(const string& courseName, const string& assignmentDetails);
	void gradeSubmission(const string& studentID, const string courseName, int grade);
	void monitorStudentProgress(const string& studentID, const string& courseName)const;
	void issueCertification(const string& studentID, const string& courseName);

	
	


	// Getter Methods
	string getEmployeeID() const { return employeeID; }        // Return ID of the Instructor
	string getDepartment()const { return department; }         // Return Department of the Instructor
	const vector<string>& getAssignedCourses()const { return assignedCourses; }  // Return course assigned to the Intructor

	// Overridden Functions from Person Class
	void displayInfo()const override;
	string getRole()const override;
	void sendNotification(const string& message)const override;
	void saveData() override;
	void loadData() override;

	// Destructor
	~Instructor() override{}

	bool operator==(const Instructor& other) const {
		return employeeID == other.employeeID;
	}

	Instructor& operator=(const Instructor& other);
	friend ostream& operator<<(ostream& os, const Instructor& instructor);
	friend istream& operator>>(istream& is, Instructor& instructor);



};
#endif // !INSTRUCTOR_H

