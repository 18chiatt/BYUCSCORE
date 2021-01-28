#ifndef CDH_H
#define CDH_H
#include"course.h"
#include<string>
using namespace std;

class Cdh : public Course{
private:
	string day;
	string time;
public:
	Cdh(string courseName, string day, string time) : Course(courseName) {
		this->day = day;
		this->time = time;
	}
	void addDay(string day) {
		this->day.append(day);
	}
	string toString() {
		ostringstream out;
		out <<  day << " " << time;
		return out.str();

	}
	string stupidToString() {
		ostringstream out;
		out << "cdh(" << courseName << "," << day << "," << time << ")";
		return out.str();

	}

	friend ostream& operator<< (ostream& os, Cdh& SNAP){
	
		return os << SNAP.stupidToString();
	}

};




#endif // !CDH_H
