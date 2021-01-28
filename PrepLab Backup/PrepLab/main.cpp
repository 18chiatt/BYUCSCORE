#include "ItemToPurchase.h"
#include<iostream>
#include<string>
#include<iomanip>



int main() {
	ItemToPurchase itemOne;
	ItemToPurchase itemTwo;

	cout << fixed << setprecision(2);
	cout << "Item 1" << endl;
	cout << "Enter the item name: ";
	string tempString = " ALLLLLLA";
	getline(cin, tempString);
	itemOne.SetName(tempString);
	cout << "Enter the item price: ";
	double tempDouble;
	cin >> tempDouble;
	itemOne.SetPrice(tempDouble);
	cout << "Enter the item quantity: ";
	int tempInt = -1;
	cin >> tempInt;
	itemOne.SetQuantity(tempInt);
	// first item done


	cout << endl << endl;

	cout << "Item 2" << endl;
	cin.ignore();
	cout << "Enter the item name: ";

	getline(cin, tempString);
	itemTwo.SetName(tempString);

	cout << "Enter the item price: ";
	cin >> tempDouble;
	itemTwo.SetPrice(tempDouble);

	cout << "Enter the item quantity: ";
	cin >> tempInt;
	itemTwo.SetQuantity(tempInt);


	cout << endl << endl;

	double itemOneCost = itemOne.GetQuantity()*itemOne.GetPrice();
	double itemTwoCost = itemTwo.GetQuantity()*itemTwo.GetPrice();

	cout << "TOTAL COST" << endl;
	cout << itemOne.GetName() << " " << itemOne.GetQuantity() << " @ $" << itemOne.GetPrice() << " = $" << itemOneCost << endl;
	cout << itemTwo.GetName() << " " << itemTwo.GetQuantity() << " @ $" << itemTwo.GetPrice() << " = $" << itemTwoCost;
	cout << endl << endl;
	cout << "Total: $" << itemOneCost + itemTwoCost;

	



}