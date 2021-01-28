#include "Cake.h"

Cake::Cake(string flavor, string frosting, double price): BakedGood(price){
	this->flavor = flavor;
	this->frosting = frosting;


}

void Cake::IncreasePrice(double amountToIncreaseBy){
	this->basePrice = this->basePrice + amountToIncreaseBy;

}

