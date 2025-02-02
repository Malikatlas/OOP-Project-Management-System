#include <iostream>
#include <vector>
#include "Student.h"
#include "Instructor.h"
#include "Admin.h"
#include "Course.h"
#include "Assesment.h"
#include "Module.h"
#include "Assignment.h"
#include "Certificate.h"
#include "Notification.h"
#include "Group.h"

using namespace std;

// Global Data Storage
vector<Student*> students;
vector<Instructor*> instructors;
vector<Course*> courses;
vector<Assignment*> assignments;
vector<Certificate*> certificates; // Declare globally
Admin admin1("Admin", "ADM-001", "admin@example.com", "ADMIN-001", "Academics", { "Manage Courses", "Issue Certificates" });

void addStudent() {
    string name, id, email;
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student ID: ";
    getline(cin, id);
    cout << "Enter Student Email: ";
    getline(cin, email);

    Student* student = new Student(name, id, email, id, "01-Dec-2024");
    students.push_back(student);
    cout << "Student added successfully.\n";
}

void addInstructor() {
    string name, id, email, empID, department;
    cout << "Enter Instructor Name: ";
    getline(cin, name);
    cout << "Enter Instructor ID: ";
    getline(cin, id);
    cout << "Enter Instructor Email: ";
    getline(cin, email);
    cout << "Enter Employee ID: ";
    getline(cin, empID);
    cout << "Enter Department: ";
    getline(cin, department);

    Instructor* instructor = new Instructor(name, id, email, empID, department);
    instructors.push_back(instructor);
    cout << "Instructor added successfully.\n";
}

void createCourse() {
    string title, code, description;
    cout << "Enter Course Title: ";
    getline(cin, title);
    cout << "Enter Course Code: ";
    getline(cin, code);
    cout << "Enter Course Description: ";
    getline(cin, description);

    Course* course = new Course(title, code, description);
    courses.push_back(course);
    cout << "Course created successfully.\n";
}

void manageCourse() {
    if (courses.empty()) {
        cout << "No courses available.\n";
        return;
    }

    cout << "Courses:\n";
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << i + 1 << ". " << courses[i]->getCourseTitle() << "\n";
    }

    int choice;
    cout << "Select a course to manage (1-" << courses.size() << "): ";
    cin >> choice;
    cin.ignore();

    if (choice < 1 || choice > courses.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    Course* course = courses[choice - 1];
    string moduleTitle, moduleID;

    cout << "Enter Module Title: ";
    getline(cin, moduleTitle);
    cout << "Enter Module ID: ";
    getline(cin, moduleID);

    Module module(moduleTitle, moduleID);
    course->addModule(module);
    cout << "Module added to course successfully.\n";
}

void issueCertificate() {
    if (students.empty() || courses.empty()) {
        cout << "No students or courses available for certification.\n";
        return;
    }

    cout << "Select a student:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". " << students[i]->getName() << "\n";
    }

    int studentChoice;
    cout << "Enter choice (1-" << students.size() << "): ";
    cin >> studentChoice;
    cin.ignore();

    if (studentChoice < 1 || studentChoice > students.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    cout << "Select a course:\n";
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << i + 1 << ". " << courses[i]->getCourseTitle() << "\n";
    }

    int courseChoice;
    cout << "Enter choice (1-" << courses.size() << "): ";
    cin >> courseChoice;
    cin.ignore();

    if (courseChoice < 1 || courseChoice > courses.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    Certificate* cert = new Certificate("CERT-001", "15-Dec-2024", courses[courseChoice - 1]->getCourseTitle(), students[studentChoice - 1], courses[courseChoice - 1]);
    certificates.push_back(cert);
    cout << "Certificate issued successfully.\n";
}

void sendNotification() {
    string message;
    cout << "Enter Notification Message: ";
    getline(cin, message);

    Notification notification("NOTIF-001", message, "01-Dec-2024");
    for (auto* student : students) {
        notification.addStudentRecipent(student);
    }
    for (auto* instructor : instructors) {
        notification.addInstructorRecipent(instructor);
    }

    notification.broadcast();
}

void createGroup() {
    int groupID = Group::createGroup();

    cout << "Select students to add to the group:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". " << students[i]->getName() << "\n";
    }

    int studentChoice;
    cout << "Enter choice (1-" << students.size() << ", 0 to stop): ";
    while (cin >> studentChoice && studentChoice != 0) {
        if (studentChoice < 1 || studentChoice > students.size()) {
            cout << "Invalid choice.\n";
        }
        else {
            Group::addMemberFromGroup(groupID, students[studentChoice - 1]);
        }
        cout << "Enter next choice (1-" << students.size() << ", 0 to stop): ";
    }
    cin.ignore();
    cout << "Group created and members added successfully.\n";
}


