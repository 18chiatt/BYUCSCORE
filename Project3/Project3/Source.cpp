#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>  

using namespace std;

class Student {
public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double personName);
	string ToString();
	
private:
	string name;
	double GPA;
};

Student::Student(string initialName, double initialGPA) {
	name = initialName;
	GPA = initialGPA;
}

void Student::SetName(string inputName) {
	name = inputName;
}

void Student::SetGPA(double newGPA) {
	GPA = newGPA;
}

string Student::ToString() {

	ostringstream stringToReturn;
	stringToReturn << name << setprecision(2) << " has a GPA of " << GPA;
	
	string anActualString = stringToReturn.str();
	return anActualString;
}

//Insert the ToString member function here


int main() {
	cout << fixed << setprecision(1);
	vector<Student*> students; // ---------------------------MAIN----------------------
	const string QUIT_OPTION = "quit";
	const string ADD_OPTION = "add";
	const string DROP_OPTION = "drop";
	const string PRINT_OPTION = "print";
	//Insert your code for main here
	while (true) {
		cout << fixed << setprecision(2);
		string tempString = " ";
		cout << "Enter Option: " << endl;
		cin >> tempString;

		if (tempString == QUIT_OPTION) {
			return 0;
		}
		if (tempString == ADD_OPTION) {
			Student* myPtr;
			cout << "Student name: ";
			string studentName = " ";
			cin >> studentName;
			cout << studentName << "'s GPA: ";
			double studentGPA = 0.0;
			cin >> studentGPA;
			myPtr = new Student(studentName, studentGPA);
			students.push_back(myPtr);

		}
		if (tempString == PRINT_OPTION) {
			for (int i = 0; i < students.size(); ++i) {
				string stringToPrint = students.at(i)->ToString();
				cout << i << ": " << stringToPrint << endl;

			}

		}
		if (tempString == DROP_OPTION) {
			cout << "Index of student to drop: ";
			int intToDrop = -1;
			cin >> intToDrop;
			students.erase(students.begin() + intToDrop);

		}


	}

	return 0;
}