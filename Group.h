#pragma once
#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Student.h"
using namespace std;
class Group {
private:
	// Static Attributes
	static int nextGroupID;                   // To auto-generate unique group IDs
	static map<int, vector<Student*>> groups; // Map to store group ID and members
public:
	// Static Methods
	static int createGroup();                 // Create a new Group and return its ID
	static void addMemberFromGroup(int groupID, Student* member);    // Add student to the group
	static void removeMemberFromGroup(int groupID, Student* member); // Remove student from group
	static void displayGroupMembers(int groupID);                    // Display all members in a group
	static void handleDiscussion(int groupID, const string& message); // simulate discussions


	friend ostream& operator<<(ostream& os, const Group& group);
	friend istream& operator>>(istream& is, Group& group);

};
#endif // !GROUP_H
