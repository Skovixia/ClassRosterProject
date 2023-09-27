#include "Student.h"

//default values if empty constructor is used
Student::Student()
	:studentID{ "" }, firstName{ "" }, lastName{ "" }, emailAddress{""}, age{0} {
	//initializing using constructor initialization list... initializing to empty string
	for (int i = 0; i < dayArraySize; i++) {
		this->remainingDays[i] = 0;
	}

	this->degreeProgram = DegreeProgram::NETWORK;
}

//full constructor using constructor initialization list 
Student::Student(std::string student_ID, std::string first_Name, std::string last_Name, std::string email_Address, int age_, int remaining_Days[], DegreeProgram degree_Program) 
	:studentID{ student_ID }, firstName{ first_Name }, lastName{ last_Name }, emailAddress{email_Address}, age{ age_ }, degreeProgram{ degree_Program } {

	for (int i = 0; i < dayArraySize; i++) {
		this->remainingDays[i] = remaining_Days[i];
	}
}


void Student::print() {
    std::cout << this->getStudentID()<<"\t";
    std::cout <<"First Name: " << this->getFirstName() << "\t";
    std::cout <<"Last Name: " << this->getLastName() << "\t";
    std::cout << "Age: " << this->getAge() << "\t\t";
    std::cout <<"Email Address: " << this->getEmailAddress() << "\t";
    std::cout <<"daysInCourse: { " << this->getNumOfDays()[0] << ", ";
    std::cout << this->getNumOfDays()[1] << ", ";
    std::cout << this->getNumOfDays()[2] << " } ";
    std::cout <<"Degree Program: " << degreeProgramString[this->getDegreeProgram()] << std::endl;
}

//destructor
Student::~Student() {}