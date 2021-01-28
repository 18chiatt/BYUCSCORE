#pragma once
#include"BakedGood.h"



class Cake : public BakedGood {
public:
	virtual string ToString() = 0;
	Cake(string flavor, string frosting, double price);
	void IncreasePrice(double amountToIncreaseBy);
	virtual double DiscountedPrice(int instances) = 0;


protected:

	string flavor;
	string frosting;


};
