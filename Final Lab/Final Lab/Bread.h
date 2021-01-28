#pragma once
#include"BakedGood.h"

class Bread : public BakedGood {
public:
	string ToString();// this is virtual because the specs says "Your three derived classes Bread, LayerCake and CupCake should at least each have the following virtual member functions: ToString, DIscountedPrice"
	Bread(string breadType = "wow ", double basePrice = 3.14);
	double DiscountedPrice(int instances); // see above


private:
	string breadType;

};
