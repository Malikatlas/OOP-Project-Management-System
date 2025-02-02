#include "Notification.h"
#include <iostream>
using namespace std;

// Setter Methods
void Notification::setNotificationID(const string& id) {
    notificationID = id;
}

void Notification::setNotificationMessage(const string& message) {
    this->message = message;
}

void Notification::setNotificationDateSent(const string& date) {
    dateSent = date;
}

// Add a student recipient to the notification
void Notification::addStudentRecipent(Student* student) {
    if (student) {
        students.push_back(student);
    }
    else {
        cout << " Invalid student recipient!" << endl;
    }
}

// Add an instructor recipient to the notification
void Notification::addInstructorRecipent(Instructor* instructor) {
    if (instructor) {
        instructors.push_back(instructor);
    }
    else {
        cout << " Invalid instructor recipient!" << endl;
    }
}

// Broadcast the notification to all recipients
void Notification::broadcast() {
    cout << "Broadcasting notification: " << notificationID << endl;
    cout << "Message: " << message << endl;
    cout << "Date Sent: " << dateSent << endl;

    cout << "Sending to Students:" << endl;
    for (const auto& student : students) {
        if (student) {
            cout << "- " << student->getName() << " (ID: " << student->getID() << ")" << endl;
        }
    }

    cout << "Sending to Instructors:" << endl;
    for (const auto& instructor : instructors) {
        if (instructor) {
            cout << "- " << instructor->getName() << " (ID: " << instructor->getID() << ")" << endl;
        }
    }
}

// Display notification details
void Notification::displayNotificationDetails() const {
    cout << "Notification ID: " << notificationID << endl;
    cout << "Message: " << message << endl;
    cout << "Date Sent: " << dateSent << endl;

    cout << "Students Recipients:" << endl;
    for (const auto& student : students) {
        if (student) {
            cout << "- " << student->getName() << " (ID: " << student->getID() << ")" << endl;
        }
    }

    cout << "Instructor Recipients:" << endl;
    for (const auto& instructor : instructors) {
        if (instructor) {
            cout << "- " << instructor->getName() << " (ID: " << instructor->getID() << ")" << endl;
        }
    }
}

ostream& operator<<(ostream& os, const Notification& notification) {
    os << "Notification ID: " << notification.notificationID << "\n"
        << "Message: " << notification.message << "\n"
        << "Date Sent: " << notification.dateSent << "\n"
        << "Recipients:\n - Students:\n";
    for (const auto& student : notification.students) {
        os << "   " << student->getName() << "\n";
    }
    os << " - Instructors:\n";
    for (const auto& instructor : notification.instructors) {
        os << "   " << instructor->getName() << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Notification& notification) {
    cout << "Enter Notification ID: ";
    getline(is, notification.notificationID);
    cout << "Enter Message: ";
    getline(is, notification.message);
    cout << "Enter Date Sent: ";
    getline(is, notification.dateSent);
    return is;
}
