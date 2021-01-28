#include "CupCake.h"
#include<string>
const string FROSTING_THAT_INCREASES_PRICE = "cream-cheese";
const double AMOUNT_TO_INCREASE_PRICE_BY = .2;


string CupCake::ToString(){
	string stringToReturn = flavor + " cupcake with " + frosting + " frosting and " + sprinklesColor + " sprinkles ($" + GetPriceString() + ")";
	return stringToReturn;
}

CupCake::CupCake(string sprinklesColor, string flavor, string frosting, double itemPrice) :Cake(flavor, frosting, itemPrice) {
	this->sprinklesColor = sprinklesColor;
	if (frosting == FROSTING_THAT_INCREASES_PRICE) { 
		IncreasePrice(AMOUNT_TO_INCREASE_PRICE_BY);


	}
	// this->basePrice = itemPrice;

}

double CupCake::DiscountedPrice(int instances){
	double totalDiscount = 0.0;
	if (instances > PRICE_REDUCTION_TIER_ONE && instances < PRICE_REDUCTION_TIER_TWO ) {
		//.3 discount
		totalDiscount = instances * TWO_OR_MORE_PRICE_REDUCTION;
	}
	else if (instances >= PRICE_REDUCTION_TIER_TWO) {
		//.4 (or whatever the const is set as) discount
		totalDiscount = instances * SECOND_TIER_PRICE_REDUCTION_ADDITIONAL_DISCOUNT + instances * TWO_OR_MORE_PRICE_REDUCTION;
	}
	
	return (GetPrice() - totalDiscount/instances)*instances;

	
}

