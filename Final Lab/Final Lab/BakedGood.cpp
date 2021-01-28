#include "BakedGood.h"
#include<math.h>
#include<tgmath.h>
#include<iomanip>
#include<sstream> // I had to google this to figure out how to round to two decimals;
#include<iostream>
using namespace std;

BakedGood::BakedGood(double price){
	this->basePrice = price;
	


}

string BakedGood::GetPriceString(){

	stringstream stream;
	stream << fixed << setprecision(2) << basePrice;
	string s = stream.str();
	return s;
}

double BakedGood::GetPrice(){

	return basePrice;
}


