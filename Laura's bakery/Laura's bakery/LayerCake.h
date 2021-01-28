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

class LayerCake : public Cake {
	static const double CREAM_CHEESE;
	static const double EXTRA_LAYERS;
	static const double DISCOUNT;
public:
	LayerCake();
	LayerCake(int numLayers, string flavor, string frosting, double price);
	string ToString();
	double DiscountedPrice(int quantity);
private:
	int numLayers;
	double tempPrice;
};