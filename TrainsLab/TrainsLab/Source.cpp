#include "DequeInterface.h"
#include "Deque.h"
#include"Vector.h"
#include"Stack.h"
#include"Queue.h"
#include"TrainStation.h"
#include <iostream>
#include<fstream>
#include<string>
#include <assert.h> 
using namespace std;
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif



int main(int argc, char * argv[]) {
	VS_MEM_CHECK
	TrainStation myStation;
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open(argv[2]);
	string toParse = "";

	while (getline(input, toParse)) {
		//parse input
		
		stringstream currInput(toParse);
		string command;
		currInput >> command;
		output << toParse;
		if (command == "Add:station") {
			unsigned int toAdd;
			currInput >> toAdd;
			output << " " << myStation.addToStationTurntable(toAdd);
		}

		if (command == "Add:queue") {
			output << " " << myStation.addToQueue();
		}
		
		if (command == "Add:stack") {
			output << " " << myStation.addToStack();
		}


		if (command == "Remove:queue") {
			output << " " << myStation.removeFromQueue();
		}

		if (command == "Remove:station") {
			output << " " << myStation.RemoveFromTurntable();
		}

		if (command == "Remove:stack") {
			output << " " << myStation.removeFromStack();
		}

		if (command == "Top:station") {
			output << " " << myStation.topOfTurntable();
		}

		if (command == "Top:queue") {
			output << " " << myStation.topOfQueue();
		}

		if (command == "Top:stack") {
			output << " " << myStation.topOfStack();
		}

		if (command == "Size:queue") {
			output << " " << myStation.sizeOfQueue();
		}

		if (command == "Size:stack") {
			output << " " << myStation.sizeOfStack();
		}

		if (command == "Train:") {
			output << " " << myStation.outputVector();
			
		}
		if (toParse == "") {
			continue;
		}

		if (command.at(0) == 'F' && command.at(1) == 'i') {
			//find case
			//locate index of :

			int indexOfEndingOfCommand = command.find(':');
			int remainingLength = command.size() - indexOfEndingOfCommand;

			unsigned int toFind = stoi(command.substr(indexOfEndingOfCommand + 1, remainingLength));
			output << " " << myStation.find(toFind);
		}



		
		
		
		output << endl;
	}

	
	

	
	return 0;
}