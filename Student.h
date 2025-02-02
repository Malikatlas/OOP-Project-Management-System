#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Student :public Person {
private:
	string studentID;                          // Student unique Identifier
	string enrollmentDate;                     // Student Enrollment Date
	vector<string> completedCourses;           // Course completed by Student
	vector<string> currentGroups;              // Groups for peer collaboration

public:
	// Constructor
	Student(const string& name, const string& id, const string& email,
		const string& studentID, const string& enrollmentDate)
		:Person(name, id, email), studentID(studentID), enrollmentDate(enrollmentDate) {}


	// setter methods
	void enrollInCourse(const string& courseName);      // Enroll in Course
	void submitAssignment(const string& courseName, const string& assigment);  // Submit an assignment
	float checkProgress(const string& courseName)const; // check progress of the course
	void addCertification(const string& courseName);    // Add a completed course to certification
	void joinGroup(const string& groupName);            // Join Group for peer collaboration

	// getter methods
	string getStudentID()const { return studentID; }            // Return student ID
	string getEnrollmentDate()const { return enrollmentDate; }  // Return Student Enrollment Date
	const vector<string>& getCompletedCourses() const { return completedCourses; }  // Return list of completed courses
	const vector<string>& getCurrentGroups()const { return currentGroups; }        // Return current group of Student

	// Overriden Fuctions from Person class
	void displayInfo()const override;
	string getRole()const override;
	void sendNotification(const string& message) const override;
	void saveData() override;
	void loadData() override;

	// Destructor
	~Student() override {}

	bool operator==(const Student& other) const {
		return studentID == other.studentID;
	}

	Student& operator=(const Student& other);
	friend ostream& operator<<(ostream& os, const Student& student);
	friend istream& operator>>(istream& is, Student& student);


};
#endif


