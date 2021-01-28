#include<iostream>
#include<vector>
#include<fstream>
#include<ostream>
#include"student.h"
#include"SNAP.h"
#include"course.h"
#include"Csg.h"
#include"CourseDayHour.h"
#include"courseRoom.h"
#include<deque>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
using namespace std;
string getStudentName(vector<int> studIDs, vector<string> studNames, int idToLookup);
string getCommand(string toSearch);
int getArgCount(string command, ofstream & toThrowTo);
string getNthArg(string toSearch, int nthArg);
int whichCourseDayHourIsthis(vector<Cdh> toScan, string courseName);
vector<string> findClasses(vector<Csg> grades, string name);
string findClassTime(vector<Cdh> ClassTimesToSearch, string courseName);
string findClassRoom(vector<Cr> classRoomsToSearch, string courseName);

int main(int argC, char* argV[]) {
	VS_MEM_CHECK
	vector<int> studIDLookup;
	vector<string> studNameLookup;
	vector<string> inputs;
	vector<string> verifiedInputs;
	vector<string> commandsVector;
	vector<int> argCounts;
	vector<SNAP> students;
	vector<Csg> grades;
	vector<Cdh> classTimes;
	vector<Cdh> stupidClassTimes;
	vector<Cr> classRooms;
	vector<string> sortedStrings;

	ifstream input(argV[1]);
	ofstream output(argV[2]);

	while (!input.eof()) {
		string toStore;
		getline(input, toStore);
		inputs.push_back(toStore);
	}

	

	//output << "Is this even updating?;";




	output << "Input Strings:\n";
	for (int i = 0; i < inputs.size(); i++) {
		//print out strings and error check
		string command = getCommand(inputs.at(i));
		int argsToGet = getArgCount(command, output);
		output << inputs.at(i) << endl;

		if (argsToGet !=-1) {
			//input is valid
			verifiedInputs.push_back(inputs.at(i));
			commandsVector.push_back(command);
			argCounts.push_back(argsToGet);


		}
		
	}

	vector<int> notYetProcessableGrades;

	
	

	//output << endl << verifiedInputs.at(6) << "should have " << argCounts.at(6) << " arguments";
	
	
	//create all objects

	for (int i = 0; i < verifiedInputs.size(); i++) {
		vector<string> args;
		for (int j = 0; j < argCounts.at(i); j++) {
			string theArg;
			//output << j << endl;
			theArg = getNthArg(verifiedInputs.at(i), j);
			args.push_back(theArg);

		}
		if (commandsVector.at(i) == "snap") {
			int studentNumber = stoi(args.at(0));
			SNAP epic(studentNumber, args.at(1), args.at(2), args.at(3));
			students.push_back(epic);
			studIDLookup.push_back(studentNumber);
			studNameLookup.push_back(args.at(1));
		}
		if (commandsVector.at(i) == "csg") {
			notYetProcessableGrades.push_back(i);
		}
		
		if (commandsVector.at(i) == "cdh") {
			//create a cdh
			//get all inputs
			// check if a cdh already exists with same class name
			// add day if it does
			string potentialCourseName = args.at(0);
			int ShouldIStay = whichCourseDayHourIsthis(classTimes, potentialCourseName);
			if (ShouldIStay == -1) {
				//create a new cdh object and push back
				Cdh epic(args.at(0), args.at(1), args.at(2));
				classTimes.push_back(epic);
				stupidClassTimes.push_back(epic);
			}
			else {
				//append existing cdh and create a stupidcdh for vector output purposes
				classTimes.at(ShouldIStay).addDay(args.at(1));
				Cdh epic(args.at(0), args.at(1), args.at(2));
				stupidClassTimes.push_back(epic);



			
			}


		}

		if (commandsVector.at(i) == "cr") {
			//create a class/room
			Cr  epic (args.at(0), args.at(1));
			classRooms.push_back(epic);


		}
	} 
	//process grades now that we know the students

	

	for (int k = 0; k < notYetProcessableGrades.size(); k++) {
		int i = notYetProcessableGrades.at(k);
		vector<string> args;
		for (int j = 0; j < argCounts.at(i); j++) {
			string theArg;
			//output << j << endl;
			theArg = getNthArg(verifiedInputs.at(i), j);
			args.push_back(theArg);

		}
		int studentNumber = stoi(args.at(1));
		string currentStudentsName;
		currentStudentsName = getStudentName(studIDLookup, studNameLookup, studentNumber);
		Csg epic(args.at(0), studentNumber, args.at(2), currentStudentsName);
		grades.push_back(epic);

	}




	//output << stupidClassTimes.size();

	output << endl << "Vectors:" << endl;
	for (int i = 0; i < students.size(); i++) {
		output << students.at(i) << endl;
	}

	for (int i = 0; i < grades.size(); i++) {
		output << grades.at(i) << endl;
	}

	for (int i = 0; i < stupidClassTimes.size(); i++) {
		output << stupidClassTimes.at(i) << endl;
	}

	for (int i = 0; i < classRooms.size(); i++) {
		output << classRooms.at(i) << endl;
	}

	
	//output << students.at(0);

	//----- vectors output, now output grades.

	output << endl << "Course Grades:" << endl;
	string previousClass = grades.at(0).getCourseName();
	for (int i = 0; i < grades.size(); i++) {
		if (previousClass == grades.at(i).getCourseName()) {

		}
		else {
			output << endl;
			previousClass = grades.at(i).getCourseName();
		}

		output << grades.at(i).toString();

	}

	//grades complete, now output schedules.
	output << endl;

	output << "Student Schedules:" << endl;


	for (int i = 0; i < students.size(); i++) {

		output << students.at(i).toString();
		output << endl;

		vector<string>  studentClasses = findClasses(grades, students.at(i).getName());

		for(int k =0; k<studentClasses.size(); k++){
			output << "  ";
			output << studentClasses.at(k);
			output << " ";
			output << findClassTime(classTimes, studentClasses.at(k));
			output << ", ";
			output << findClassRoom(classRooms, studentClasses.at(k));
			
			if (k == studentClasses.size() - 1) {

			}
			else {
				output << endl;
			}
			
			
			
			
		
		}
		if (i == students.size() - 1) {

		}
		else {
			output << endl;
			output << endl;
		}



	
	}

	

	
	

	
	
	

	//when we output grades, store the previously output class name and compare to see if we need a new line
	//when we go to output schedules, find enrollment of students based on grades
	// for each student, create a vector of class Times by searching class Times for a class with the 
	//same name as they have a grade for.
	//then output the classTime for that class.


} // ----------------------------------------------------------------------------


