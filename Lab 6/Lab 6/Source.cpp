	#include<iostream>
	#include<string>
	#include<iomanip>
	#include <limits>
	using namespace std;




	double ComputeWinnings(int slotNum);
	double SingleChipFall(int initialSlot, bool wantOutput = true);
	int GetUserInt(string prompt, string errorMessage, int min = 0, int max = 900000000);





	const int SINGLE_SLOT = 1;
	const int MULTI_SLOT = 2;
	const int OPTIONS_MENU = 4;
	const int QUITTER = 5;
	const int MULTI_CHIPS_EACH_SLOT = 3;
	const int BOARD_HEIGHT = 12;
	const int NUM_OPTIONS = 5;

	
	const int MIN_SLOT = 0;
	const int MAX_SLOT = 8;
	const double SLOT_WINNINGS[MAX_SLOT-MIN_SLOT+1] = { 100,500,1000,0,10000,0,1000,500,100 };
	

	int main() {
		int userInput = 0;
		int chipSlot = 0;
		double lateralLocation = -1;
		double userWinnings = 0.0;
		int numChips = 0;
		double totalWinnings = 0;
	


		// declarig the random seed
		const int RANDOM_SEED = 42;
		srand(RANDOM_SEED);
		// start program
		cout << "Welcome to the Plinko simulator!  Enter "+to_string(OPTIONS_MENU)+" to see options." << endl << endl;
		userInput = GetUserInt("Enter your selection now : ", "Invalid selection.Enter " + to_string(OPTIONS_MENU) + " to see options.", 1, NUM_OPTIONS);
		// begin WHILE loop
		while (userInput != QUITTER) {

			if (userInput == SINGLE_SLOT) {
				// single slot
				/* if not between 0 &8
				for loop runs 12 times
				   if 0- auto up
				   if 8- auto down
				   if 0<8 rand () % 2
				*/
				cout << "*** Drop a single chip ***" << endl << endl;
				//FIXME GETUSERINPUT
				chipSlot = GetUserInt("Which slot do you want to drop the chip in (0-" +to_string(MAX_SLOT)+  ")? ", "Invalid slot.", MIN_SLOT, MAX_SLOT);


				
				cout << "*** Dropping chip into slot " << chipSlot << " ***" << endl;
				cout << "Path: [" << setprecision(1) << fixed;
				//plinko x1
				// USER THE FUNCTION
				userWinnings = SingleChipFall(chipSlot);
				
					cout << "Winnings: $" << setprecision(2) << fixed << userWinnings << endl << endl;

				
				
			}
			else if (userInput == MULTI_SLOT) {
				// multi slot
				userWinnings = 0.0;
				totalWinnings = 0.0;
				cout << "*** Drop multiple chips ***" << endl << endl;

				
				numChips = GetUserInt("How many chips do you want to drop (>0)? ", "Invalid number of chips.", 1);

				 // if valid number of chips
					
				chipSlot = GetUserInt("Which slot do you want to drop the chip in (0-"+ to_string(MAX_SLOT) +  ")? ", "Invalid slot.", MIN_SLOT, MAX_SLOT);

			
					//plinko x1
					for (int l = 0; l < numChips; ++l) { // for each chip
						lateralLocation = chipSlot;
						userWinnings = SingleChipFall(lateralLocation,false);
						
						
						totalWinnings = totalWinnings + userWinnings;


					}
				cout << "Total winnings on " << numChips << " chips: $" << setprecision(2) << fixed << totalWinnings << endl;
				cout << "Average winnings per chip: $" << totalWinnings / numChips << endl;
					
					
				
				





			}
			else if (userInput == OPTIONS_MENU) {
				// options menu
				cout << "Menu: Please select one of the following options:" << endl << endl;
				cout << "1 - Drop a single chip into one slot" << endl
					<< "2 - Drop multiple chips into one slot" << endl
					<< "3 - Drop multiple chips into each slot" << endl
					<< "4 - Show the options menu" << endl
					<< "5 - Quit the program" << endl;

			}

			else if (userInput == MULTI_CHIPS_EACH_SLOT) {
				cout << "*** Sequentially drop multiple chips ***" << endl << endl;
				int numChips = -1;
				numChips = GetUserInt("How many chips do you want to drop (>0)? ", "Invalid number of chips.", 1);
				for (int i = 0; i < MAX_SLOT+1; ++i) {
					userWinnings = 0.0;
					totalWinnings = 0.0;
					for (int l = 0; l < numChips; ++l) { // for each chip
						lateralLocation = i;
						userWinnings = SingleChipFall(lateralLocation, false);


						totalWinnings = totalWinnings + userWinnings;


					}
					cout << "Total winnings on " << numChips << " chips in slot " << i << " : $" << setprecision(2) << fixed << totalWinnings << endl;
					cout << "Average winnings per chip: $" << totalWinnings / numChips << endl << endl;

				}

			}
			



			userInput = GetUserInt("Enter your selection now : ", "Invalid selection.Enter " +to_string(OPTIONS_MENU)+ " to see options.", 1, NUM_OPTIONS);

		}
		cout << "Goodbye!" << endl;

		//system("Pause");
		return 0;


	}

// FUNCTIONS BEGIN HERE-----------------------------------------------------------------------------------------------------------

	double ComputeWinnings(int slotNum) {

		return SLOT_WINNINGS[slotNum];

	}

	double SingleChipFall(int initialSlot, bool wantOutput) {
		double lateralLocation = initialSlot;
		if (wantOutput == true) {
			cout << lateralLocation << ", ";
		}
		for (int i = 0; i < BOARD_HEIGHT; ++i) {

			if (lateralLocation == MIN_SLOT) { // if on far left
				lateralLocation = lateralLocation + .5;
			}
			else if (lateralLocation == MAX_SLOT) {
				lateralLocation = lateralLocation - .5;
			}
			else { // random up or down
				lateralLocation = lateralLocation + (rand() % 2 - .5);
			}
			if (wantOutput == true) {
				if (i < (BOARD_HEIGHT - 1)) {
					cout << lateralLocation << ", ";
				}
				else {
					cout << lateralLocation << "]" << endl;
				}
			}
		}
		double userWinnings = ComputeWinnings(lateralLocation);
		return userWinnings;
	}




	int GetUserInt(string prompt, string errorMessage, int min , int max) {
		int userInput = -3;
		while (true) {
			
			
			cout << prompt;
			
			cin >> userInput;

			cout << endl << endl;
			
			//cout << "THIS LINE OF CODE IS RUNNING";
			
			

			if (userInput > max || userInput < min || cin.fail()) {
				cin.clear(); //THIS solution took a long time to find, I kept getting infinite loops
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << errorMessage << endl;
				//cout << "THIS FUNCTION WORKS";
			}
			else {
				
				return userInput;
			}
		}
		

	}

	/*
	welcome
	cin userinput

	while (userInput !=4) RESET
		if UI = 1
			single slot

		if UI = 2
			multi slot
		if UI = 3
			cout options menu

		else
			cout "Invalid selection."
			continue

	 cin userINput;

	*/