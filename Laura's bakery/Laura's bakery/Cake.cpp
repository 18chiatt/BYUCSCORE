#include <iostream>
#include <string> 
#include <vector> 
#include <iomanip> 
#include <cctype> 
#include <limits> 
#include "BakedGood.h"
#include "Cake.h"
using namespace std;

//Default Constructor
Cake::Cake() {
	flavor = "none";
	frosting = "none";
}

//Parameterized constructor
Cake::Cake(string flavor, string frosting, double price) : BakedGood(price) {
	this->flavor = flavor;
	this->frosting = frosting;
}

//-----------------------------------------Access Member Functions-----------------------------------------------------------
