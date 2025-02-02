#include "Assignment.h"
#include "Student.h"
#include "Instructor.h"
#include <iostream>
using namespace std;

// Setter Methods
void Assignment::setAssignmentID(const string& id) {
    assignmentID = id;
}

void Assignment::setAssignmentDescription(const string& description) {
    assignmentDescription = description;
}

void Assignment::setMaxScore(int score) {
    maxScore = score;
}

void Assignment::setDueDate(const string& dueDate) {
    this->dueDate = dueDate;
}

// Student's Assignment Submission
void Assignment::submitAssignment(Student* student, int score) {
    if (score > maxScore) {
        cout << " Score cannot exceed the maximum score of " << maxScore << "." << endl;
        return;
    }
    submissions[student] = score;  // Add or update submission
    cout << " Assignment submitted successfully for " << student->getName() << " with score " << score << "." << endl;
}

// Student's Grade Submission
void Assignment::gradeAssignment(Student* student, int score) {
    if (submissions.find(student) == submissions.end()) {
        cout << " Error: No submission found for the student " << student->getName() << "." << endl;
        return;
    }
    submissions[student] = score;  // Update the score
    cout << " Assignment graded successfully for " << student->getName() << " with score " << score << "." << endl;
}

// Method to display assignment details
void Assignment::displayAssignmentDetails()const {
    cout << "Assignment ID: " << assignmentID << endl;
    cout << "Description: " << assignmentDescription << endl;
    cout << "Maximum Score: " << maxScore << endl;
    cout << "Due Date: " << dueDate << endl;
    cout << " Created by: " << (assignmentCreator ? assignmentCreator->getName() : " Unknown ") << endl;
}

// Method to display all submissions
void Assignment::displaySubmissin()const {
    if (submissions.empty()) {
        cout << " No submissions yet." << endl;
        return;
    }
    cout << " Submissions: " << endl;
    for (const auto& entry : submissions) {
        cout << " - " << entry.first->getName() << ": " << entry.second << "/" << maxScore << endl;
    }
}

// Overloaded output operator (<<)
ostream& operator<<(ostream& os, const Assignment& assignment) {
    os << "Assignment ID: " << assignment.assignmentID << "\n"
        << "Description: " << assignment.assignmentDescription << "\n"
        << "Max Score: " << assignment.maxScore << "\n"
        << "Due Date: " << assignment.dueDate << "\n"
        << "Creator: " << (assignment.assignmentCreator ? assignment.assignmentCreator->getName() : "Unknown") << "\n";

    os << "Submissions:\n";
    const auto& submissions = assignment.getSubmissions();
    if (submissions.empty()) {
        os << " No submissions yet.\n";
    }
    else {
        for (const auto& entry : submissions) {
            os << "Student: " << entry.first->getName() << ", Score: " << entry.second << "\n";
        }
    }

    return os;
}

// Overloaded input operator (>>)
istream& operator>>(istream& is, Assignment& assignment) {
    string line;

    cout << "Enter Assignment ID: ";
    getline(is, assignment.assignmentID);

    cout << "Enter Description: ";
    getline(is, assignment.assignmentDescription);

    cout << "Enter Max Score: ";
    is >> assignment.maxScore;
    is.ignore();  // To ignore the trailing newline after reading an integer

    cout << "Enter Due Date (e.g., 12-12-2024): ";
    getline(is, assignment.dueDate);

    // Assuming you can set the instructor via input (modify according to your actual logic)
    // For example:
    cout << "Enter Instructor Name: ";
    string instructorName;
    getline(is, instructorName);
    // Note: You'll need to find the instructor based on the name or ID. Here we'll leave it as a placeholder:
    assignment.assignmentCreator = nullptr;  // Assuming instructor assignment logic is handled separately.

    return is;
}