#include "Group.h"
#include <iostream>
#include <algorithm> // For removing a member
using namespace std;

// Initialize static members
int Group::nextGroupID = 1;
map<int, vector<Student*>> Group::groups;

// Create a new group and return its ID
int Group::createGroup() {
    int groupID = nextGroupID++;
    groups[groupID] = {}; // Create an empty group with the new group ID
    cout << "Group created with ID: " << groupID << endl;
    return groupID;
}

// Add a student to a specific group
void Group::addMemberFromGroup(int groupID, Student* member) {
    if (groups.find(groupID) != groups.end()) {
        if (member) {
            groups[groupID].push_back(member);
            cout << "Student " << member->getName() << " (ID: " << member->getID() << ") added to Group " << groupID << "." << endl;
        }
        else {
            cout << "Invalid student! Cannot add to the group." << endl;
        }
    }
    else {
        cout << "Group with ID " << groupID << " does not exist!" << endl;
    }
}

// Remove a student from a specific group
void Group::removeMemberFromGroup(int groupID, Student* member) {
    if (groups.find(groupID) != groups.end()) {
        auto& members = groups[groupID];
        auto it = find(members.begin(), members.end(), member); // Find the member in the group
        if (it != members.end()) {
            cout << "Student " << member->getName() << " (ID: " << member->getID() << ") removed from Group " << groupID << "." << endl;
            members.erase(it);
        }
        else {
            cout << "Student is not a member of Group " << groupID << "!" << endl;
        }
    }
    else {
        cout << "Group with ID " << groupID << " does not exist!" << endl;
    }
}

// Display all members in a specific group
void Group::displayGroupMembers(int groupID) {
    if (groups.find(groupID) != groups.end()) {
        cout << "Members of Group " << groupID << ":" << endl;
        for (const auto& member : groups[groupID]) {
            if (member) {
                cout << "- " << member->getName() << " (ID: " << member->getID() << ")" << endl;
            }
        }
    }
    else {
        cout << "Group with ID " << groupID << " does not exist!" << endl;
    }
}

// Simulate a group discussion
void Group::handleDiscussion(int groupID, const string& message) {
    if (groups.find(groupID) != groups.end()) {
        cout << "Discussion in Group " << groupID << ":" << endl;
        cout << "Message: " << message << endl;

        cout << "Participants:" << endl;
        for (const auto& member : groups[groupID]) {
            if (member) {
                cout << "- " << member->getName() << " (ID: " << member->getID() << ")" << endl;
            }
        }
    }
    else {
        cout << "Group with ID " << groupID << " does not exist!" << endl;
    }
}


ostream& operator<<(ostream& os, const Group& group) {
    os << "Group ID: " << group.nextGroupID << "\nMembers:\n";  // Access groupID via the object
    // Access the map 'groups' via the static method
    auto it = Group::groups.find(group.nextGroupID);  // Use the correct groupID
    if (it != Group::groups.end()) {
        for (const auto& student : it->second) {
            os << " - " << student->getName() << "\n";
        }
    }
    else {
        os << "No members found in this group." << endl;
    }
    return os;
}


istream& operator>>(istream& is, Group& group) {
    cout << "Enter Group ID: ";
    is >> group.nextGroupID;  // Assign to group object directly
    is.ignore(); // Ignore trailing newline if any
    return is;
}
