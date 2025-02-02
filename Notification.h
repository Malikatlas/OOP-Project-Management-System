#pragma once
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include<iostream>
#include "Student.h"
#include "Instructor.h"
#include <vector>
#include <string>
using namespace std;

class Notification {
private:
	string notificationID;              // Unique Identifier for the Notification
	string message;                     // Content of the Notification
	string dateSent;                    // Date of message sent
	vector<Student*>students;           // List of students to receive notification
	vector<Instructor*> instructors;    // List of Istructors to receive notification
public:
	//Costructor
	Notification(const string& id, const string& message, const string& date ):
		notificationID(id),message(message), dateSent(date){}

	// Setter Methods
	void setNotificationID(const string& id);
	void setNotificationMessage(const string& message);
	void setNotificationDateSent(const string& date);

	// Getter methods
	string getNotificationID()const { return notificationID; }
	string getNotificationMessage()const { return message; }
	string getNotificationDateSent()const { return dateSent; }
	const vector<Student*>& getStudents()const { return students; }
	const vector<Instructor*>& getInstructors()const { return instructors; }

	// other methods
	void addStudentRecipent(Student* student);                          // Add student recipent to the List
	void addInstructorRecipent(Instructor* instructor);                 // Add Instructor recipent to the List
	void broadcast();                                                   // send notification to all recipents
	void displayNotificationDetails()const;                             // Display notification details

	// Destructor
	~Notification(){}

	bool operator==(const Notification& other) const {
		return notificationID == other.notificationID;
	}
	friend ostream& operator<<(ostream& os, const Notification& notification);
	friend istream& operator>>(istream& is, Notification& notification);



};
#endif // !NOTIFICATION_H

