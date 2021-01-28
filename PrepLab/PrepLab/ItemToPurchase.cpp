#include "ItemToPurchase.h"
#include <iostream> 
#include<string>





ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity)
{
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription)
{
	this->itemName = itemName;
	this->itemDescription = itemDescription;

}

ItemToPurchase::ItemToPurchase(double itemPrice, int itemQuantity)
{
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
}

ItemToPurchase::ItemToPurchase(double itemPrice)
{
	this->itemPrice = itemPrice;
}

ItemToPurchase::ItemToPurchase(int itemQuantity)
{
	this->itemQuantity = itemQuantity;
}

ItemToPurchase::ItemToPurchase(string itemName)
{
	this->itemName = itemName;
}

void ItemToPurchase::SetName(string nameToSet)
{
	this->itemName = nameToSet;
}

string ItemToPurchase::GetName() {
	return itemName;

}

void ItemToPurchase::SetPrice(double priceToSet)
{
	this->itemPrice = priceToSet;
}

double ItemToPurchase::GetPrice()
{
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantityToSet)
{
	this->itemQuantity = quantityToSet;
}

int ItemToPurchase::GetQuantity()
{
	return itemQuantity;
}

void ItemToPurchase::SetItemDescription(string itemDescription)
{
	this->itemDescription = itemDescription;
}

string ItemToPurchase::GetItemDescription()
{
	return itemDescription;
}

void ItemToPurchase::OutputItemCost()
{
	cout << itemName << " " << itemQuantity << " @ " << itemPrice << " = $" << itemPrice * itemQuantity;
}

void ItemToPurchase::OutputItemDescription()
{
	cout << itemName << ": " << itemDescription;
}


