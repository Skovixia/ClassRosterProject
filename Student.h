#pragma once
#include <iostream>
#include<iomanip>
#include "degree.h"

class Student
{
public:
	const static int dayArraySize = 3;
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int remainingDays[dayArraySize];
	DegreeProgram degreeProgram;
public:
	//parameterless constructor that allows for default values to be set
	Student();
	//full constructor 
	Student(std::string student_ID, std::string first_Name, std::string last_Name, std::string email_Address, int age_, int remaining_Days[], DegreeProgram degree_Program);

	//getters/accessors
	std::string getStudentID() { return this->studentID; }
	std::string getFirstName() { return this->firstName; }
	std::string getLastName() { return this->lastName; }
	int getAge() {return this->age;}
	std::string getEmailAddress() { return this->emailAddress; }
	int* getNumOfDays() { return this->remainingDays; }
	DegreeProgram getDegreeProgram() { return this->degreeProgram; }

	//setters/mutators
	//this-> allows the compiler to know which address to set the values to and allows compiler to disambiguate between local variable and method parameters
	void setStudentID(std::string stID) { this->studentID = stID; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
	void setAge(int age) { this->age = age; }
	void setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }
	//setting remaining course days individually 
	void setRemainingDays(int remainingDays[]) {
		for (int i = 0; i < dayArraySize; i++) {
			this->remainingDays[i] = remainingDays[i];
		}
	}

	void print();
	~Student();
};

