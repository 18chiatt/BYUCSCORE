#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;

class Course {
protected:
	string courseName;
public:
	Course(string courseName) {
		this->courseName = courseName;
	}
	virtual string getCourseName() {
		return courseName;
	}

};


#endif // !COURSE_H
