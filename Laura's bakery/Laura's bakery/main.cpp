#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"
using namespace std;

//Constants used in classes
const double LayerCake::CREAM_CHEESE = 1.0;
const double LayerCake::EXTRA_LAYERS = 3.0;
const double LayerCake::DISCOUNT = 2.0;
const double CupCake::CREAM_CHEESE = 0.2;
const double CupCake::INITIAL_DISCOUNT = 0.3;
const double CupCake::BIGGER_DISCOUNT = 0.4;

//Function declarations
string GetString(string prompt);
int FindInOrder(vector<BakedGood*> tempOrder, string tempString);

int main() {
	const string DONE = "done";
	const string BREAD = "Bread";
	const string CUPCAKE = "Cupcake";
	const string LAYERCAKE = "Layer-cake";
	const double BREAD_PRICE = 4.5;
	const double CUPCAKE_PRICE = 1.95;
	const double LAYERCAKE_PRICE = 9.0;

	vector<BakedGood*> customerOrder;
	Bread* newBread;
	CupCake* newCupCake;
	LayerCake* newLayerCake;
	string bakedGoodType;
	string breadVariety;
	string cakeFlavor;
	string cakeFrosting;
	string cupcakeSprinkles;
	int numLayers;
	int quantity;
	istringstream inSS;

	cout << "**Bread and Cakes Bakery**" << endl;
	cout << endl;	

	//Part 1: Get the order
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	inSS.str(GetString("Sub-order: "));
	inSS >> bakedGoodType;

	while (bakedGoodType != DONE) {
		if (bakedGoodType == BREAD) { //Create a bread object with the given parameters
			inSS >> breadVariety >> quantity;
			for (int i = 0; i < quantity; ++i) {
				newBread = new Bread(breadVariety, BREAD_PRICE);
				customerOrder.push_back(newBread);
			}

			inSS.clear(); //Get ready for a new order
			inSS.str(GetString("Sub-order: "));
			inSS >> bakedGoodType;
		}
		else if (bakedGoodType == CUPCAKE) { //Create a cupcake object with the given parameters
			inSS >> cakeFlavor >> cakeFrosting >> cupcakeSprinkles >> quantity;
			for (int i = 0; i < quantity; ++i) {
				newCupCake = new CupCake(cupcakeSprinkles, cakeFlavor, cakeFrosting, CUPCAKE_PRICE);
				customerOrder.push_back(newCupCake);
			}

			inSS.clear(); //Get ready for a new order
			inSS.str(GetString("Sub-order: "));
			inSS >> bakedGoodType;
		}
		else if (bakedGoodType == LAYERCAKE) { //Create a layercake object with the given parameters
			inSS >> cakeFlavor >> cakeFrosting >> numLayers >> quantity;
			for (int i = 0; i < quantity; ++i) {
				newLayerCake = new LayerCake(numLayers, cakeFlavor, cakeFrosting, LAYERCAKE_PRICE);
				customerOrder.push_back(newLayerCake);
			}

			inSS.clear(); //Get ready for a new order
			inSS.str(GetString("Sub-order: "));
			inSS >> bakedGoodType;
		}
		else { //If they give an invalid type
			cout << "Invalid type of baked good." << endl;

			inSS.clear(); //Get ready for a new order
			inSS.str(GetString("Sub-order: "));
			inSS >> bakedGoodType;
		}
	}

	cout << endl;

	//Part 2: Confirm order (print it)
	cout << "Order Confirmations:" << endl;
	for (int i = 0; i < customerOrder.size(); ++i) {
		cout << customerOrder.at(i)->ToString() << endl;
	}

	cout << endl;
	//Part 3: Print invoice
	vector<BakedGood*> tempVector;
	vector<int> quantities;

	//Build vectors with the info we need
	for (int i = 0; i < customerOrder.size(); ++i) {

		if (FindInOrder(tempVector, customerOrder.at(i)->ToString()) != -1) { //If we have this good already recorded, just increment its quantity
			quantities.at(FindInOrder(tempVector, customerOrder.at(i)->ToString())) += 1;
		}
		else { //If this is a new good, put a pointer into our tempVector and make its quantity 1
			tempVector.push_back(customerOrder.at(i));
			quantities.push_back(1);
		}
	}

	//Print out the invoice from the vectors we made
	cout << "Invoice:" << endl;
	cout << left << setw(75) << "Baked Good" << right << setw(10) << "Quantity" << right << setw(10) << "Total" << endl;

	double priceTotal = 0;
	int quantityTotal = 0;

	for (int i = 0; i < tempVector.size(); ++i) {
		cout << left << setw(75) << tempVector.at(i)->ToString();
		cout << right << setw(10) << quantities.at(i);
		cout << right << setw(10) << fixed << setprecision(2) << tempVector.at(i)->DiscountedPrice(quantities.at(i)) << endl;
		priceTotal += tempVector.at(i)->DiscountedPrice(quantities.at(i));
		quantityTotal += quantities.at(i);
	}

	cout << left << setw(75) << "Totals" << right << setw(10) << quantityTotal << right << setw(10) << fixed << setprecision(2) << priceTotal << endl;
	cout << "Good Bye" << endl;

	//system("pause");
	return 0;
}

string GetString(string prompt) {
	string temp;

	cout << prompt << endl;
	getline(cin, temp);

	return temp;
}

int FindInOrder(vector<BakedGood*> tempOrder, string tempString) {
	if (tempOrder.size() == 0) {
		return -1;
	}
	else {
		for (int i = 0; i < tempOrder.size(); ++i) {
			if (tempOrder.at(i)->ToString() == tempString) {
				return i;
			}
		}
		return -1;
	}
}