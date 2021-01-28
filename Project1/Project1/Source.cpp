#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	int userInput = 0;
	int chipSlot = 0;
	double lateralLocation = -1;
	double userWinnings = 0.0;
	int numChips = 0;
	double totalWinnings = 0;
	const int SINGLE_SLOT = 1;
	const int MULTI_SLOT = 2;
	const int OPTIONS_MENU = 3;
	const int QUITTER = 4;
	const int BOARD_HEIGHT = 12;
	const int SLOT_0_8_WINNINGS = 100;
	const int SLOT_1_7_WINNINGS = 500;
	const int SLOT_2_6_WINNINGS = 1000;
	const int SLOT_3_5_WINNINGS = 0;
	const int SLOT_4_WINNINGS = 10000;
	const int MIN_SLOT = 0;
	const int MAX_SLOT = 8;


	// declarig the random seed
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);
	// start program
	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userInput;
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
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> chipSlot;


			if ((chipSlot >= MIN_SLOT) && (chipSlot <= MAX_SLOT)) {
				cout << "*** Dropping chip into slot " << chipSlot << " ***" << endl;
				cout << "Path: [" << setprecision(1) << fixed;
				//plinko x1
				lateralLocation = chipSlot;
				cout << lateralLocation << ", ";
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
					if (i < (BOARD_HEIGHT - 1)) {
						cout << lateralLocation << ", ";
					}
					else {
						cout << lateralLocation << "]" << endl;
					}
				}
				// calculate winnings
				if ((lateralLocation == MIN_SLOT) || (lateralLocation == MAX_SLOT)) {
					userWinnings = SLOT_0_8_WINNINGS;
				}
				else if ((lateralLocation == MIN_SLOT + 1) || (lateralLocation == MAX_SLOT - 1)) {
					userWinnings = SLOT_1_7_WINNINGS;
				}
				else if ((lateralLocation == MIN_SLOT + 2) || (lateralLocation == MAX_SLOT - 2)) {
					userWinnings = SLOT_2_6_WINNINGS;
				}
				else if ((lateralLocation == MIN_SLOT + 3) || (lateralLocation == MAX_SLOT - 3)) {
					userWinnings = SLOT_3_5_WINNINGS;
				}
				else if (lateralLocation == MAX_SLOT / 2) {
					userWinnings = SLOT_4_WINNINGS;
				}
				else {
					cout << "SOMETHING WENT VERY WRONG, PLEASE HELP ME";
					break;
				}
				cout << "Winnings: $" << setprecision(2) << fixed << userWinnings << endl << endl;

			}
			else {
				// invalid range

				cout << endl << "Invalid slot." << endl << endl;
			}
		}
		else if (userInput == MULTI_SLOT) {
			// multi slot
			userWinnings = 0.0;
			totalWinnings = 0.0;
			cout << "*** Drop multiple chips ***" << endl << endl;

			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl;

			if (numChips > 0) { // if valid number of chips
				cout << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> chipSlot;
				cout << endl << endl;

				if ((chipSlot >= MIN_SLOT) && (chipSlot <= MAX_SLOT)) { //FIXME CHANGE TO MAXVAL AND MINVAL
					//plinko x1
					for (int l = 0; l < numChips; ++l) {
						lateralLocation = chipSlot;
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
						}
						// calculate winnings
						if ((lateralLocation == 0) || (lateralLocation == 8)) {
							userWinnings = SLOT_0_8_WINNINGS;
						}
						else if ((lateralLocation == 1) || (lateralLocation == 7)) {
							userWinnings = SLOT_1_7_WINNINGS;
						}
						else if ((lateralLocation == 2) || (lateralLocation == 6)) {
							userWinnings = SLOT_2_6_WINNINGS;
						}
						else if ((lateralLocation == 3) || (lateralLocation == 5)) {
							userWinnings = SLOT_3_5_WINNINGS;
						}
						else if (lateralLocation == 4) {
							userWinnings = SLOT_4_WINNINGS;
						}
						else {
							cout << "SOMETHING WENT VERY WRONG, PLEASE HELP ME"

								<< lateralLocation;
							break;
						}
						totalWinnings = totalWinnings + userWinnings;


					}
					cout << "Total winnings on " << numChips << " chips: $" << setprecision(2) << fixed << totalWinnings << endl;
					cout << "Average winnings per chip: $" << totalWinnings / numChips << endl;
				}
				else {
					cout << "Invalid slot." << endl << endl;
				}
			}
			else { // if invalid number of chips
				cout << "Invalid number of chips." << endl << endl;
			}





		}
		else if (userInput == OPTIONS_MENU) {
			// options menu
			cout << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl
				<< "2 - Drop multiple chips into one slot" << endl
				<< "3 - Show the options menu" << endl
				<< "4 - Quit the program" << endl;
		}
		else {
			// invalid input
			cout << "Invalid selection.Enter 3 to see options." << endl << endl;
		}



		cout << "Enter your selection now : ";
		cin >> userInput;
		cout << endl << endl;


	}
	cout << "Goodbye!" << endl;

	system("Pause");
	return 0;
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