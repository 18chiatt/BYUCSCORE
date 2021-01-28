#ifndef SNAP_H
#define SNAP_H
#include"student.h"
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

class SNAP : public Student
{
private:
	string name;
	string address;
	string phoneNumber;


public:
	SNAP(int studentID, string name, string address, string phoneNumber) : Student(studentID,name) {
		//this->setID(studentID);
		this->name = name;
		this->address = address;
		this->phoneNumber = phoneNumber;
	}
	string getName() { return name; }
	string getAddress() { return address; }
	string getPhoneNumber() { return phoneNumber; }
	string toString() const {
		//Charlie Brown, 12345, Manager, 555-1234
		ostringstream idWidener;
		idWidener << setw(4) << setfill('0') << studID;
		ostringstream out;
		out << name << ", " << idWidener.str() << ", " << address << ", " << phoneNumber;
		return out.str();
	}
	string stupidToString() {
		ostringstream studIDBoost;
		studIDBoost << setw(4) << setfill('0') << studID;
		ostringstream out;
		out << "snap(" << studIDBoost.str() << "," << studName << "," << address << "," << phoneNumber << ")";
		return out.str();

	}

	friend ostream& operator<< (ostream& os, SNAP& SNAP){
	
		return os << SNAP.stupidToString();
	}
};



#endif // !SNAP_H

