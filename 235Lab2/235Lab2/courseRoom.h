#ifndef COURSEROOM_H
#define COURSEROOM_H
#include<string>
#include"course.h"
#include<ostream>
#include<sstream>
using  namespace std;

class Cr : public Course{
private:
	string room;
public:
	Cr(string courseName, string room) : Course(courseName) {
		this->room = room;
	}
	string toString() {
		ostringstream out;
		out << room;
		return out.str();
	}

	string stupidToString() {
		ostringstream out;
		out << "cr(" << courseName << "," << room << ")";
		return out.str();

	}
	string getCourseName() {
		return courseName;

	}

	friend ostream& operator<< (ostream& os, Cr& SNAP)
	{
		return os << SNAP.stupidToString();
	}


};


#endif // !COURSEROOM_H
