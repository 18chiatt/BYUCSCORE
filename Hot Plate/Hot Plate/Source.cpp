#include<iostream>
#include<iomanip>
#include <fstream>
using namespace std;
using std::fstream;


const int lengthHeight = 10;

void outputHotPlate(double Temps[lengthHeight][lengthHeight]) {
	for (int row = 0; row < lengthHeight; ++row) {
		for (int column = 0; column < lengthHeight; ++column) {
			cout << std::fixed;
			cout << setprecision(3);
			cout << setw(9) << setprecision(3) << showpoint << Temps[column][row];
			if (column == lengthHeight - 1) {
				cout << endl;
			}
			else {
				cout << ",";
			}
		}

	}


}


/*bool differentArraysInterrogative(double oldArray[lengthHeight][lengthHeight], double newArray[lengthHeight][lengthHeight]) {
	bool isDifference = 0;
	for (int row = 0; row < lengthHeight; ++row) {
		for (int column = 0; column < lengthHeight; ++column) {
			if (((oldArray[row][column] - newArray[row][column]) > .1) || (oldArray[row][column] - newArray[row][column]) < -.1)) {
			isDifference = 1;
			}

		}


	}

	return isDifference;


}
*/

/*double copyTwoDimensionalArray(double originalArray[lengthHeight][lengthHeight], double newArray[lengthHeight][lengthHeight]) {
	for (int row = 0; row < lengthHeight; ++row) {
		for (int column = 0; column < lengthHeight; ++column) {
			newArray[column][row] = originalArray[column][row];
		}

	}
	return newArray;
}*/




int main() {
	ifstream inFS;
	bool isDifference = true;
	ofstream outFS;
	// welcome message
	cout << "Hotplate simulator" << endl << endl;

	

	double originalTemps[lengthHeight][lengthHeight];
	double newTemps[lengthHeight][lengthHeight];

	//initial assigning

	for (int row = 0; row < lengthHeight; ++row) {
		for (int column = 0; column < lengthHeight; ++column) {
			if ((column == 0) || (column == lengthHeight - 1)) {
				originalTemps[column][row] = 0;
			}
			else if ((column != 0) && (column != lengthHeight - 1) && ((row == 0) || (row == lengthHeight - 1))) {
				originalTemps[column][row] = 100;
			}
			else {
				originalTemps[column][row] = 0;
			}


		}


	}
	//output hotplate
	cout << "Printing initial plate..." << endl;
	outputHotPlate(originalTemps);

	// do an iteration






	for (int row = 0; row < lengthHeight; ++row) {
		for (int column = 0; column < lengthHeight; ++column) {
			if ((column == 0) || (column == lengthHeight - 1)) {
				newTemps[column][row] = 0;
			}
			else if ((column != 0) && (column != lengthHeight - 1) && ((row == 0) || (row == lengthHeight - 1))) {
				newTemps[column][row] = 100;
			}
			else {
				// calculate average w/o going out of bounds
				// we actually don't have to worry about going OOB because it only reaches this point if it isn't assigned 100 or 0

				newTemps[column][row] = (originalTemps[column - 1][row] + originalTemps[column + 1][row] + originalTemps[column][row + 1] + originalTemps[column][row - 1]) / 4;

			}

		}
	}// one iteration finished

	cout << endl << "Printing plate after one iteration..." << endl;
	outputHotPlate(newTemps);



	
	while (isDifference== 1) { // iterate
		//copy arrays

		for (int row = 0; row < lengthHeight; ++row) {
			for (int column = 0; column < lengthHeight; ++column) {
				originalTemps[row][column] = newTemps[row][column];
			}
		}
		//finished copying

		for (int row = 0; row < lengthHeight; ++row) {
			for (int column = 0; column < lengthHeight; ++column) {
				if ((column == 0) || (column == lengthHeight - 1)) {
					newTemps[column][row] = 0;
				}
				else if ((column != 0) && (column != lengthHeight - 1) && ((row == 0) || (row == lengthHeight - 1))) {
					newTemps[column][row] = 100;
				}
				else {
					// calculate average w/o going out of bounds
					// we actually don't have to worry about going OOB because it only reaches this point if it isn't assigned 100 or 0

					newTemps[column][row] = (originalTemps[column - 1][row] + originalTemps[column + 1][row] + originalTemps[column][row + 1] + originalTemps[column][row - 1]) / 4;
					//system("Pause");

				}

			}
		}



		







		bool isDifference = 0; //check for difference
		for (int row = 0; row < lengthHeight; ++row) {
			//cout << "WE'RE CHECKING FOR A DIFFERENCE OVER HERE";
			for (int column = 0; column < lengthHeight; ++column) {
				double difference = originalTemps[row][column] - newTemps[row][column];
				if (((originalTemps[row][column] - newTemps[row][column]) > .1) || (originalTemps[row][column] - newTemps[row][column]) < (-.1)) {
				isDifference = 1; //WE FOUND A DIFFERENCE
				
				}
				
				
			}

		}// end check for difference
		if (isDifference == 0) {
			break;
		}

		

		
		
		

		 // cout << "this is an infinite loop" << endl;
		// cout << "we need to loop again is there a difference? " << isDifference <<  endl;
	}
	// program found equilibrium
	
	cout << endl << "Printing final plate..." << endl;
	outputHotPlate(newTemps);
	cout << endl << endl;

	//write to file
	outFS.open("Hotplate.csv");
	// output to Hotplate.csv
	if (!outFS.is_open()) {
		cout << "Could not open file myoutfile.txt." << endl;
		system("Pause");
	}

	for (int row = 0; row < lengthHeight; ++row) {
		for (int column = 0; column < lengthHeight; ++column) {
			outFS << std::fixed;
			outFS << setprecision(3);
			outFS << setw(9) << setprecision(3) << showpoint << newTemps[column][row];
			if (column == lengthHeight - 1) {
				outFS << endl;
			}
			else {
				outFS << ",";
			}
		}

	}
	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl;
	cout << endl;
	outFS.close();

	inFS.open("Inputplate.txt");
	for (int row = 0; row < lengthHeight; ++row) {
		
		
		for (int column = 0; column < lengthHeight; ++column) {
			inFS >> originalTemps[column][row];

		}
		cout << "DOES THIS MATCH?" << endl;
		outputHotPlate(originalTemps);


	}
	for (int i = 0; i < 3; ++i) {
		
		//finished copying

		for (int row = 0; row < lengthHeight; ++row) {
			for (int column = 0; column < lengthHeight; ++column) {
				if ((column == 0) || (column == lengthHeight - 1)) {
					newTemps[column][row] = 0;
				}
				else if ((column != 0) && (column != lengthHeight - 1) && ((row == 0) || (row == lengthHeight - 1))) {
					newTemps[column][row] = 100;
				}
				else {
					// calculate average w/o going out of bounds
					// we actually don't have to worry about going OOB because it only reaches this point if it isn't assigned 100 or 0

					newTemps[column][row] = (originalTemps[column - 1][row] + originalTemps[column + 1][row] + originalTemps[column][row + 1] + originalTemps[column][row - 1]) / 4;
					//system("Pause");

				}

			}
			
		}
		for (int row = 0; row < lengthHeight; ++row) {
			for (int column = 0; column < lengthHeight; ++column) {
				originalTemps[row][column] = newTemps[row][column];
				//cout << "COPIED TO ORIGINAL TEMPS" << endl;
			}
		}
		//cout << "JUST FINISHED ITERATION " << i + 1 << endl;


	}
	cout << "Printing input plate after 3 updates..." << endl;

	outputHotPlate(newTemps);


	
	



	system("Pause");
	return 0;
}
