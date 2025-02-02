#include "Assesment.h"
#include "Student.h"
#include<string>
#include <map>
#include <iostream>
using namespace std;

// Setter for Assesment ID
void Assesment::setAssesmentID(const string& id) {
    assesmentID = id;
}

// Setter for Assesment Type
void Assesment::setAssesmentType(const string& type) {
    assesmentType = type;
}

// Setter for Total Marks
void Assesment::setTotalMarks(int marks) {
    if (marks > 0) {
        totalMarks = marks;
    }
    else {
        cout << " Invalid Marks. Please enter a positive value." << endl;
    }
}

// Record a student's score
void Assesment::takeAssesment(Student* student, int score) {
    if (student == nullptr) {
        cout << " Invalid student." << endl;
        return;
    }
    if (score<0 || score>totalMarks) {
        cout << " Invalid score. Please enter a value between 0 and " << totalMarks << ".";
        return;
    }

    // Add or update the student's score
    studentScores[student] = score;
    cout << "Score recorded for " << student->getName() << ": " << score << " out of " << totalMarks << endl;
}

// Display details of the assessment
void Assesment::displayAssesmentDetails() const {
    cout << "Assesment ID: " << assesmentID << endl;
    cout << "Assesment Type: " << assesmentType << endl;
    cout << "Total Marks: " << totalMarks << endl;
}

// Display all student scores
void Assesment::displayStudentScores()const {
    if (studentScores.empty()) {
        cout << " No scores recorded yet."<<endl;
        return;
    }
    cout << " Student Scores: " << endl;
    for (const auto& entry : studentScores) {
        cout << " Student: " << entry.first->getName() << ", Score: " << entry.second << endl;
    }
}

ostream& operator<<(ostream& os, const Assesment& assessment) {
    os << "Assessment ID: " << assessment.assesmentID << "\n"
        << "Type: " << assessment.assesmentType << "\n"
        << "Total Marks: " << assessment.totalMarks << "\n"
        << "Scores:\n";
    for (const auto& entry : assessment.studentScores) {
        Student* student = entry.first;
        int score = entry.second;
        os << " - " << (student ? student->getName() : "Unknown Student") << ": " << score << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Assesment& assessment) {
    cout << "Enter Assessment ID: ";
    getline(is, assessment.assesmentID);
    cout << "Enter Type: ";
    getline(is, assessment.assesmentType);
    cout << "Enter Total Marks: ";
    is >> assessment.totalMarks;
    is.ignore(); // Ignore the trailing newline
    return is;
}
