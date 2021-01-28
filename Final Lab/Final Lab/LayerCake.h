#pragma once
#include"Cake.h"
#ifndef LAYERCAKE_H
const int INSTANCES_TO_GET_DISCOUNT = 3; // set this to the amount you actually want to get the discount
const double DISCOUNT_PER_ITEM_IF_DISCOUNT_AMOUNT_IS_ACHIEVED = 2.0;

class LayerCake : public Cake {
public:
	string ToString(); // this is virtual because the specs says "Your three derived classes Bread, LayerCake and CupCake should at least each have the following virtual member functions: ToString, DIscountedPrice"
	LayerCake(int numLayers, string flavor, string frosting, double price);
	double DiscountedPrice(int instances);

private:
	int numLayers;

};
#endif
