#include <iostream>
#include<string>
#include<fstream>
#include<ostream>
#include<sstream>
#include<iomanip>
using namespace std;

char getGradeLetter(double studentScore, double averageScore);
int findInstancesof(string baseString, char charToSearchFor);


int main(int argC, char* argV[]) {


	fstream inputFile;
	ofstream output;
	output.open(argV[2]);

	inputFile.open(argV[1]);

	string initialValues;

	getline(inputFile, initialValues);
	//file is opened, firstStr has initial values in str
	stringstream firstInput(initialValues);
	int indexOfSpace = 0;
	for (int i = 0; i < initialValues.length(); i++) {
		if (initialValues.at(i) == ' ') indexOfSpace = i;

	}

	//from 0 to indexOfSpace-1 is the number of students, from indexofSpace+1 to end is number of grades

	string stringNumStudents = initialValues.substr(0, indexOfSpace);
	string stringNumGrades = initialValues.substr(indexOfSpace + 1, initialValues.length() - 1);

	stringstream streamNumStudents(stringNumStudents);
	stringstream streamNumGrades(stringNumGrades);
	int numStudents = 0;
	int numGrades = 0;
	streamNumStudents >> numStudents;

	streamNumGrades >> numGrades;


	





	//output << numStudents << " is the num students ==6?" << endl << numGrades << " is the num grades ==8?" << endl;

	//numStudents has number of students, numGrades has number of grades, now dynamic array for names

	string* studentNames = new string[numStudents];
	string* letterGrades = new string[numGrades];
	double* studentAverages = new double[numStudents];
	for (int i = 0; i < numGrades; i++) {
		letterGrades[i] = "";

	}

	//create two dimensional dynamic array for grades
	double** scores = new double*[numStudents];
	for (int i = 0; i < numStudents; i++) {
		scores[i] = new double[numGrades];

	}
	// main loop for storing inputs




	for (int i = 0; i < numStudents; i++) {
		string line;
		stringstream input;
		getline(inputFile, line);

		input << line;

		string firstName, lastName;

		input >> firstName >> lastName;

		string fullName = firstName + " " + lastName;
		studentNames[i] = fullName;

		//output << studentNames[i] << endl;
		// names are stored

		for (int j = 0; j < numGrades; j++) {
			string gradeToStore;
			input >> gradeToStore;
			double currentGrade = stod(gradeToStore);
			scores[i][j] = currentGrade;

		}






	}


	//finished with input, begin output/processing

	output << "Student Scores:" << endl;

	for (int i = 0; i < numStudents; i++) {
		output << setw(20) << studentNames[i];
		for (int j = 0; j < numGrades; j++) {
			output << setw(7) << scores[i][j];
			//if (j != numGrades - 1) {
			//	output << " ";
			//}

		}
		output << endl;

	}


	double* averageScores = new double[numGrades];
	output << "Exam Averages:" << endl;
	for (int i = 0; i < numGrades; i++) {
		double runningTotal = 0;

		for (int j = 0; j < numStudents; j++) {
			runningTotal = runningTotal + scores[j][i];

		}
		output << "    Exam " << i + 1 << " Average =";
		double average = runningTotal / numStudents;
		output << setw(7) << fixed << setprecision(1) << average << endl;
		averageScores[i] = average;


	} //output average scores

	//output students and their grades
	output << "Student Exam Grades:" << endl;
	for (int i = 0; i < numStudents; i++) {
		output << setw(20) << studentNames[i];

		for (int j = 0; j < numGrades; j++) {
			//find grade
			char studentsLetterGrade = getGradeLetter(scores[i][j], averageScores[j]);
			letterGrades[j].push_back(studentsLetterGrade);
			output << setw(9) << setprecision(0) << scores[i][j] << "(" << studentsLetterGrade << ")";



			//output

		}
		output << endl;


	}






	output << "Exam Grades:" << endl;

	for (int i = 0; i < numGrades; i++) {
		output << setw(8) << "Exam";
		output << setw(3) << i+1;

		int numA = findInstancesof(letterGrades[i], 'A');
		int numB = findInstancesof(letterGrades[i], 'B');
		int numC = findInstancesof(letterGrades[i], 'C');
		int numD = findInstancesof(letterGrades[i], 'D');
		int numE = findInstancesof(letterGrades[i], 'E');

		output << setw(8) << numA << "(A)";
		output << setw(8) << numB << "(B)";
		output << setw(8) << numC << "(C)";
		output << setw(8) << numD << "(D)";
		output << setw(8) << numE << "(E)";
		output << endl;



	}


	output << "Student Final Grades:" << endl;

	//find student average
	for (int i = 0; i < numStudents; i++) {
		double runningTotal = 0;
		for (int j = 0; j < numGrades; j++) {
			runningTotal = runningTotal + scores[i][j];


		}
		double studentAverage = runningTotal / numGrades;
		studentAverages[i] = studentAverage;
	}





	// find class average



	double runningAverage = 0;
	for (int i = 0; i < numStudents; i++) {
		runningAverage = runningAverage + studentAverages[i];

	}
	double overallAverage = runningAverage / numStudents;

	for (int i = 0; i < numStudents; i++) {

		output << setw(20) << studentNames[i];
		// width is 9
		output << setw(9) << fixed << setprecision(1) << studentAverages[i] << "(" << getGradeLetter(studentAverages[i], overallAverage) << ")";
		output << endl;



	}


	output << "Class Average Score = " << fixed << setprecision(1) << overallAverage;




	delete[] studentNames;
	for (int i = 0; i < numStudents; i++) {
		delete[] scores[i];


	}
	delete[] scores;
	delete[] studentAverages;
	delete[] letterGrades;
	delete[] averageScores;
	return 0;
}



char getGradeLetter(double studentScore, double averageScore) {

	double difference = studentScore - averageScore;

	if (difference >= 14.999) {
		return 'A';
	}
	if (difference >= 5.001) {
		return 'B';

	}
	if (difference >= -5.0001) return 'C';
	if (difference >= -15.0001) return 'D';
	return 'E';

}

int findInstancesof(string baseString, char charToSearchFor) {
	int instancesFound = 0;
	for (int i = 0; i < baseString.length(); i++) {
		if (baseString.at(i) == charToSearchFor) { instancesFound++; }


	}
	return instancesFound;
}


