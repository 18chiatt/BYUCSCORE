#include<iostream>
#include<string>
#include<ostream>
#include<sstream>
#include<fstream>
#include"BinarySearchTree.h"
#include"Node.h"

using namespace std;



int main(int argc, char* argV[]) {

	if (!(argc > 2)) {
		cerr << " insuffiecient args" << endl; //notify of too low arg count
	}
	BinarySearchTree<int> * intTreePtr = nullptr;
	BinarySearchTree<string>  * stringTreePtr = nullptr; //initialize BST
	string toProcess;
	bool isOnInt = false;

	ifstream input;
	input.open(argV[1]);

	ofstream output;
	output.open(argV[2]);

	bool intMode = false;


	



	

	

	while (getline(input, toProcess)) { //get int commands
		output << toProcess;
		stringstream lineToProcess(toProcess);
		string command;
		lineToProcess >> command;
		

		if (command == "INT") {
			intTreePtr = new BinarySearchTree<int>;
			intMode = true;
			output << " true";
			output << endl;
		}

		if (command == "STRING") {
			stringTreePtr = new BinarySearchTree<string>;
			intMode = false;

			output << " true";
			output << endl;
		}
		
		if (intMode == true) {
			//int commands
			if (command == "add") {
				int toAdd;
				lineToProcess >> toAdd;
				if (intTreePtr->addNode(toAdd) == true) {
					output << " true" << endl;
				}
				else {
					output << " false" << endl;
				}
				continue;
			}

			if (command == "remove") {
				int toRemove;
				lineToProcess >> toRemove;
				if (intTreePtr->removeNode(toRemove) == true) {
					output << " true" << endl;
				}
				else {
					output << " false" << endl;
				}
				continue;
			}

			if (command == "clear") {
				if (intTreePtr->clearTree() == true) {
					output << " true" << endl;
				}
				else {
					output << " false" << endl;
				}
				continue;
			}

			if (command == "size") {
				output << " " << intTreePtr->getNumNodes() << endl;
				continue;
			}

			if (command == "print") {
				output << ":";
				if (intTreePtr->getNumNodes() != 0) {
					output << intTreePtr->getThis() ;

					output << endl;
					continue;
				}
				output << " empty" << endl;
				continue;
				
			}

			if (command == "find") {
				int toFind;
				lineToProcess >> toFind;

				if (intTreePtr->findNode(toFind) == true) {
					output << " found" << endl;
				}
				else {
					output << " not found" << endl;
				}
				continue;
			}


		}
		
		if (intMode == false) {
			//string commands
			if (command == "add") {
				string toAdd;
				lineToProcess >> toAdd;
				if (stringTreePtr->addNode(toAdd) == true) {
					output << " true" << endl;
				}
				else {
					output << " false" << endl;
				}
				continue;
			}

			if (command == "remove") {
				string toRemove;
				lineToProcess >> toRemove;
				if (stringTreePtr->removeNode(toRemove) == true) {
					output << " true" << endl;
				}
				else {
					output << " false" << endl;
				}
				continue;
			}

			if (command == "clear") {
				if (stringTreePtr->clearTree() == true) {
					output << " true" << endl;
				}
				
				continue;
			}

			if (command == "size") {
				output << " " << stringTreePtr->getNumNodes() << endl;
				continue;
			}

			if (command == "print") {
				output << ":";
				if (stringTreePtr->getNumNodes() != 0) {
					output << stringTreePtr->getThis() ;

					output << endl;
					continue;
				}
				output << " empty" << endl;
				continue;

			}

			if (command == "find") {
				string toFind;
				lineToProcess >> toFind;

				if (stringTreePtr->findNode(toFind) == true) {
					output << " found" << endl;
				}
				else {
					output << " not found" << endl;
				}
				continue;
			}


		}

		
		
	} 



	

	

	

	//is no longer on int, now do string

	if (intTreePtr != nullptr) {
		delete intTreePtr;


	}

	if (stringTreePtr != nullptr) {
		delete stringTreePtr;
	}

	return 0;
}