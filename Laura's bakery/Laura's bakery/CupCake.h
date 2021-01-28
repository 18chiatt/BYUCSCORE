#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include "BakedGood.h"
#include "Cake.h"
using namespace std;

class CupCake : public Cake {
	static const double CREAM_CHEESE;
	static const double INITIAL_DISCOUNT;
	static const double BIGGER_DISCOUNT;
public:
	CupCake();
	CupCake(string sprinklesColor, string flavor, string frosting, double price);
	string ToString();
	double DiscountedPrice(int quantity);
private:
	string sprinklesColor;
	double tempPrice;
};