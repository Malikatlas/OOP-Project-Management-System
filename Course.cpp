#include "Course.h"
#include "Instructor.h"
#include "Student.h"
#include "Module.h"
#include <iostream>
using namespace std;

// Setter for course title
void Course::setCourseTitle(const string& courseTitle) {
    this->courseTitle = courseTitle;
}

// Setter for course code
void Course::setCourseCode(const string& courseCode) {
    this->courseCode = courseCode;
}

// Setter for course description
void Course::setCourseDescription(const string& description) {
    this->description = description;
}

// Setter for assigning an instructor
void Course::setInstructor(Instructor* instructor) {
    this->instructor = instructor;
}

// Add a student to the course
void Course::enrollStudent(Student* student){
    if (student) {
        enrolledStudents.push_back(student);
        cout << " Student" << student->getName() << " has enrolled in the course: " << courseTitle << endl;
    }
    else {
        cout << " Invalid student!" << endl;
    }
}

// Add a module to the course
void Course::addModule(const Module& module) {
    modules.push_back(module);
    cout << " Module added to course: " << module.getModuleTitle() << endl;
}

// Display course details and related Information
void Course::displayCourseDetails()const {
    cout << " Course Title: " << courseTitle << endl;
    cout << " Course Code: " << courseCode << endl;
    cout << " Description: " << description << endl;

    if (instructor) {
        cout << " Instructor: " << instructor->getName() << endl;
    }
    else {
        cout << " Instructor not assigned" << endl;
    }

    cout << " Endrolled students: ";
    if (!enrolledStudents.empty()) {
        for (Student* student : enrolledStudents) {
            cout << student->getName() << " , ";
        }
        cout << endl;
    }
    else {
        cout << " None" << endl;
    }

    cout << " Modules: ";
    if (!modules.empty()) {
        for (const Module& module : modules) {
            cout << module.getModuleTitle() << " , ";
        }
        cout << endl;
    }
    else {
        cout << " None" << endl;
    }
}

Course& Course::operator=(const Course& other) {
    if (this == &other) {
        return *this;  // Return the object itself if it’s the same object.
    }

    // Copy the simple data members
    courseTitle = other.courseTitle;
    courseCode = other.courseCode;
    description = other.description;

    // Deep copy the instructor (if necessary)
    if (other.instructor) {
        instructor = new Instructor(*other.instructor);
    }
    else {
        instructor = nullptr;
    }

    // Deep copy the enrolled students (if necessary)
    enrolledStudents = other.enrolledStudents;

    // Deep copy the modules (assuming shallow copy of module is fine)
    modules = other.modules;

    return *this;
}

void Course::saveData() {
    std::ofstream outputFile("course_" + this->getCourseTitle() + "_output.txt");

    if (outputFile.is_open()) {
        outputFile << "Course Title:" << this->getCourseTitle() << std::endl;
        outputFile << "Course Code:" << this->getCourseCode() << std::endl;
        outputFile << "Description:" << this->getCourseDescription() << std::endl;
        outputFile << "Instructor:" << this->instructor->getName() << std::endl;
     
        vector<Student*> students = this->getEnrolledStudents();

        outputFile << "Enrolled Students:";
        for (int i = 0; i < students.size(); i++) {
            outputFile << students[i]->getName() << ",";
        }
        outputFile << std::endl;
        outputFile.close();

        std::cout << "Saved Course " << this->getCourseTitle() << " Data To File" << std::endl;
    }
}

void Course::loadData() {
    std::ifstream inputFile("course_" + this->getCourseTitle() + "_output.txt");

    std::cout << "Data For Course " << this->getCourseTitle() << std::endl;
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

ostream& operator<<(ostream& os, const Course& course) {
    os << "Course Title: " << course.courseTitle << "\n"
        << "Course Code: " << course.courseCode << "\n"
        << "Description: " << course.description << "\n"
        << "Instructor: " << (course.instructor ? course.instructor->getName() : "None") << "\n"
        << "Modules: ";
    for (const auto& module : course.modules) {
        os << module.getModuleTitle() << ", ";
    }
    os << "\nEnrolled Students: ";
    for (const auto& student : course.enrolledStudents) {
        os << student->getName() << " ";
    }
    return os;
}

istream& operator>>(istream& is, Course& course) {
    cout << "Enter course title: ";
    getline(is, course.courseTitle);

    cout << "Enter course code: ";
    getline(is, course.courseCode);

    cout << "Enter course description: ";
    getline(is, course.description);

    // You could also input the instructor here if needed
    // For simplicity, assuming we can set a null instructor in the constructor

    return is;
}



