#include<string>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<limits>
using namespace std;
//constant decleration
// Input constants
const int UNLIKELYINPUT = -1457772322;
const string QUIT_PROGRAM = "quit";
const string DISPLAY_RESTRAUNTS = "display";
const string ADD_RESTRAUNT = "add";
const string REMOVE_RESTRAUNT = "remove";
const string CUT_LIST = "cut";
const string SHUFFLE_LIST = "shuffle";
const string BATTLE_TIME = "battle";
const string OPTION_MENU = "options";
const vector<string> MENU_OPTIONS = {QUIT_PROGRAM,DISPLAY_RESTRAUNTS,ADD_RESTRAUNT,REMOVE_RESTRAUNT,CUT_LIST,SHUFFLE_LIST,BATTLE_TIME,OPTION_MENU };
// 



//function prototypes
bool PowerOfTwo(int numberToCheck);
void OutputMenu();
string GetMenuChoice(vector<string>& restrauntList);
void AddRestraunt(vector<string>& restrauntList);
void DisplayRestraunts(vector<string>& restrauntList);
void RemoveRestraunt(vector<string>& restrauntList);
int FindInRestrauntList(string stringToFind, vector<string>& restrauntList );
void CutTheList(vector<string>& restrauntList);
vector<string> ShuffleList(vector<string>& restrauntList);
int GetUserInt(string prompt, string errorMessage, int min = 0, int max = 900000000);
void AlertUserPowerOfTwoFailure(string attemptedFunction, int currentSize);
void DoBattle(vector<string>& restrauntList);
int GetBattleChoice(string optionOne, string optionTwo);




int main() { // --------------------------------BEGIN MAIN--------------------------------------------------
	// begin menu portion
	vector<string> restrauntList;
	
	string userString = " ";
	int userInt = -1;
	cout << "Welcome to the restaurant battle!  Enter \"options\" to see options." << endl << endl;
	while (true) {
		
		cout << "Enter your selection: ";
		userString = GetMenuChoice(restrauntList); // GET INPUT


		// act on input
		if (userString == OPTION_MENU) {
			OutputMenu();
		}
		if (userString == "THIS USER WANTS TO QUIT, THIS IS NOT A DRILL") {
			cout << "Goodbye!";
			return 0;

		}
		if (userString == ADD_RESTRAUNT) {
			AddRestraunt(restrauntList);
		}
		if (userString == DISPLAY_RESTRAUNTS) {
			DisplayRestraunts(restrauntList);
		}
		if (userString == REMOVE_RESTRAUNT) {
			RemoveRestraunt(restrauntList);
		}
		if (userString == CUT_LIST) {
			CutTheList(restrauntList);

		}
		if (userString == SHUFFLE_LIST) {
			if (PowerOfTwo(restrauntList.size())) {
				restrauntList = ShuffleList(restrauntList);
			}
			else {
				AlertUserPowerOfTwoFailure("shuffle", restrauntList.size());
			}
		}
		if (userString == BATTLE_TIME) {
			if (PowerOfTwo(restrauntList.size())) {
				// BATTLE TIME
				DoBattle(restrauntList);
			}
			else {
				AlertUserPowerOfTwoFailure("battle", restrauntList.size());
			}
		}
		


	}
	return 0;
} /*
  
  -------------------------------------------BEGIN FUNCTIONS-------------------------------------------------------------------------------------------------------------
  
  
  */
void DoBattle(vector<string>& restrauntList) {
	int numberOfRounds = 0;
	int numberToCheck = restrauntList.size();
	vector<string> copiedRestrauntList;
	for (int i = 0; i < restrauntList.size(); ++i) {
		copiedRestrauntList.push_back(restrauntList.at(i)); //copy restraunt list to new vector
	}
	while (numberToCheck != 1) { // see how many rounds
		if ((numberToCheck % 2) == 0) {
			numberToCheck = numberToCheck / 2;
			numberOfRounds = numberOfRounds + 1;
		}
		
	}
	
	for (int i = 0; true; ++i) {
		//each round
		cout << "Round: " << i+1 << endl << endl;
		int bankedSize = copiedRestrauntList.size();
		int cycles = 0;
		for (int j = 0; j < bankedSize ; j=j+2) {

			//individual battles
			
			int whatToKeep = GetBattleChoice(copiedRestrauntList.at(j-cycles), copiedRestrauntList.at(j -cycles+1));
			int whatToErase = -1;
			if (whatToKeep == 0) {
				whatToErase = 1;
			}
			else {
				whatToErase = 0;
			}
			//cout << "You entered: " << whatToKeep << endl;
			//cout << "I'm about to erase " << copiedRestrauntList.at(whatToErase - cycles) << endl;
			copiedRestrauntList.erase(copiedRestrauntList.begin()+whatToErase+j-cycles);
			
			if(copiedRestrauntList.size()==1){
				cout << "The winning restaurant is " << copiedRestrauntList.at(0) << "." << endl << endl;
				return;
			}
			cycles = cycles + 1;
		}

	}



	}

	
	
	




int GetBattleChoice(string optionOne, string optionTwo) {
	while (true) {
		int userInput;
		cout << "Type \"1\" if you prefer " << optionOne << " or" << endl;
		cout << "Type \"2\" if you prefer " << optionTwo << endl;
		cout << "Choice: ";
		cin >> userInput;

		if (userInput > 2 || userInput < 1 || cin.fail()) {
			cin.clear(); //THIS solution took a long time to find, I kept getting infinite loops
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice" << endl;
			//cout << "THIS FUNCTION WORKS";
		}
		else {

			return userInput-1;
		}


	}

}

