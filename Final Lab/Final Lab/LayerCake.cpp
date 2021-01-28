#include "LayerCake.h"
#include<iostream>
using namespace std;
const string FROSTING_THAT_INCREASES_PRICE = "cream-cheese";
const double AMOUNT_TO_INCREASE_PRICE_BY = 1.0;
const double LAYER_CAKE_BASE_PRICE = 9.0;
const double EXTRA_CHARGE_PER_LAYER = 3.0;
string LayerCake::ToString(){

	string stringToReturn = to_string(numLayers) + "-layer " + flavor + " cake with " + frosting + " frosting ($" + GetPriceString()+")";




	return stringToReturn;
}

LayerCake::LayerCake(int numLayers, string flavor, string frosting, double price) : Cake(flavor,frosting,price){
	this->numLayers = numLayers;
	this->basePrice = price;
	//cout << endl << numLayers << " is the number of layers" << endl;
	int numExtraLayers = numLayers - 1;
	//cout << frosting << "IS THE FROSTING" << endl;
	if (frosting == FROSTING_THAT_INCREASES_PRICE) {
		//cout << "IT'S CREAM CHEESE TIME " << endl;
		double extraChargeForCreamCheese = AMOUNT_TO_INCREASE_PRICE_BY * numLayers;
		//cout << extraChargeForCreamCheese << " is the extra we are charging for cream cheese ==3?" << endl;
		//cout << basePrice << " is the price" << endl;
		IncreasePrice(extraChargeForCreamCheese);
		//cout << basePrice << " Is the increased price " << endl;
	}
	
	
	double extraChargeForThiccStacks = numExtraLayers * EXTRA_CHARGE_PER_LAYER;
	IncreasePrice(extraChargeForThiccStacks);
}

double LayerCake::DiscountedPrice(int instances){
	double totalDiscount = 0.0;
	if (instances > INSTANCES_TO_GET_DISCOUNT - 1) {
		totalDiscount = instances * DISCOUNT_PER_ITEM_IF_DISCOUNT_AMOUNT_IS_ACHIEVED;

	}
	return instances*(basePrice -totalDiscount/instances);

}


