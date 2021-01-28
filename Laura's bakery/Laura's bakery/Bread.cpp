#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include <sstream>
#include "BakedGood.h"
#include "Bread.h"
using namespace std;

//Default Constructor
Bread::Bread() {
	variety = "none";
}

//Parameterized Constructor
Bread::Bread(string variety, double price) : BakedGood(price) {
	this->variety = variety;
}

//---------------------------------------------Access Member Functions----------------------------------------------------
string Bread::ToString() {
	ostringstream oSS;
	oSS << fixed << showpoint << setprecision(2);
	oSS << variety << " bread " << BakedGood::ToString();
	return oSS.str();
}

double Bread::DiscountedPrice(int quantity) {
	double totalPrice;
	int extra = quantity % 3;

	totalPrice = (((quantity - extra) * (2.0 / 3.0)) + extra) * price;

	return totalPrice;
}