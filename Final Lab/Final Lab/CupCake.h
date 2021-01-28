#pragma once
#include"Cake.h"

#ifndef CUPCAKE_H
const double TWO_OR_MORE_PRICE_REDUCTION = .3;
const double SECOND_TIER_PRICE_REDUCTION_ADDITIONAL_DISCOUNT = .1;
const int PRICE_REDUCTION_TIER_ONE = 1; // set this to be one lower than you want the price reduction breakpoint for the initial discount to be
const int PRICE_REDUCTION_TIER_TWO = 4;  //set this one higher than you want the price reduction tier two breakpoint to be


class CupCake : public Cake {
public:
	string ToString();// this is virtual because the specs says "Your three derived classes Bread, LayerCake and CupCake should at least each have the following virtual member functions: ToString, DIscountedPrice"
	CupCake(string sprinklesColor, string flavor, string frosting, double itemPrice);
	double DiscountedPrice(int instances);
	

protected:
	string sprinklesColor;


};
#endif
