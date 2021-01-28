#include<iostream>
#include<string>
#include"Quicksort.h"
#include<fstream>
#include<sstream>
#include<stdbool.h>
using namespace std;
//this code is copyrighted by your mom LUL
//


int main(int argc, char* argv[]) {
	

	QuickSort<int> myQuickSort;

	ifstream input(argv[1]);
	string lineToProcess; //wow, lower camel Case variables all around
	ofstream output(argv[2]);

	while (getline(input, lineToProcess)) {
		
		stringstream toProcess(lineToProcess);
		string command;
		toProcess >> command;
		if (command == "QuickSort") {
			myQuickSort.clear();
			output << lineToProcess;
			int newCapacity;
			toProcess >> newCapacity;
			myQuickSort.createArray(newCapacity);
			output << " OK" << endl;

		}

		if (command == "Capacity") {
			output << lineToProcess;
			output << " " << myQuickSort.capacity() << endl;
		}

		if (command == "Clear") {
			output << lineToProcess;
			output << " OK" << endl;
			myQuickSort.clear();

		}

		if (command == "AddToArray") {
			output << command << "  ";
			stringstream tooutput("");
			

			while (true) {
				if (toProcess.eof()) {
					break;
				}
				int toAdd;
				toProcess >> toAdd;
				myQuickSort.addElement(toAdd);
				tooutput << toAdd << ",";

			}
			string toPrint = tooutput.str().substr(0, tooutput.str().length() - 1); //remove trailing comma
			output << toPrint;
			output << " OK" << endl;

		}

		if (command == "Size") {
			output << lineToProcess;
			output << " " << myQuickSort.size() << endl;
		}

		if (command == "PrintArray") {
			output << lineToProcess;
			output << " " << myQuickSort << endl;
		}


		if (command == "MedianOfThree") {
			output << command;
			int startingIndex;
			int endingIndexPlusOne;
			toProcess >> startingIndex;
			toProcess >> endingIndexPlusOne;
			output << " " << startingIndex << "," << endingIndexPlusOne << " = ";

			output << myQuickSort.medianOfThree(startingIndex, endingIndexPlusOne) << endl;
		}
		if (command == "Partition") {
			output << command << " ";
			int leftIndex;
			int rightIndex;
			int pivotIndex;
			
			toProcess >> leftIndex;
			toProcess >> rightIndex;
			toProcess >> pivotIndex;

			output << leftIndex << "," << rightIndex << "," << pivotIndex;
			output << " = " << myQuickSort.partition(leftIndex, rightIndex, pivotIndex) << endl;
		}

		if (command == "SortAll") {
			bool suceeded = myQuickSort.sortAll(); //set suceeded flag or not
			output << command << " ";
			if (suceeded) {
				output << "OK";
			}
			else {
				output << "Error";
			}
			output << endl;
		}

		if (command == "Sort") {
			myQuickSort.resetSwaps(); //from when I tried to do the stats command
			int startingPoint;
			toProcess >> startingPoint;
			int endingPlusOne;
			toProcess >> endingPlusOne;

			myQuickSort.sort(startingPoint, endingPlusOne);
			output << command << " " << startingPoint << "," << endingPlusOne << " OK" << endl;
		}


	}
	


	



	return 0;

}