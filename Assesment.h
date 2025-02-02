#pragma once
#ifndef ASSESMENT_H
#define ASSESMENT_H
#include <iostream>
#include"Student.h"
#include<string>
#include <map>
using namespace std;
class Assesment {
private:
	string assesmentID;     // Unique Identifier for the Assesment
	string assesmentType;   // Type i.e Quiz, Exam or Project
	int totalMarks;         // Total Marks for the Assesment
	map<Student*, int> studentScores;  // Map to track students and their marks
public:
	// COnstructor
	Assesment(const string& id,const string& type, int marks):
		assesmentID(id), assesmentType(type), totalMarks(marks){}

	// Setter methods
	void setAssesmentID(const string& id);
	void setAssesmentType(const string& type);
	void setTotalMarks(int marks);

	// Getter Methods
	string getAssesmentID()const { return assesmentID; }
	string getAssesmentType()const { return assesmentType; }
	int getTotalMarks() const { return totalMarks; }
	const map<Student*, int> getStudentScores()const { return studentScores; }

	// Other Methods
	void takeAssesment(Student* student, int score);         // Record a student's score
	void displayAssesmentDetails()const;                     // Display assessment details
	void displayStudentScores()const;                        // Display all scores

	// Destructor
	~Assesment(){}

	bool operator==(const Assesment& other) const {
		return assesmentID == other.assesmentID;
	}
	friend ostream& operator<<(ostream& os, const Assesment& assesment);
	friend istream& operator>>(istream& is, Assesment& assesment);

};
#endif // !ASSESMENT_H
