#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include "BakedGood.h"
using namespace std;

class Cake : public BakedGood {
public:
	Cake();
	Cake(string flavor, string frosting, double price);
protected:
	string flavor;
	string frosting;
};