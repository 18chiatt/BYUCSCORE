#include<vector>
#include<iostream>	
#include<string>
#include"BakedGood.h"
#include"Bread.h"
#include<iomanip>
#include"LayerCake.h"
#include"CupCake.h"

//the pragma once acts as my include guard for most of these classes.
using namespace std;

const double BREAD_PRICE = 4.50;
const double CUPCAKE_PRICE = 1.95;
const double LAYERCAKE_PRICE = 9.00;
const double PRICE_INCREASE_PER_LAYER = 1.00;
const string END_IT_ALL_COMMAND = "done";
// bool ShouldIIncreasePrice(string frostingName); //my attempt at using a truly global variable system ,in which all constants can be declared in main, it does not work. I tried many different methods
string FindNthWord(string baseString, int numberWord);
//template <class whoknows> I only need to get ints, so I don't have to worry about a template
int GetNumberFromString(string baseString);



int main() {
	vector<BakedGood*> shoppingCart;
	cout << "**Bread and Cakes Bakery**" << endl << endl;



	//testing area for findNthWord

	//string testString = "Bread epic 3";
	//string zeroString = FindNthWord(testString, 2);
	//cout << zeroString << endl;

	//string epicTest = "32";
	//int testBed = GetNumberFromString(epicTest);
	//cout << endl << testBed << endl;

	//system("Pause");

	cout << "Enter sub-order (enter \"" << END_IT_ALL_COMMAND<< "\" to finish)" << endl;

	while (true) {
		string userInput = "";//get input
		cout << "Sub-order: "; //prompt input
		getline(cin, userInput);

		//figure out which type was entered to properly process input
		if (FindNthWord(userInput, 0) == "Bread") {
			//user is inputting bread;
			//cout << "ITS BREAD TIME";
			string typeOfBread = FindNthWord(userInput, 1);
			string stringToFindNumberIn = FindNthWord(userInput, 2);
			int userInstancesOfThisBread = GetNumberFromString(stringToFindNumberIn);
			//cout << userInstancesOfThisBread << endl;

			//add N bread of type typeOfBread to vectorShoppingCart

			for (int i = 0; i < userInstancesOfThisBread; i++) {
				Bread *breadToAdd = new Bread(typeOfBread, BREAD_PRICE);
				shoppingCart.push_back(breadToAdd);

			}



		}
		//cupcake time
		if (FindNthWord(userInput, 0) == "Cupcake") {
			//IT'S CUPCAKE TIME
			string flavor = FindNthWord(userInput, 1);
			string frosting = FindNthWord(userInput, 2);
			string sprinklesColor = FindNthWord(userInput, 3);
			string quantity = FindNthWord(userInput, 4);
			int numObjectsToAdd = GetNumberFromString(quantity);
			//add each of the pointers to the vector

			for (int i = 0; i < numObjectsToAdd; i++) {
				//add cupcake to vector

				CupCake *newCupcake = nullptr;
				newCupcake = new CupCake(sprinklesColor, flavor, frosting, CUPCAKE_PRICE);
				//add objects to vector
				shoppingCart.push_back(newCupcake);

			}

		}
		// layer cake time
		if (FindNthWord(userInput, 0) == "Layer-cake") {
			//user selected layer cake
			string flavor = FindNthWord(userInput, 1);
			string frosting = FindNthWord(userInput, 2);
			string numLayersString = FindNthWord(userInput, 3);
			int numLayers = GetNumberFromString(numLayersString);
			string quantityItemString = FindNthWord(userInput, 4);
			int quantityInt = GetNumberFromString(quantityItemString);

			for (int i = 0; i < quantityInt; i++) {
				LayerCake *newLayerCake = nullptr;
				newLayerCake = new LayerCake(numLayers, flavor, frosting, LAYERCAKE_PRICE);
				//add objects to vector
				shoppingCart.push_back(newLayerCake);


			}

		}




		if (FindNthWord(userInput, 0) == END_IT_ALL_COMMAND) {
			break;

		}
	}
		//FINISHED with input area


	cout << endl << endl;
	cout << "Order Confirmations:" << endl;

	for (int i = 0; i < shoppingCart.size(); i++) {
		cout << shoppingCart.at(i)->ToString() << endl;
	} // finished confirmation area


	// INVOICE
	vector<BakedGood*> differentItems; //vector of unique items
	vector<int> indexsOfUniqueGoods;
	vector<int>quantityOfEachUniqueGood;

	for (int i = 0; i < shoppingCart.size(); i++) {
		//fresh item
		bool foundAMatch = false;
		for (int l = 0; l < differentItems.size(); l++) {
			//find if it matches any items already on the list
			if (shoppingCart.at(i)->ToString() == differentItems.at(l)->ToString()) {
				// we found a match on the already existing list
				// 
				foundAMatch = true;
				quantityOfEachUniqueGood.at(l)++;
				//increase count of the count of that good

			}

		}
		if (foundAMatch == false) {
			// item was not found on list
			differentItems.push_back(shoppingCart.at(i));
			indexsOfUniqueGoods.push_back(i);
			quantityOfEachUniqueGood.push_back(1);
		}

	}

	//testing the above vectors
	//cout << differentItems.at(0)->ToString() << quantityOfEachUniqueGood.at(0) << " Should be bread TOString " << endl;
	//system("Pause");




	double totalPrice = 0.0;
	int totalQuantity = 0;
	cout << "Invoice:" << endl;
	cout << "Baked Good" << setw(75);
	cout << "Quantity" << setw(9);
	cout << "Total" << setw(9) << endl;


	// cout << differentItems.at(0)->ToString() << " bread 4.50 stuff, " << quantityOfEachUniqueGood.at(0) << " is quantity " << endl;

	//output each unique item's stats

	for (int i = 0; i < differentItems.size(); i++) {
		string stringToPrint = differentItems.at(i)->ToString();
		
		int quantityItems = quantityOfEachUniqueGood.at(i);
		//cout << " We know there are " << quantityItems << " items of this kind";
		double currItemPrice = differentItems.at(i)->DiscountedPrice(quantityItems);

		//cout << "Price as a double is: " << currItemPrice;
		totalPrice = totalPrice + currItemPrice;
		totalQuantity = totalQuantity + quantityOfEachUniqueGood.at(i);


		
		cout << stringToPrint; //setw is super broken, I'm doing this manually.

		int numSpacesToPrint = 75 - stringToPrint.length();
		for (int i = 0; i < numSpacesToPrint; i++) {
			cout << " ";
		}

		cout << setw(9) << quantityItems;
		cout << fixed << setprecision(2);
		cout << setw(9) << currItemPrice << endl;
		cout << scientific;

		






	}
	string totals = "Totals";
	cout << totals;

	for (int i = 0; i < 75 - totals.length(); i++) {
		cout << " ";

	}
	cout << setw(9) << totalQuantity;
	cout << setw(9) << fixed << setprecision(2) << totalPrice << endl;

	//system("Pause");
	
	cout << "Good bye";
	return 0;
}

string FindNthWord(string baseString, int numberWord){
	int currIndex = 1;
	baseString.append("                                 "); //this stops the program from having trouble with the final word
	vector<int> spaceLocations;
	while (baseString.find(" ", currIndex) != string::npos) {
		spaceLocations.push_back(baseString.find(" ", currIndex));
		currIndex = spaceLocations.back()+1;

	}
	if (numberWord == 0) {
		int startOfWordToFind = 0;
		int endOfWordToFind = spaceLocations.at(0);
		string wordToReturn = baseString.substr(0, endOfWordToFind);
		//cout << "it knows we want the 0th";
		return wordToReturn;


	}
	int startOfWordToFind = spaceLocations.at(numberWord-1);
	int endOfWordToFind = spaceLocations.at(numberWord);
	int lengthOfWordToFind = endOfWordToFind - startOfWordToFind;
	string wordToReturn = baseString.substr(startOfWordToFind + 1, lengthOfWordToFind - 1);
	return wordToReturn;

	
}

int GetNumberFromString(string baseString) {

	// cout << baseString << " should be just a number and nothing else"; 

	//system("Pause");
	int number = stoi(baseString);
	return number;


}