// Utility Functions
void displayMainMenu() {
    cout << "\n===== Educational Management System =====\n";
    cout << "1. Admin Menu\n";
    cout << "2. Student Menu\n";
    cout << "3. Instructor Menu\n";
    cout << "4. Exit\n";
    cout << "=========================================\n";
    cout << "Enter your choice: ";
}

void displayAdminMenu() {
    cout << "\n===== Admin Menu =====\n";
    cout << "1. Add Student\n";
    cout << "2. Add Instructor\n";
    cout << "3. Create Course\n";
    cout << "4. Manage Course\n";
    cout << "5. Issue Certificate\n";
    cout << "6. Send Notification\n";
    cout << "7. Create Group\n";
    cout << "8. Back to Main Menu\n";
    cout << "======================\n";
    cout << "Enter your choice: ";
}

void displayStudentMenu() {
    cout << "\n===== Student Menu =====\n";
    cout << "1. Submit Assignment\n";
    cout << "2. Check Progress\n";
    cout << "3. Back to Main Menu\n";
    cout << "========================\n";
    cout << "Enter your choice: ";
}

void displayInstructorMenu() {
    cout << "\n===== Instructor Menu =====\n";
    cout << "1. Create Assignment\n";
    cout << "2. Submit Grades\n";
    cout << "3. Back to Main Menu\n";
    cout << "===========================\n";
    cout << "Enter your choice: ";
}

// Admin Functions
void adminMenu() {
    int choice;
    do {
        displayAdminMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            addInstructor();
            break;
        case 3:
            createCourse();
            break;
        case 4:
            manageCourse();
            break;
        case 5:
            issueCertificate();
            break;
        case 6:
            sendNotification();
            break;
        case 7:
            createGroup();
            break;
        case 8:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);
}

// Student Functions
void submitAssignment() {
    if (assignments.empty()) {
        cout << "No assignments available.\n";
        return;
    }

    cout << "Assignments:\n";
    for (size_t i = 0; i < assignments.size(); ++i) {
        cout << i + 1 << ". " << assignments[i]->getAssignmentDescription() << "\n";
    }

    int assignmentChoice;
    cout << "Select an assignment to submit (1-" << assignments.size() << "): ";
    cin >> assignmentChoice;
    cin.ignore();

    if (assignmentChoice < 1 || assignmentChoice > assignments.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    cout << "Enter your Student ID: ";
    string studentID;
    getline(cin, studentID);

    Student* student = nullptr;
    for (auto* s : students) {
        if (s->getID() == studentID) {
            student = s;
            break;
        }
    }

    if (!student) {
        cout << "Student not found.\n";
        return;
    }

    int score;
    cout << "Enter your score: ";
    cin >> score;
    cin.ignore();

    assignments[assignmentChoice - 1]->submitAssignment(student, score);
}

void checkProgress() {
    cout << "Enter your Student ID: ";
    string studentID;
    getline(cin, studentID);

    Student* student = nullptr;
    for (auto* s : students) {
        if (s->getID() == studentID) {
            student = s;
            break;
        }
    }

    if (!student) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter the course name: ";
    string courseName;
    getline(cin, courseName);

    float progress = student->checkProgress(courseName);
    cout << "Your progress in " << courseName << " is: " << progress << "%\n";
}

void studentMenu() {
    int choice;
    do {
        displayStudentMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            submitAssignment();
            break;
        case 2:
            checkProgress();
            break;
        case 3:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Instructor Functions
void createAssignment() {
    cout << "Enter Assignment ID: ";
    string id;
    getline(cin, id);

    cout << "Enter Assignment Description: ";
    string description;
    getline(cin, description);

    cout << "Enter Maximum Score: ";
    int maxScore;
    cin >> maxScore;
    cin.ignore();

    cout << "Enter Due Date: ";
    string dueDate;
    getline(cin, dueDate);

    Assignment* assignment = new Assignment(id, description, maxScore, dueDate);
    assignments.push_back(assignment);
    cout << "Assignment created successfully.\n";
}


void submitGrades() {
    cout << "Feature to submit grades is under construction.\n";
}

void instructorMenu() {
    int choice;
    do {
        displayInstructorMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            createAssignment();
            break;
        case 2:
            submitGrades();
            break;
        case 3:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Main Function
int main() {
    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            adminMenu();
            break;
        case 2:
            studentMenu();
            break;
        case 3:
            instructorMenu();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
