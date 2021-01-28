#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include <sstream>
#include "BakedGood.h"
#include "Cake.h"
#include "LayerCake.h"
using namespace std;

//Default Constructor
LayerCake::LayerCake() {
	numLayers = 0;
}

//Parameterized Constructor
LayerCake::LayerCake(int numLayers, string flavor, string frosting, double price) : Cake(flavor, frosting, price){
	this->numLayers = numLayers;
	if (frosting == "cream-cheese") {
		tempPrice = ((CREAM_CHEESE + EXTRA_LAYERS) * (numLayers - 1)) + CREAM_CHEESE + price;
	}
	else {
		tempPrice = (EXTRA_LAYERS * (numLayers - 1)) + price;
	}
	SetPrice(tempPrice);
}

//---------------------------------------------Access Member Functions----------------------------------------------------
string LayerCake::ToString() {
	ostringstream oSS;
	oSS << fixed << showpoint << setprecision(2);
	oSS << numLayers << "-layer " << flavor << " cake with " << frosting << " frosting " << BakedGood::ToString();
	return oSS.str();
}

double LayerCake::DiscountedPrice(int quantity) {
	double newUnitPrice;

	if (quantity > 2) {
		newUnitPrice = price - DISCOUNT;
	}
	else {
		newUnitPrice = price;
	}

	return newUnitPrice * quantity;
}