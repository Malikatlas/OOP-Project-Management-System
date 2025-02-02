#pragma once
#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include <iostream>
#include "Student.h"
#include "Course.h"
using namespace std;

class Certificate {
private:
	string certificateID;       // Unique Identifier for the Certificate
	string issueDate;           // Issue Date of the Certificate
	string courseTitle;         // Title of the completed course
	Student* recipent;           // Student who receives the certificate
	Course* course;             // Course for which certificate is issued
public:
	// Constructor
	Certificate(const string& id, const string& date, const string& title, Student* student, Course* course):
		certificateID(id), issueDate(date), courseTitle(title), recipent(student),course(course){}

	// Setter Methods
	void setCertificateID(const string& id);
	void setIssueDate(const string& date);
	void setCourseTitle(const string& title);
	void setCertificateRecipent(Student* student);
	void setCertificateCourse(Course* course);

	// Getter Methods
	string getCertificateID()const { return certificateID; }
	string getIssueDate()const { return issueDate; }
	string getCourseTitle()const { return courseTitle; }
	Student* getCertificateRecipent()const { return recipent; }
	Course* getCertificateCourse()const { return course; }

	// Display Certificate details
	void displayCertificateDetails()const;            

	// Destructor
	~Certificate(){}

	bool operator==(const Certificate& other) const {
		return certificateID == other.certificateID;
	}

	// Overloaded operators
	friend ostream& operator<<(ostream& os, const Certificate& certificate);  // Stream output (<<)
	friend istream& operator>>(istream& is, Certificate& certificate);        // Stream input (>>)

};
#endif // !CERTIFICATE_H
