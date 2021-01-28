#include "ItemToPurchase.h"
#include<iostream>
#include<string>
#include<iomanip>
#include"ShoppingCart.h"
const string ADD_OPTION = "add";
const string REMOVE_OPTION = "remove";
const string CHANGE_OPTION = "change";
const string DESCRIPTIONS_OPTION = "descriptions";
const string CART_OPTION = "cart";
const string OPTIONS_OPTION = "options";
const string QUIT_OPTION = "quit";
void OutputOptionsMenu();



int main() {


	
	
	cout << "Enter Customer's Name: ";
	string customerName;
	getline(cin, customerName);
	cout << endl;
	
	
	string todaysDate;
	cout << "Enter Today's Date: ";
	getline(cin, todaysDate);
	cout << endl;
	cout << fixed << setprecision(2);
	

	ShoppingCart theCart(customerName, todaysDate);
	string userMenuChoice = " ";

	while (true) {
		cout << endl;

		cout << "Enter option: ";
		cin >> userMenuChoice;
		// find what the user put
		// the output will be formatted for zybooks (when I use a getline, I will add in a redundant space if the code is being run in VS)
		
		if (userMenuChoice == ADD_OPTION) {
			string itemName;
			string itemDescription;
			double itemPrice;
			int itemQuantity;

			cout << "Enter the item name: ";
			cin.ignore();
			getline(cin, itemName);
			cout << endl;

			cout << "Enter the item description: ";
			getline(cin, itemDescription);
			cout << endl;

			cout << "Enter the item price: ";
			cin >> itemPrice;

			cout << "Enter the item quantity :";
			cin >> itemQuantity;
			theCart.AddItemToCart(itemName, itemDescription, itemPrice, itemQuantity);
			continue;
		} 
		if (userMenuChoice == REMOVE_OPTION) {
			cout << "Enter name of the item to remove: ";
			string itemToRemove;
			cin.ignore();
			getline(cin, itemToRemove);
			cout << endl;
			theCart.RemoveItemFromCart(itemToRemove);
			continue;
			
		} 
		if (userMenuChoice == CHANGE_OPTION) {
			cout << "Enter the item name: ";
			string itemName;
			cin.ignore();
			getline(cin, itemName);
			cout << endl;

			cout << "Enter the new quantity: ";
			int newQuantity;
			cin >> newQuantity;
			theCart.UpdateItemQuantity(itemName, newQuantity);
			continue;
		} 
		if (userMenuChoice == DESCRIPTIONS_OPTION) {
			theCart.OutputDescriptions();
			continue;
		}
		if (userMenuChoice == CART_OPTION) {
			theCart.OutputCart();
			continue;
		}
		if (userMenuChoice == OPTIONS_OPTION) {
			OutputOptionsMenu();
			continue;
		}
		if (userMenuChoice == QUIT_OPTION) {
			cout << "Goodbye.";
			return 0;
		}
		
		
			OutputOptionsMenu();
		



	}



}
void OutputOptionsMenu() {
	cout << "MENU" << endl;
	cout << "add - Add item to cart" << endl;
	cout << "remove - Remove item from cart" << endl;
	cout << "change - Change item quantity" << endl;
	cout << "descriptions - Output items' descriptions" << endl;
	cout << "cart - Output shopping cart" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "quit - Quit" << endl << endl;


}