void AlertUserPowerOfTwoFailure(string attemptedFunction, int currentSize) {
	cout << "The current tournament size (" << currentSize << ") is not a power of two (2, 4, 8...)." << endl;
	cout << "A " << attemptedFunction << " is not possible. Please add or remove restaurants.";

}


vector<string> ShuffleList(vector<string>& restrauntList) {
	vector<string> firstDeck;
	vector<string> secondDeck;
	int numInEachDeck = restrauntList.size() / 2;
	for (int i = 0; i < numInEachDeck; ++i) {
		firstDeck.push_back(restrauntList.at(i));

	}
	for (int i = 0; i < numInEachDeck; ++i) {
		secondDeck.push_back(restrauntList.at(i + numInEachDeck));
	}
	vector<string> newDeck;

	for (int i = 0; i < restrauntList.size(); ++i) {
		if (i % 2) {
			newDeck.push_back(firstDeck.at(i / 2));
		}
		else {
			newDeck.push_back(secondDeck.at(i / 2));
		}
	}

	return newDeck;

}


void CutTheList(vector<string>& restrauntList) {
	int cardsToCut = GetUserInt("How many restaurants should be taken from the top and put on the bottom? ", "The cut number must be between 0 and "
		+ to_string(restrauntList.size()),0, restrauntList.size());
	vector<string> tempStorage;

	for (int i = 0; i < cardsToCut; ++i) {
		tempStorage.push_back(restrauntList.at(0));
		restrauntList.erase(restrauntList.begin() + 0);

	} // erased
	for (int i = 0; i < cardsToCut; ++i) {
		restrauntList.push_back(tempStorage.at(i));
	}

}





int FindInRestrauntList(string stringToFind, vector<string>& restrauntList) {
	for (int i = 0; i < restrauntList.size(); ++i) {
		if (restrauntList.at(i) == stringToFind) {
			return i;
		}


	}
	return -1;

}


void RemoveRestraunt(vector<string>& restrauntList) {
	string restrauntToRemove = " ";
	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, restrauntToRemove);
	

	//check if restrauntToRemove is in restrauntList

	int indexToRemove = FindInRestrauntList(restrauntToRemove, restrauntList);
	if (indexToRemove == -1) {
		cout << "That restaurant is not on the list, you can not remove it." << endl;
	}
	else {
		restrauntList.erase(restrauntList.begin() + indexToRemove);
		cout << restrauntToRemove << " has been removed." <<  endl;
		cout << endl;
	}

	
	

}





void DisplayRestraunts(vector<string>& restrauntList) {

	cout << "Here are the current restaurants: " << endl << endl;

	for (int i = 0; i < restrauntList.size(); ++i) {
		cout << "\t\"" << restrauntList.at(i) << "\"" << endl;
	}
	cout << endl;



}


void AddRestraunt(vector<string>& restrauntList) {
	cout << "What is the name of the restaurant you want to add?" << endl << endl;
	string restrauntName = " ";
	getline(cin, restrauntName);
	int lookForRestrauntName = FindInRestrauntList(restrauntName, restrauntList);

	if (lookForRestrauntName == -1) {
		restrauntList.push_back(restrauntName);
		cout << restrauntName << " has been added." << endl << endl;
		return;
	}
	else {
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
	}

	
	
	
}


bool PowerOfTwo(int numberToCheck) {
	while (numberToCheck != 1) {
		if ((numberToCheck % 2) == 0) {
			numberToCheck = numberToCheck / 2;
		}
		else {
			return false;
		}
	}
	return true;
}

void OutputMenu() {
	
		cout << "Please select one of the following options:" << endl << endl;
		cout << QUIT_PROGRAM << " - Quit the program" << endl;
		cout << DISPLAY_RESTRAUNTS << " - Display all restaurants" << endl;
		cout << ADD_RESTRAUNT << " - Add a restaurant" << endl;
		cout << REMOVE_RESTRAUNT << " - Remove a restaurant" << endl;
		cout << CUT_LIST << " - \"Cut\" the list of restaurants" << endl;
		cout << SHUFFLE_LIST << " - \"Shuffle\" the list of restaurants" << endl;
		cout << BATTLE_TIME << " - Begin the tournament" << endl;
		cout << OPTION_MENU << " - Print the options menu" << endl;

	
}

string GetMenuChoice(vector<string>& restrauntList) {
	string userString = " ";
	int userChoice = -1;
	while (true) {
		cin >> userString;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;
		

		// check if it matches anything

		for (int i = 0; i < MENU_OPTIONS.size(); ++i) {
			if (userString == MENU_OPTIONS.at(i)) {
				userChoice = i;
				break;
			}
		}
		//error checking
		if (userChoice == -1) {
			cout << "Invalid Selection" << endl;
			OutputMenu();
			cout << "Enter your selection: " << endl;
		}
		else if (userString == QUIT_PROGRAM) {
			return "THIS USER WANTS TO QUIT, THIS IS NOT A DRILL"; // by returning multiple words I can ensure this is not reached through a coincidental cin
		}
		else {
			return userString;
		}


	}

}

int GetUserInt(string prompt, string errorMessage, int min, int max) {
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


