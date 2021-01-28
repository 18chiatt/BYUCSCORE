#ifndef CSG_H
#define CSG_H
#include"student.h"
#include"course.h"
#include<string>
#include<sstream>
using namespace std;

class Csg : public Student, public Course {
private:
	string grade;
public:
	Csg(string courseName, int studID, string grade, string name) : Student(studID, name), Course(courseName){
		this->grade = grade;
	}
	string toString() {
		ostringstream out;
		out << courseName << "," << this->getName() << "," << this->grade << endl;
		return out.str();
	}
	

	string stupidToString() {
		ostringstream idWidener;

		idWidener << setw(4) << setfill('0') << studID;
		ostringstream out;
		out << "csg(" << courseName << "," << idWidener.str() << "," << grade << ")";
		return out.str();

	}
	friend ostream& operator<< (ostream& os, Csg& SNAP){
	
		return os << SNAP.stupidToString();
	}

};



#endif // !CSG_H

