#include "Certificate.h"
#include <iostream>
using namespace std;

// Setter Methods
void Certificate::setCertificateID(const string& id) {
    certificateID = id;
}

void Certificate::setIssueDate(const string& date) {
    issueDate = date;
}

void Certificate::setCourseTitle(const string& title) {
    courseTitle = title;
}

void Certificate::setCertificateRecipent(Student* student) {
    recipent = student;
}

void Certificate::setCertificateCourse(Course* course) {
    this->course = course;
}

// Display Certificate details
void Certificate::displayCertificateDetails()const {
    cout << "Certificate ID: " << certificateID << endl;
    cout << "Issue Date: " << issueDate << endl;
    cout << "Course Title: " << courseTitle << endl;
    if (recipent) {
        cout << "Recipient: " << recipent->getName() << " (ID: " << recipent->getID() << ")" << endl;
    }
    else {
        cout << "Recipient: Not assigned yet" << endl;
    }
    if (course) {
        cout << "Course: " << course->getCourseTitle() << " (Code: " << course->getCourseCode() << ")" << endl;
    }
    else {
        cout << "Course: Not assigned yet" << endl;
    }
}


// Overloaded output operator (<<)
ostream& operator<<(ostream& os, const Certificate& certificate) {
    os << "Certificate ID: " << certificate.certificateID << "\n"
        << "Issue Date: " << certificate.issueDate << "\n"
        << "Course Title: " << certificate.courseTitle << "\n"
        << "Recipient: " << (certificate.recipent ? certificate.recipent->getName() : "Unknown Student") << "\n"
        << "Course: " << (certificate.course ? certificate.course->getCourseTitle() : "Unknown Course") << "\n";
    return os;
}

// Overloaded input operator (>>)
istream& operator>>(istream& is, Certificate& certificate) {
    string line;

    cout << "Enter Certificate ID: ";
    getline(is, certificate.certificateID);

    cout << "Enter Issue Date (e.g., 12-12-2024): ";
    getline(is, certificate.issueDate);

    cout << "Enter Course Title: ";
    getline(is, certificate.courseTitle);

    // For simplicity, assuming you can input recipient and course by name
    // You might want to look up the actual Student and Course based on input or ID
    cout << "Enter Recipient Name: ";
    string studentName;
    getline(is, studentName);
    // Assuming you handle student and course lookups by name or other logic
    certificate.recipent = nullptr;  // Placeholder for actual student assignment logic

    cout << "Enter Course Title: ";
    string courseTitle;
    getline(is, courseTitle);
    // Placeholder for course assignment logic
    certificate.course = nullptr;  // Placeholder for actual course assignment logic

    return is;
}
