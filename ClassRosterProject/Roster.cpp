#include "Roster.h"
#include<iomanip>


void Roster::parse(std::string studentData){
	size_t pos = studentData.find(","); //calling function to find the commas in the input
	//extracting substring from begining to position of comma then storing it in variable created
	std::string stID = studentData.substr(0, pos); //studentID

	size_t pos2 = pos + 1;//moving past comma
	pos = studentData.find(",", pos2);
	std::string fName = studentData.substr(pos2, pos - pos2); //firstName

	pos2 = pos + 1; 
	pos = studentData.find(",", pos2);
	std::string lName = studentData.substr(pos2, pos - pos2); //lastName

	pos2 = pos + 1;
	pos = studentData.find(",", pos2);
	std::string email = studentData.substr(pos2, pos - pos2); //email


	pos2 = pos + 1; 
	pos = studentData.find(",", pos2);
	int age1 = stoi(studentData.substr(pos2, pos - pos2)); //age converted to int from string

	pos2 = pos + 1;
	pos = studentData.find(",", pos2);
	int course1 = stoi(studentData.substr(pos2, pos - pos2)); //remaining days of course1

	pos2 = pos + 1;
	pos = studentData.find(",", pos2);
	int course2 = stoi(studentData.substr(pos2, pos - pos2)); //remaining days of course 2

	pos2 = pos + 1;
	pos = studentData.find(",", pos2);
	int course3 = stoi(studentData.substr(pos2, pos - pos2)); //remaining days of course 3

	/*cout << "==================================================================" << std::endl;
	cout << "pos2: " << studentData.at(pos) << ", pos2+1: " << studentData.at(pos2) << std::endl;
	cout << "==================================================================" << std::endl;*/

	pos2 = pos + 1;
	pos = studentData.find(",", pos2);

	/*pos2 = pos + 1;
	pos = studentData.find(",", pos2);*/

	DegreeProgram degree = NETWORK; //default value
	if (studentData.at(pos2) == 'S' && studentData.at(pos2 + 1) == 'O') {
		degree = SOFTWARE;
	}
	else if (studentData.at(pos2) == 'S' && studentData.at(pos2 + 1) == 'E') {
		degree = SECURITY;
	}

	//course days separate for now... calling add function which will allow student data to be stored in array
	add(stID, fName, lName, email, age1, course1, course2, course3, degree);
}


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
	
	//put course days into and array to pass an array to constructor
	int remDaysArr[3] = { daysInCourse1, daysInCourse2, daysInCourse3};
	//making the new student object dynamically
	classRosterArray[++finalPos] = new Student(studentID, firstName, lastName, emailAddress, age, remDaysArr, degreeProgram);
	//****REMINDER that the last index begins at -1, use PREincrement
	//using full constructor
}


void Roster::remove(std::string studentID){

	bool found = false;
	for (int i = 0; i <= Roster::finalPos; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;//stopping exception from being thrown
		}
		//if the i-th element == studentID, setting that element to nullptr
		if (classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			found = true;
		}
	}
	if (found) {
		std::cout << studentID << " has been removed from the class roster." << std::endl << std::endl;
	}
	else {
		std::cout << studentID << " was not found in the class roster." << std::endl << std::endl;
	}
}

//calls the print() method from Student class for each student
void Roster::printAll(){
	for (int i = 0; i <= Roster::finalPos; i++) {
		if (classRosterArray[i] != nullptr) {
			//for each element of classRosterArray as long as it is not a nullptr
			classRosterArray[i]->print();
		}
	}

}
void Roster::printAverageDaysInCourse(std::string studentID){
	
	for (int i = 0; i < Roster::finalPos+1; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			//allowing for only one digit after decimal 
			std::cout << std::fixed << std::setprecision(1);
			std::cout << classRosterArray[i]->getStudentID() << ": ";
			double avg = (classRosterArray[i]->getNumOfDays()[0] + classRosterArray[i]->getNumOfDays()[1] + classRosterArray[i]->getNumOfDays()[2]) / 3.0;
			std::cout << avg << std::endl;
		}
	}
	
}
//valid email should have ('@') and ('.') and no (' ').
void Roster::printInvalidEmails(){
	bool found = false;
	for (int i = 0; i <= Roster::finalPos; i++) {
		std::string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == std::string::npos || (email.find('.') == std::string::npos || email.find(" ") != std::string::npos)) {
			found = true;
			std::cout << classRosterArray[i]->getStudentID()<<" " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ": "<<email<< std::endl;
		}
	}
	if (!found) {
		std::cout << "There are no invalid Emails." << std::endl;
	}
}

//DegreeProgram is passed in
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
	//looping through all elements that include the degree passed in
	for (int i = 0; i <= Roster::finalPos; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	std::cout << std::endl;
}
//destructor
Roster::~Roster(){
	std::cout << "Destructor called." << std::endl;
	for (int i = 0; i < numEntries; i++) {
		if (classRosterArray[i] == nullptr) {
			std::cout << "Destroying student data for: nullptr" << std::endl;
		} else {
			std::cout << "Destroying student data for: " << classRosterArray[i]->getStudentID() << std::endl;
		}
		//deallocating/freeing up memory
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
		//since array is just like a ptr, we need to null it out once project is done to avoid memory leaks
		//not nulling it will cause issues if user attempts to dereference addresses in array in the future
	}
}