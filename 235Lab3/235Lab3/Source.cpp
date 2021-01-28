#include<string>
#include<iostream>
#include"Linked List Interface.h"
#include"LinkedList.h"
#include<fstream>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //detect memory leaks
#else
#define VS_MEM_CHECK;
#endif

using namespace std;
string findNthWord(string baseString, int nthWord); //I use this function in almost every program, very very useful
int findWordCount(string baseString); //very useful for finding number of times to call push_front




int main(int argc, char* argv[]) {
	VS_MEM_CHECK;
	ofstream output;
	output.open(argv[2]);
	if (argc != 3) {
		output << "Usage is [input file] [output file]"; //let user know how to use file
		return 1;
	}


	


	ifstream input;
	input.open(argv[1]);
	LinkedList<string> * head;
	head = new LinkedList<string>("epicBoi222");

	
	
	
	
	string lineToProcess;

	while (true) {
		getline(input, lineToProcess);
		output << lineToProcess;
		
		string command = findNthWord(lineToProcess, 0);

		if (command == "PrintList") { //print list function

			try { //a similar guard is used in most of the functions, this stops calling a function when it can't return anything
				if (head == nullptr) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}

			catch (string error) {
				output << error;
			}
			
			output << " ";
			output << *head;
		}

		if (command == "Delete") {
			try {
				if (head == nullptr) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}

			catch (string error) {
				output << error;
			}
			if (!(head == nullptr)) {
				head->pop_front();
				output << " OK";
			}
		}

		if (command == "Insert") {
			bool initializedList = false;
			if (head == nullptr) {
				initializedList = true;
				string toInitizlizeWith = findNthWord(lineToProcess, 1);
				head = new LinkedList<string>(toInitizlizeWith);
			}
			int numToInsert = findWordCount(lineToProcess);
			for (int i = 1; i < numToInsert+1; i++) {
				if ((initializedList) && i == 1) {
					continue;
				}
				string toPopFront = findNthWord(lineToProcess, i);
				head->push_front(toPopFront);
				//output << "Insertion";

			}

		}

		if (command == "Clear") {
			output << " ";
			try {
				if (head == nullptr) {
					string errorMessage = "Empty!";
					throw errorMessage;
				}
			}

			catch (string error) {
				output << error;
			}

			head->clear();
			output << "OK";
		}

		if (command == "First") {

			try {
				if (head == nullptr) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}

			catch (string error) {
				output << error;
			}

			if (!(head == nullptr)) {
				
				string toPrint = head->front();
				output << " " << toPrint;
			}
			
		}
		

		if (command == "Reverse") {

			try {
				if (head== nullptr) {
					string errorMessage = " Empty!";
					throw errorMessage;

				}
			}
			catch (string error) {
				output << error;
			}

			if (head == nullptr) {
				head->reverse();
				output << " OK";

			}
		}

		if (command == "Size") {
			output << head->size();
		}

		if (command == "Remove") {
			try {
				if (head == nullptr) {
					string errorMessage = " Empty!";
					throw errorMessage;
				}
			}

			catch (string error) {
				output << error;
			}

			if (!(head == nullptr)) {
				string toDelete = findNthWord(lineToProcess, 1);
				head->remove(toDelete);
			}
		}

		if (command == "Empty") {
			if (head == nullptr) {
				output << " true";
			}
			else {
				output << " false";
			}
		}
		




		if (input.eof()) {
			break;  //exit otherwise infinite loop when we reach EOF
		}
		else {
			output << endl; //output end line to seperate inputs
		}
	}	
	

	
	
	
	
	

	
	

	
	


	head->clear(); //ensure no memory leaks
	delete head; //delete final piece
	return 0;
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
		for (int i = 0; i < numWords ; i++) {
			indexBeginning = baseString.find(" ", indexBeginning + 1);

		}

		string toReturn = baseString.substr(indexBeginning+1, baseString.length() - indexBeginning);
		return toReturn;



	}
	int currSpaceLocation = -1;

	for (int i = 0; i < nthWord; i++) {
		currSpaceLocation = baseString.find(" ", currSpaceLocation + 1);


	}
	int endSpaceLocation = baseString.find(" ", currSpaceLocation + 1);

	//output << "INdex of begining of nth word is " << currSpaceLocation << " end of nthWord is " << endSpaceLocation;
	int length = endSpaceLocation-1 - currSpaceLocation;

	string toReturn = baseString.substr(currSpaceLocation + 1, length);
	return toReturn;
	





}

int findWordCount(string baseString) {
	
	int alreadyFound = 0;
	int mostRecentIndex = 0;
	while (baseString.find(" ", mostRecentIndex) != string::npos) {
		mostRecentIndex = baseString.find(" ", mostRecentIndex+1);
		alreadyFound++;
		

	}

	//output << alreadyFound;
	return alreadyFound-1;

}