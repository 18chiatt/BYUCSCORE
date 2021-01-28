#include "ItemToPurchase.h"
#include <iostream> 
#include<string>



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


