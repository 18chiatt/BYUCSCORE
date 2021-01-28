#pragma once
#include<string>

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
using namespace std;

class ItemToPurchase
{
public:
	ItemToPurchase(string itemName, string itemDescription, double itemPrice ,int itemQuantity);
	ItemToPurchase(string itemName, string itemDescription);
	ItemToPurchase(double itemPrice, int itemQuantity);
	ItemToPurchase(double itemPrice);
	ItemToPurchase(int itemQuantity);
	ItemToPurchase(string itemName);
	void SetName(string nameToSet);
	string GetName();
	void SetPrice(double priceToSet);
	double GetPrice();
	void SetQuantity(int quantityToSet);
	int GetQuantity();
	void SetItemDescription(string itemDescription);
	string GetItemDescription();
	void OutputItemCost();
	void OutputItemDescription();


private:
	string itemDescription = "none";
	string itemName = "none";
	double itemPrice = 0.0;
	int itemQuantity = 0;



};

#endif