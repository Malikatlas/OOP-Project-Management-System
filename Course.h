#pragma once
#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#include "Module.h"
#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course {
private:
    string courseTitle;  // The Title of the Course
    string courseCode;   // Unique Identifier for the course
    string description;  // Description of the Course
    Instructor* instructor;  // Aggregated relationship with Instructor
    vector<Student*> enrolledStudents;   // Associated relationship with students
    vector<Module> modules;              // Composed with module objects

public:
    // Constructor
    Course(const string& title, const string& code, const string& desc, Instructor* instructor = nullptr)
        : courseTitle(title), courseCode(code), description(desc), instructor(instructor) {}

    // Setter methods
    void setCourseTitle(const string& courseTitle);
    void setCourseCode(const string& courseCode);
    void setCourseDescription(const string& description);
    void setInstructor(Instructor* instructor);

    // Getter methods
    string getCourseTitle() const {
        return courseTitle;
    }
    string getCourseCode() const {
        return courseCode;
    }
    string getCourseDescription() const {
        return description;
    }
    const vector<Student*>& getEnrolledStudents() const {
        return enrolledStudents;
    }
    const vector<Module>& getCourseModule() const {
        return modules;
    }

    // Other methods
    void enrollStudent(Student* student);     // Add a student to the course
    void addModule(const Module& module);     // Add a module to the course
    void displayCourseDetails() const;         // Display course details and related information
    void saveData();
    void loadData();


    // Destructor
    ~Course() {}

    bool operator==(const Course& other) const {
        return courseCode == other.courseCode;
    }

    Course& operator=(const Course& other);   // Copy assignment operator
    friend ostream& operator<<(ostream& os, const Course& course);
    friend istream& operator>>(istream& is, Course& course);
};

#endif // !COURSE_H
