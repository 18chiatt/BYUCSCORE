#pragma once
#include<string>

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
using namespace std;

class ItemToPurchase
{
public:

	void SetName(string nameToSet);
	string GetName();
	void SetPrice(double priceToSet);
	double GetPrice();
	void SetQuantity(int quantityToSet);
	int GetQuantity();

private:
	string itemName = "none";
	double itemPrice = 0.0;
	int itemQuantity = 0;



};

#endif