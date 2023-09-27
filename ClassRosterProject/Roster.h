#pragma once
#include "Student.h"
#include "degree.h"

class Roster
{
private:
	const static int numEntries = 5;
	//not delcared dynamically
	//Student* studentRosterArr[numEntries];
	int finalPos = -1;
public:
	Student* classRosterArray[numEntries]={};
	/*The parse method will search through sets of comma delimited strings within the student data table provided then extracts the data. 
	The data is then passed into the add method which will then create the student object to be stored in the array*/
	void parse(std::string studentData);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, 
		int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	//destructor
	~Roster();
	//will be using default constructor given by cpp
};

