#pragma once
#ifndef MODULE_H
#define MODULE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Module {
private:
	string moduleTitle;   // Title of the Module
	string moduleID;      // Unique Identifier for Module
	vector<string> contentSection;   // Sections or topics in the module
public:
	// COnstructor
	Module(const string& moduleTitle, const string& moduleID):
		moduleTitle(moduleTitle),moduleID(moduleID){}

	// Setter Methods
	void setModuleTitle(const string& title);
	void setModuleID(const string& Id);
	void setContentSection(const vector<string>& sections);

	// Getter Methods
	string getModuleTitle()const { return moduleTitle; }
	string getModuleID()const { return moduleID; }
	const vector<string>& getContentSection()const { return contentSection; }

	void displayModuleDetails()const;      // Display Module Information
	void saveData();
	void loadData();

	// Destructor
	~Module(){}

	bool operator==(const Module& other) const {
		return moduleID == other.moduleID;
	}
	friend ostream& operator<<(ostream& os, const Module& module);
	friend istream& operator>>(istream& is, Module& module);


};
#endif // !MODULE_H





