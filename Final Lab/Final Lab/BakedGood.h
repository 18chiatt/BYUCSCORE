#pragma once
#include<string>
using namespace std;

class BakedGood {
public:
	virtual string ToString() = 0; // pure virtual function, overloaded by each other function
	BakedGood( double price);
	string GetPriceString();
	virtual double DiscountedPrice(int instances) = 0;
	double GetPrice();


protected:
	double basePrice; //the only piece of information EVERYTHING has in common





};
