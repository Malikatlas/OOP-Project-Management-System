#include "Instructor.h"
#include "Student.h"
#include "Certificate.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;



// Function to create an assignment for a course
void Instructor::createAssignment(const string& courseName, const string& assignmentDetails) {
	cout << " Assignment has created for the course " << courseName << endl;
	cout << " Details: " << assignmentDetails << endl;
	assignedCourses.push_back(courseName);   // The course is assigned if an assignment is created
}

// Function to submit grades of Student
void Instructor::gradeSubmission(const string& studentID, const string courseName, int grade) {
	cout << " Grading submission for student ID: " << studentID << endl;
	cout << " Course: " << courseName << ", Grade: " << grade << endl;

	// Grade validation
	if (grade < 0 || grade>100) {
		throw invalid_argument(" Grade must be between 0 and 100.");
	}
}

// Function to monitor progress of student
void Instructor::monitorStudentProgress(const string& studentID, const string& courseName)const {
	cout << " Monitoring progress for student ID: " << studentID << endl;
	cout << " For Course: " << courseName << endl;
	// You can add logic to check progress from a data source if needed
}

// Function to issue certificate to a student
void Instructor::issueCertification(const string& studentID, const string& courseName) {
	cout << " Certificate issued to student ID: " << studentID << endl;
	cout << " For course: " << courseName << endl;
	// This could interact with a "Certificate" class in a more advanced implementation
} 

// Overridden displayInfo function
void Instructor::displayInfo()const {
	cout << " Instructor Name: " << name << endl;
	cout << " ID: " << ID << endl;
	cout << " Email: " << email << endl;
	cout << " Employee ID: " << employeeID << endl;
	cout << " Department: " << department << endl;
	if (!assignedCourses.empty()) {
		for (const string& course : assignedCourses) {
			cout << course << " , ";
		}
		cout << endl;
	}
}

// Overridden get role function
string Instructor::getRole()const { return "Instructor"; }

// Overridden send notification function
void Instructor::sendNotification(const string& message)const {
	cout << " Notification to all assigned course students. " << endl;
	cout << " Message: " << message << endl;
}

Instructor& Instructor::operator=(const Instructor& other) {
	if (this != &other) { // Self-assignment check
		Person::operator=(other); // Call base class assignment operator
		employeeID = other.employeeID;
		department = other.department;
		assignedCourses = other.assignedCourses; // `vector` manages its own deep copy
	}
	return *this;
}

void Instructor::saveData() {
	std::ofstream outputFile("instructor_" + this->name + "_output.txt");

	if (outputFile.is_open()) {
		outputFile << "Name:" << this->getName() << std::endl;
		outputFile << "ID:" << this->getID() << std::endl;
		outputFile << "Email:" << this->getEmail() << std::endl;
		outputFile << "Employee ID:" << this->getEmployeeID() << std::endl;
		outputFile << "Department:" << this->getDepartment() << std::endl;


		vector<string> assignedCourses = this->getAssignedCourses();

		outputFile << "Assigned Courses:";
		for (int i = 0; i < assignedCourses.size(); i++) {
			outputFile << assignedCourses[i] << ",";
		}
		outputFile << std::endl;
		outputFile.close();

		std::cout << "Saved Instructor " << this->getName() << " Data To File" << std::endl;
	}
}

void Instructor::loadData() {
	std::ifstream inputFile("instructor_" + this->name + "_output.txt");

	std::cout << "Data For Instructor " << this->name << std::endl;
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

ostream& operator<<(ostream& os, const Instructor& instructor) {
	os << " Instructor Name: " << instructor.getName() << "\n"
		<< " Employee ID: " << instructor.employeeID << "\n"
		<< " Department: " << instructor.department << "\n"
		<< " Assigned Courses: ";
	for (const auto& course : instructor.assignedCourses) {
		os << course << " ";
	}
	return os;
}

istream& operator>>(istream& is, Instructor& instructor) {
	cout << " Enter Instructor Name: ";
	getline(is, instructor.name); // Using Person's protected name
	cout << " Enter Employee ID: ";
	is >> instructor.employeeID;
	is.ignore(); // Ignore trailing newline
	cout << " Enter Department: ";
	getline(is, instructor.department);

	// Optional: Clear and input assigned courses
	instructor.assignedCourses.clear();
	cout << " Enter Assigned Courses (comma-separated, end with newline): ";
	string coursesLine;
	getline(is, coursesLine);
	stringstream ss(coursesLine);
	string course;
	while (getline(ss, course, ',')) {
		instructor.assignedCourses.push_back(course);
	}
	return is;
}

	