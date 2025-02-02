#include "Module.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Setter for Module Title
void Module::setModuleTitle(const string& title) {
    moduleTitle = title;
}

// Setter for Module ID
void Module::setModuleID(const string& Id) {
    moduleID = Id;
}

// Setter for Content Sections
void Module::setContentSection(const vector<string>& sections) {
    contentSection = sections;
}

// Display Module Information
void Module::displayModuleDetails()const {
    cout << "Module Title: " << moduleTitle << endl;
    cout << "Module ID: " << moduleID << endl;
    cout << "Content Sections: " << endl;

    for (const auto& section : contentSection) {
        cout << "- " << section << endl;
    }
}

void Module::saveData() {
    std::ofstream outputFile("module_" + this->getModuleTitle()  + "_output.txt");

    if (outputFile.is_open()) {
        outputFile << "Module Title:" << this->getModuleTitle() << std::endl;
        outputFile << "Module ID:" << this->getModuleID() << std::endl;

        vector<string> contentSection = this->getContentSection();

        outputFile << "Content Section:";
        for (int i = 0; i < contentSection.size(); i++) {
            outputFile << contentSection[i] << ",";
        }
        outputFile << std::endl;
        outputFile.close();

        std::cout << "Saved Module " << this->getModuleTitle() << " Data To File" << std::endl;
    }
}

void Module::loadData() {
    std::ifstream inputFile("module_" + this->getModuleTitle() + "_output.txt");

    std::cout << "Data For Module " << this->getModuleTitle() << std::endl;
    std::cout << "===========================\n";

    if (inputFile.is_open()) {
        // Current Line
        std::string currLine;

        // Read File Line By Line
        while (std::getline(inputFile, currLine)) {
            std::cout << currLine << std::endl;
        }

        inputFile.close();
        std::cout << endl;
    }
}

ostream& operator<<(ostream& os, const Module& module) {
    os << "Module ID: " << module.moduleID << "\n"
        << "Title: " << module.moduleTitle << "\n"
        << "Content Sections:\n";
    for (const auto& section : module.contentSection) {
        os << " - " << section << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Module& module) {
    cout << "Enter Module ID: ";
    getline(is, module.moduleID);
    cout << "Enter Module Title: ";
    getline(is, module.moduleTitle);

    module.contentSection.clear();
    cout << "Enter Content Sections (comma-separated): ";
    string line;
    getline(is, line);
    stringstream ss(line);
    string section;
    while (getline(ss, section, ',')) {
        module.contentSection.push_back(section);
    }
    return is;
}
