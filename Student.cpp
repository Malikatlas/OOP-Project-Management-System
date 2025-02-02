#include "Student.h"
#include <iostream>
#include <sstream>
using namespace std;

// Function to display student Information
void Student::displayInfo()const {
	cout << " Student Name: " << name << endl;                   // Accessed from Person
	cout << " ID: " << ID << endl;                               // Accessed from Person
	cout << " Email: " << email << endl;                         // Accessed from Person
	cout << " Student ID: " << studentID << endl;
	cout << " Enrollment Date: " << enrollmentDate << endl;
	cout << " Completed course: ";
	for (const auto& course : completedCourses) {
		cout << course << " ";
	}
	cout << "\nGroups:";
	for (const auto& group : currentGroups) {
		cout << group << " ";
	}
	cout << endl;

}
// Function to get role of person
string Student::getRole()const { return "Student"; }

// Function to send notification to student
void Student::sendNotification(const string& message) const {
	cout << " Notification for Student " << name << " : " << message << endl;
}
// function to enroll in course
void Student::enrollInCourse(const string& courseName) {
	cout << name << " has enrolled in the course " << courseName << endl;
	completedCourses.push_back(courseName);
}

// Function to submit assignment
void Student::submitAssignment(const string& courseName, const string& assigment) {
	cout << name << " has submitted assignment " << assigment << " for the course " << courseName << endl;
}

// Function to check progress
float Student::checkProgress(const string& courseName)const {
	cout << " CHecking progress for " << name << " in course " << courseName << "\n";
	// You can add percentage logic here 
	return 75.0f; // Assuming for example
}

// Function to add Certification
void Student::addCertification(const string& courseName) {
	completedCourses.push_back(courseName);
	cout << " Added certification for the course " << courseName << " successfully.\n";
}

// Function to join group
void Student::joinGroup(const string& groupName) {
	cout << name << " joined the group " << groupName << "\n";
	currentGroups.push_back(groupName);
}

// Self-Assignment Operator
Student& Student::operator=(const Student& other) {
	if (this != &other) { // Self-assignment check
		// Free any existing resources if applicable (not required here since no dynamic memory in Student)

		// Copy primitive and standard data members
		name = other.name;
		ID = other.ID;
		email = other.email;
	}
	return *this; // Return *this to allow chained assignments
}

void Student::saveData(){
	std::ofstream outputFile("student_" + this->name + "_output.txt");

	if (outputFile.is_open()) {
		outputFile << "Name:" << this->getName() << std::endl;
		outputFile << "ID:" << this->getID() << std::endl;
		outputFile << "Email:" << this->getEmail() << std::endl;
		outputFile << "Student ID:" << this->getStudentID() << std::endl;
		outputFile << "Enrollment Date:" << this->getEnrollmentDate() << std::endl;


		vector<string> completedCourses = this->getCompletedCourses();

		outputFile << "Completed Courses:";
		for (int i = 0; i < completedCourses.size(); i++) {
			outputFile << completedCourses[i] << ",";
		}
		outputFile << std::endl;

		vector<string> currentGroups = this->getCurrentGroups();

		outputFile << "Current Groups:";
		for (int i = 0; i < currentGroups.size(); i++) {
			outputFile << currentGroups[i] << ",";
		}
		outputFile << std::endl;


		outputFile.close();

		std::cout << "Saved Student " << this->getName() << " Data To File" << std::endl;
	}
}

void Student::loadData() {
	std::ifstream inputFile("student_" + this->name + "_output.txt");

	std::cout << "Data For Student " << this->name << std::endl;
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

// Output operator overloading
ostream& operator<<(ostream& os, const Student& student) {
	os << "Student Name: " << student.name << "\n"
		<< "Student ID: " << student.ID << "\n"
		<< "Email: " << student.email;
	return os; // Return the stream for chaining
}

// Input operator overloading
istream& operator>>(istream& is, Student& student) {
	cout << "Enter Student Name: ";
	getline(is, student.name);
	cout << "Enter Student ID: ";
	is >> student.ID;
	is.ignore(); // Ignore trailing newline
	cout << "Enter Email: ";
	getline(is, student.email);
	return is; // Return the stream for chaining
}



