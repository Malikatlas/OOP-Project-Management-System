#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;
class Person
{
protected:
	string name;    // Person Name
	string ID;      // Unique Identifier
	string email;   // Person Email Address for Communication
public:
	//Constructor
	Person(const string& n, const string& Id, const string& e):name(n),ID(Id),email(e){}

	// Virtual Destructor
	virtual ~Person(){}

	// Virtual Methods
	virtual void displayInfo()const=0;      // Display Person Information
	virtual string getRole()const = 0;        // Return the Role of the Person
	virtual void sendNotification(const string& message) const = 0;  // send messsage to the person
	virtual void saveData() = 0;
	virtual void loadData() = 0;

	// Getter Methods
	string getName()const { return name; }      // Return name of the person
	string getID() { return ID; }          // Return ID of the person
	string  getEmail() { return email; }   // Return Email of the Person

	friend ostream& operator<<(ostream& os, const Person& person) {
		os << person.getName();  // Output the name of the person
		return os;
	}

};

#endif // !PERSON_H

