#include<iostream>
#include<string>
#include"Linked List.h"
#include<fstream>
using namespace std;

string findNthWord(string baseString, int nthWord); //I use this function in almost every program, very very useful
int findWordCount(string baseString); //very useful for finding number of times to call push_front

int main(int argc, char* argv[]) {
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open(argv[2]);

	LinkedList<string> myList; //create the list

	
	cout << findWordCount("hello my name is sam");
	

	while (true) { //infinite loop that I break out of when we reach eof
		string lineToProcess;
		getline(input, lineToProcess);
		string command = findNthWord(lineToProcess, 0);
		output << command;


		if (command == "PrintList") {
			try {
				if (myList.isEmpty() ) {
					string errorMessage = " Empty!";
				}

			}
			catch (string error) {
				output << error;
			}
			//list is not empty

			if (!myList.isEmpty()) {
				//print list
				output << myList;

			}


		}


		if (command == "Insert") {
			//insert elements
			int numWordsToInsert = findWordCount(lineToProcess);
			for (int i = 1; i < numWordsToInsert + 1; i++) {
				string toInsert = findNthWord(lineToProcess, i);
				output << " " <<  toInsert;
				myList.push_front(toInsert);
			}
		}


		if (command == "Clear") {
			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}
			catch (string error) {
				output << error;
			}

			if (!(myList.isEmpty())) {
				myList.clear();
				output << " OK";
			}

		}


		if (command == "Iterate") {			

			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}			
			catch (string error) {
				output << error;
			}			
			if (!(myList.isEmpty())) {
				LinkedList<string>::Iterator iter = myList.begin();

				while (iter != myList.end()) {
					output << endl  << " " << "[" << *iter << "]";
					++iter;
				}
			}

		}


		if (command == "Find") {
			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
				}
			}
			catch (string error) {
				output << error;
			}
			string toFind = findNthWord(lineToProcess, 1);
			output << " " << toFind;
			LinkedList<string>::Iterator iter = myList.find(myList.begin(), myList.end(), toFind);
			if (iter.getHead() == NULL) { //we have the iterator getHead
				output << " Not Found";
			}
			else {
				
				output << " OK";
			}
		}

		if (command == "InsertBefore") {

			string toOutput = findNthWord(lineToProcess, 1);
			output << " " << toOutput;
			toOutput = findNthWord(lineToProcess, 2);
			output << " " << toOutput;
			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
				}
			}
			catch (string error) {
				output << error;
			}

			if (!(myList.isEmpty())) {
				string findValue = findNthWord(lineToProcess, 2);
				string afterValue = findNthWord(lineToProcess, 1);
				LinkedList<string>::Iterator position = myList.find(myList.begin(), myList.end(), findValue);
				if (position.getHead() != NULL) {
					myList.insert(position, afterValue);
					output << " OK";
				}
				else {
					output << " Not Found";
				}

			}
		}

		if (command == "InsertAfter") {
			string toOutput = findNthWord(lineToProcess, 1);
			output << " " << toOutput;
			toOutput = findNthWord(lineToProcess, 2);
			output << " " << toOutput;
			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
				}
			}
			catch (string error) {
				output << error;
			}

			if (!myList.isEmpty()) {
				
				string findValue = findNthWord(lineToProcess, 2);
				string afterValue = findNthWord(lineToProcess, 1);
				LinkedList<string>::Iterator position = myList.find(myList.begin(), myList.end(), findValue);
				if (position.getHead() != NULL) {
					myList.insertAfter(position, afterValue);
					output << " OK";

				}
				else {
					output << " Not Found";
				}

			}

		}


		if (command == "Erase") {
			output << " " << findNthWord(lineToProcess, 1);
			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
				}
			}
			catch (string error) {
				output << error;
			}

			if (!(myList.isEmpty())) {
				string toErase = findNthWord(lineToProcess, 1);
				LinkedList<string>::Iterator iter = myList.find(myList.begin(), myList.end(), toErase);
				if (iter.getHead() == NULL) {
					output << " Not Found";
				}
				else {
					LinkedList<string>::Iterator begin = myList.begin();
					myList.Erase(begin, iter);
					output << " OK";
				}
			
			}

		}


		if (command == "Replace") {
			string toReplace = findNthWord(lineToProcess, 1);
			output << " " << toReplace;
			string toReplaceWith = findNthWord(lineToProcess, 2);
			output << " " << toReplaceWith;

			try {
				if (myList.isEmpty()) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}
			catch (string error) {
				output << error;
			}
			if (!(myList.isEmpty())) {
				myList.replace(myList.begin(), myList.end(), toReplace, toReplaceWith);
				output << " OK";
			}

		}

		if (input.eof()) {
			break;  //exit otherwise infinite loop when we reach EOF
		}
		else {
			output << endl; //output end line to seperate inputs
		}


	}
	
	
	


	if (!myList.isEmpty()) {
		myList.clear(); //clear list to avoid memory Leaks
	}
	return 0;
}


int findWordCount(string baseString) {

	int alreadyFound = 0;
	int mostRecentIndex = 0;
	while (baseString.find(" ", mostRecentIndex) != string::npos) {
		mostRecentIndex = baseString.find(" ", mostRecentIndex + 1);
		alreadyFound++;


	}

	//output << alreadyFound;
	return alreadyFound - 1;

}


string findNthWord(string baseString, int nthWord) {
	int numWords = findWordCount(baseString);

	if (nthWord == 0) {
		int firstSpaceIndex = baseString.find(" ");
		string toReturn = baseString.substr(0, firstSpaceIndex);
		return toReturn;

	}

	int indexBeginning = -1;
	if (nthWord == (numWords)) {
		//output << "FInal word mode";
		for (int i = 0; i < numWords; i++) {
			indexBeginning = baseString.find(" ", indexBeginning + 1);

		}

		string toReturn = baseString.substr(indexBeginning + 1, baseString.length() - indexBeginning);
		return toReturn;



	}
	int currSpaceLocation = -1;

	for (int i = 0; i < nthWord; i++) {
		currSpaceLocation = baseString.find(" ", currSpaceLocation + 1);


	}
	int endSpaceLocation = baseString.find(" ", currSpaceLocation + 1);

	//output << "INdex of begining of nth word is " << currSpaceLocation << " end of nthWord is " << endSpaceLocation;
	int length = endSpaceLocation - 1 - currSpaceLocation;

	string toReturn = baseString.substr(currSpaceLocation + 1, length);
	return toReturn;






}