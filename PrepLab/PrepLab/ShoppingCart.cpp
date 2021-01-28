#include "ShoppingCart.h"
#include<string>
using namespace std;



ShoppingCart::ShoppingCart()
{
	this->customerName = "none";
	this->creationDate = "none";
}

int ShoppingCart::FindIndexInCart(string name)
{
	int indexToDelete = -1;
	for (int i = 0; i < itemsInCart.size(); ++i) {
		if (itemsInCart.at(i).GetName() == name) {
			indexToDelete = i;
		}
	}
	return indexToDelete;
}

string ShoppingCart::GetItemName(int index)
{
	return itemsInCart.at(index).GetName();
}

int ShoppingCart::GetItemQuantity(int index)
{
	return itemsInCart.at(index).GetQuantity();
}

double ShoppingCart::GetItemPrice(int index)
{
	return itemsInCart.at(index).GetPrice();

}

double ShoppingCart::GetItemTotalPrice(int index)
{
	return itemsInCart.at(index).GetQuantity()*itemsInCart.at(index).GetPrice();
}

string ShoppingCart::GetItemDescription(int index)
{
	return itemsInCart.at(index).GetItemDescription();
}

ShoppingCart::ShoppingCart(string customerName, string creationDate)
{
	this->customerName = customerName;
	this->creationDate = creationDate;
}

string ShoppingCart::GetCustomerName()
{
	return customerName;
}

string ShoppingCart::GetCreationDate()
{
	return creationDate;
}

void ShoppingCart::SetCustomerName(string customerName)
{
	this->customerName = customerName;
}

void ShoppingCart::SetCreationDate(string creationDate)
{
	this->creationDate = creationDate;
}

void ShoppingCart::AddItemToCart(string itemName, string itemDescription, double itemPrice, int itemQuantity)
{
	if (FindIndexInCart(itemName) == -1) {
		ItemToPurchase tempName(itemName, itemDescription, itemPrice, itemQuantity);
		itemsInCart.push_back(tempName);
	}
	else {
		cout << "Item is already in cart. Nothing added.";
	}

}

void ShoppingCart::RemoveItemFromCart(string itemToRemoveName)
{
	int indexToRemove = FindIndexInCart(itemToRemoveName);
	if (indexToRemove == -1) {
		cout << "Item not found in cart. Nothing removed.";
	}
	else {
		itemsInCart.erase(itemsInCart.begin() + indexToRemove);
	}
	
	
}

void ShoppingCart::UpdateItemQuantity(string itemToUpdateName, int newQuantity)
{
	int indexToUpdate = FindIndexInCart(itemToUpdateName);
	if (indexToUpdate == -1) {
		cout << "Item not found in cart. Nothing modified.";
	}
	else {
		itemsInCart.at(indexToUpdate).SetQuantity(newQuantity);
	}

}

int ShoppingCart::GetNumberItems()
{
	int totalItems = 0;
	for (int i = 0; i < itemsInCart.size(); ++i) {
		totalItems = totalItems + itemsInCart.at(i).GetQuantity();

	}
	return totalItems;
}

double ShoppingCart::GetTotalCost()
{
	double totalCost = 0.0;
	for (int i = 0; i < itemsInCart.size(); ++i) {
		totalCost = totalCost + itemsInCart.at(i).GetPrice()*itemsInCart.at(i).GetQuantity();

	}
	return totalCost;
}

void ShoppingCart::OutputCart()

{
	cout << customerName << "'s Shopping Cart - " << creationDate << endl << endl;
	if (itemsInCart.size() > 0) {
		
		cout << "Number of items: " << GetNumberItems();
		cout << endl << endl;
		for (int i = 0; i < itemsInCart.size(); ++i) {
			cout << GetItemName(i) << " " << GetItemQuantity(i) << " @ $" << GetItemPrice(i) << " = $" << GetItemTotalPrice(i) << endl;

		}
		cout << endl;
		cout << "Total: $" << GetTotalCost() << endl;
	}
	else {
		cout << "Shopping cart is empty." << endl << endl;
	}
}

void ShoppingCart::OutputDescriptions()
{
	cout << customerName << "'s Shopping Cart - " << creationDate << endl << endl;
	if (itemsInCart.size() > 0) {
		cout << endl;
		cout << "Item Descriptions" << endl;
		for (int i = 0; i < itemsInCart.size(); ++i) {
			cout << GetItemName(i) << ": " << GetItemDescription(i) << endl;

		}
	}
	else {
		cout << "Shopping cart is empty." << endl << endl;
	}
}
