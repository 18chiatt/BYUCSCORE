#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include <sstream>
#include "BakedGood.h"
#include "Cake.h"
#include "CupCake.h"
using namespace std;

//Default Constructor
CupCake::CupCake() {
	sprinklesColor = "none";
}

//Parameterized Constructor
CupCake::CupCake(string sprinklesColor, string flavor, string frosting, double price) : Cake(flavor, frosting, price) {
	if (frosting == "cream-cheese") {
		tempPrice = CREAM_CHEESE + price;
	}
	else {
		tempPrice = price;
	}
	SetPrice(tempPrice);
	this->sprinklesColor = sprinklesColor;
}

//---------------------------------------------Access Member Functions----------------------------------------------------
string CupCake::ToString() {
	ostringstream oSS;
	oSS << fixed << showpoint << setprecision(2);
	oSS << flavor << " cupcake with " << frosting << " frosting and " << sprinklesColor << " sprinkles " << BakedGood::ToString();
	return oSS.str();
}

double CupCake::DiscountedPrice(int quantity) {
	double newUnitPrice;

	if (quantity > 3) {
		newUnitPrice = price - BIGGER_DISCOUNT;
	}
	else if (quantity > 1) {
		newUnitPrice = price - INITIAL_DISCOUNT;
	}
	else {
		newUnitPrice = price;
	}

	return newUnitPrice * quantity;
}