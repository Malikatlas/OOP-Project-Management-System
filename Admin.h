#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "Person.h"
#include <string>
#include <vector>
using namespace std;

class Admin:private Person{
private:
	string adminID;               // Unique Indetifier for Admin
	vector<string> privileges;    // List of Admin privileges
	string department;            // Department of Admin
public:
	// Constructor
	Admin(const string& name, const string& ID, const string& email, const string& adminID, const string& department, const vector<string> privileges):
		Person(name,ID,email),adminID(adminID),department(department),privileges(privileges){}

	// Setter Methods(Admin - specific)
	void addCourse(const string& courseName);
	void removeCourse(const string& courseName);
	void assignInstructor(const string& courseName, const string& instructorID);
	void generateReport();
	void manageCertification(const string& studentID, const string& courseName);
	void sendNotificationToSystem(const string& message);


	// Getter Methods
	string getAdminID()const { return adminID; }        // Return the ID of Admin
	string getDepartment()const { return department; }  // Return the Department of Admin
	const vector<string>& getPrivileges()const { return privileges; } // Return the Privileges of the Admin

	// Overridden Function for th person Class
	void displayInfo()const override;
	string getRole()const override { return "Admin"; }
	void sendNotification(const string& message) const override;
	void saveData() override;
	void loadData() override;

	// Destructor
	~Admin() override{}

	bool operator==(const Admin& other) const {
		return adminID == other.adminID;
	}
	friend ostream& operator<<(ostream& os, const Admin& admin);
	friend istream& operator>>(istream& is, Admin& admin);


};
#endif // !ADMIN_H

