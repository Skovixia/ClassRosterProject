#include <iostream>
#include "Roster.h"
using namespace std;

/*
* Sarah Kouhail
* Scripting and Programming - Applications - C867 submission
*/

int main() {

	cout << "Course Title: Scripting and Programming - Applications - C867\nName: Sarah Kouhail" << endl;

	const string studentData[] = 
		{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Sarah,Kouhail,skouhai@wgu.edu	,22, 28, 30, 30,SOFTWARE"};

	const int numStudents = 5;

	//using default constructor provided by c++
	Roster classRoster;

	//parsing all the data
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << "\nDisplaying all student data: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Displaying invalid Emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Displaying average course completion days: " << endl;
	for (auto &i: classRoster.classRosterArray ) {
		classRoster.printAverageDaysInCourse(i->getStudentID());
	}
	cout << endl;

	
	cout << "Displaying by degree program: SOFTWARE:" << endl;
		classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);//casting integer to DegreeProgram
		cout << endl;



	cout << "Removing student: " << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();


	cout << "\nRemoving student: " << endl;
	classRoster.remove("A3");

	cout << "Please hit any key to view destructor details" << endl;

	system("pause");


	return 0;
}