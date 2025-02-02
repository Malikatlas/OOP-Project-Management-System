#include "Admin.h"
#include <iostream>
#include <sstream>
#include <string>
#include<map>
#include <algorithm>
#include <fstream> // For file handling
using namespace std;


// Function to add a course
void Admin::addCourse(const string& courseName) {
	cout << "Adding course: " << courseName << endl;
	// Logic to add a course (can be expanded based on a course database or file handling)
}

// Function to remove a course
void Admin::removeCourse(const string& courseName) {
	cout << "Removing course: " << courseName << endl;
	// Logic to remove a course (can be expanded based on a course database or file handling)
}

// Function to assign an instructor to a course
void Admin::assignInstructor(const string& courseName, const string& instructorID) {
	cout << "Assigning instructor (ID: " << instructorID << ") to course: " << courseName << endl;
	// Logic to assign instructor (can involve updating an instructor-course relationship in a database)
}

// Function to generate reports
void Admin::generateReport() {
	cout << "Generating system report..." << endl;
	// Logic to generate and output reports (e.g., from a database or files)
	// This could involve student performance, course completion stats, etc.
}

// Function to manage certifications
void Admin::manageCertification(const string& studentID, const string& courseName) {
	cout << "Managing certification for student ID: " << studentID << " for course: " << courseName << endl;
	// Logic to issue or revoke certifications (could interact with a `Certificate` class or file)
}

// Function to send a notification to the system
void Admin::sendNotificationToSystem(const string& message) {
	cout << "System-wide notification sent: " << message << endl;
	// Logic to broadcast messages (could involve interacting with a `Notification` class)
}

// Overridden function to display admin information
void Admin::displayInfo() const {
	cout << "Admin Name: " << name << endl;
	cout << "ID: " << ID << endl;
	cout << "Email: " << email << endl;
	cout << "Admin ID: " << adminID << endl;
	cout << "Department: " << department << endl;

	cout << "Privileges: ";
	for (const string& privilege : privileges) {
		cout << privilege << ", ";
	}
	cout << endl;
}

// Overridden function to send notifications
void Admin::sendNotification(const string& message) const {
	cout << "Admin-specific notification sent: " << message << endl;
}

void Admin::saveData() {
	std::ofstream outputFile("admin_" + this->name + "_output.txt");

	if (outputFile.is_open()) {
		outputFile << "Name:" << this->getName() << std::endl;
		outputFile << "ID:" << this->getID() << std::endl;
		outputFile << "Email:" << this->getEmail() << std::endl;
		outputFile << "Admin ID:" << this->getAdminID() << std::endl;
		outputFile << "Department:" << this->getDepartment() << std::endl;


		vector<string> privileges = this->getPrivileges();

		outputFile << "Privileges:";
		for (int i = 0; i < privileges.size(); i++) {
			outputFile << privileges[i] << ",";
		}
		outputFile << std::endl;
		outputFile.close();

		std::cout << "Saved Admin " << this->getName() << " Data To File" << std::endl;
	}
}

void Admin::loadData() {
	std::ifstream inputFile("admin_" + this->name + "_output.txt");

	std::cout << "Data For Admin " << this->name << std::endl;
	std::cout << "===========================\n";

	if (inputFile.is_open()) {
		// Current Line
		std::string currLine;

		// Read File Line By Line
		while (std::getline(inputFile, currLine)) {
			std::cout << currLine << std::endl;
		}

		inputFile.close();
		std::cout << endl;
	}
}



ostream& operator<<(ostream& os, const Admin& admin) {
	os << "Admin Name: " << admin.name << "\n"
		<< "Admin ID: " << admin.adminID << "\n"
		<< "Department: " << admin.department << "\n"
		<< "Privileges: ";
	for (const auto& privilege : admin.privileges) {
		os << privilege << " ";
	}
	return os;
}

istream& operator>>(istream& is, Admin& admin) {
	cout << "Enter Admin Name: ";
	getline(is, admin.name); // From `Person` class
	cout << "Enter Admin ID: ";
	getline(is, admin.adminID);
	cout << "Enter Department: ";
	getline(is, admin.department);

	admin.privileges.clear();
	cout << "Enter Privileges (comma-separated): ";
	string line;
	getline(is, line);
	stringstream ss(line);
	string privilege;
	while (getline(ss, privilege, ',')) {
		admin.privileges.push_back(privilege);
	}
	return is;
}
