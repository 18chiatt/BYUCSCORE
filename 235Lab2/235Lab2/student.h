#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;

class Student {
protected: 
	int studID;
	string studName;

public:
	const int getID() { return studID; }
	void setID(int id) { this->studID = id; }
	Student(int studentID, string studName) : studID(studentID), studName(studName) {}
	string getName() { return studName; }
};





#endif // !STUDENT_H

