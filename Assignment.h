#pragma once
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
#include "Student.h"    // Include the header file for Student class
#include "Instructor.h"  // Include the header file for Instructor class
#include <string>
#include <vector>
#include <map>
using namespace std;

class Assignment {
private:
	string assignmentID;           // Unique Identifier for the Assignment
	string assignmentDescription;  // Description of the Assignment
	int maxScore;                  // Maximum possible scores
	string dueDate;                // Submission Date of Assignment
	Instructor* assignmentCreator; // Creator of Assignment
	map<Student*, int> submissions; // Map of Student pointers to their submitted scores
public:
	// COnstructor
	Assignment(const string& ID, const string& desc, int maxScore, const string& dueDate):
		assignmentID(ID),assignmentDescription(desc),maxScore(maxScore),dueDate(dueDate){}

	// Setter Methods
	void setAssignmentID(const string& id);
	void setAssignmentDescription(const string& description);
	void setMaxScore(int score);
	void setDueDate(const string& dueDate);

	// Getter Methods
	string getAssignmentID()const { return assignmentID; }
	string getAssignmentDescription()const { return assignmentDescription; }
	int getMaxScore()const { return maxScore; }
	string getDueDate()const { return dueDate; }
	Instructor* getAssignmentCreator()const { return assignmentCreator; }
	const map<Student*, int>& getSubmissions()const { return submissions; }

	// Other Methods
	void submitAssignment(Student* student, int score);   // Student's Assignment Submission
	void gradeAssignment(Student* student, int score);    // Student's Grade
	void displayAssignmentDetails()const;                 // Display Assignment Details
	void displaySubmissin()const;                         // Display all submissions

	// Destructor
	~Assignment(){}

	bool operator==(const Assignment& other) const {
		return assignmentID == other.assignmentID;
	}

	// Overloaded operators
	friend ostream& operator<<(ostream& os, const Assignment& assignment);  // Stream output (<<)
	friend istream& operator>>(istream& is, Assignment& assignment);        // Stream input (>>)



};
#endif // !ASSIGNMENT_H

