#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include <sstream>
using namespace std;

class BakedGood {
public:
	BakedGood();
	BakedGood(double price);
	virtual string ToString();
	virtual double DiscountedPrice(int quantity) = 0;
	void SetPrice(double price);
protected:
	double price;
};