string getStudentName(vector<int> studIDs, vector<string> studNames, int idToLookup) {
	int index = -4;
	for (int i = 0; i < studIDs.size(); i++) {
		if (studIDs.at(i) == idToLookup) {
			index = i;
		}
	}
	string studentName = studNames.at(index);
	return studentName;
}

string getCommand(string toSearch){

	int endOfCommand = toSearch.find('(');
	string toReturn = toSearch.substr(0, endOfCommand);
	return toReturn;
}

int getArgCount(string command, ofstream& toThrowTo){

	try {
		if (command == "snap") {
			
			return 4;
		}
		if (command == "csg") {
			
			return 3;
		}
		if (command == "cdh") {
			
			return 3;
		}
		if (command == "cr") {
			
			return 2;
		}
		
		throw "**Error: ";
		

		
		

	}
	catch (...) {
		toThrowTo << "**Error: ";
		return -1;
		
	}
	
}

string getNthArg(string toSearch, int nthArg){
	toSearch.append(",,,,,,,,,,,,");
	//find location of the initial (
	vector<int> commaLocations;
	int locationOfBegining = toSearch.find('(');
	int locationOfEnd = toSearch.find(')');
	int locationOfSearch = locationOfBegining;


	while (locationOfSearch != locationOfEnd) {
		if (toSearch.at(locationOfSearch) == ',') {
			commaLocations.push_back(locationOfSearch);
		}
		locationOfSearch++;


	}
	//testing
	int numComas = commaLocations.size();
	if (nthArg == 0) {
		int length = commaLocations.at(0) - locationOfBegining-1;
		string toReturn = toSearch.substr(locationOfBegining+1, length);
		//output << endl << toReturn << endl;
		return toReturn;
	}
	if (nthArg == numComas) {
		int length = locationOfEnd - commaLocations.at(numComas - 1)-1;
		string toReturn = toSearch.substr(commaLocations.at(numComas - 1)+1, length);
		//output << endl << toReturn << endl;
		return toReturn;
	} 
	int length = commaLocations.at(nthArg) - commaLocations.at(nthArg - 1)-1;
	string toReturn = toSearch.substr(commaLocations.at(nthArg - 1)+1, length);
	//output << endl << toReturn << endl;
	return toReturn;
	




	
}

int whichCourseDayHourIsthis(vector<Cdh> toScan, string courseName){
	int index = -1;
	for (int i = 0; i < toScan.size(); i++) {
		if (toScan.at(i).getCourseName() == courseName){
			index = i;
		}
	}


	return index;
}

vector<string> findClasses(vector<Csg> grades, string name){
	vector<string> foundClasses;

	for (int i = 0; i < grades.size(); i++) {
		if (grades.at(i).getName() == name) {
			foundClasses.push_back(grades.at(i).getCourseName());
			//output << "Found a class";
		}

	}
	
	return foundClasses;



}

string findClassTime(vector<Cdh> ClassTimesToSearch, string courseName){
	for (int i = 0; i < ClassTimesToSearch.size(); i++) {
		if (ClassTimesToSearch.at(i).getCourseName() == courseName) {
			return ClassTimesToSearch.at(i).toString();

		}

	}


	
}

string findClassRoom(vector<Cr> classRoomsToSearch, string courseName){
	//output << "Searching for :\"" << courseName << "\" " << endl;
	for (int i = 0; i < classRoomsToSearch.size(); i++) {
		//output << "--- " << endl;
		//output << classRoomsToSearch.at(i).getCourseName() << endl;
		//output << "--- " << endl;
		if (classRoomsToSearch.at(i).getCourseName() == courseName) {
			return classRoomsToSearch.at(i).toString();

		}


	}
	return "We failed";

}

