#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include "BakedGood.h"
using namespace std;

class Bread : public BakedGood {
public:
	Bread();
	Bread(string variety, double price);
	string ToString();
	double DiscountedPrice(int quantity);
private:
	string variety;
};