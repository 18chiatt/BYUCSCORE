#include "Bread.h"
#include<sstream>
#include<iomanip>
#include<iostream>
using namespace std;

string Bread::ToString(){
	stringstream stream;
	stream << fixed << setprecision(2) << basePrice;
	string s = stream.str();

	string stringToReturn = breadType + " " + "Bread ($" + s +")";


	return stringToReturn;
}

Bread::Bread(string breadType, double basePrice) :BakedGood(basePrice) {
	this->breadType = breadType;
}

double Bread::DiscountedPrice(int instances){
	int numFreeBread = instances / 3; // this is an int so we know how many bread are free.
	int numOfPaidBread = instances - numFreeBread;
	//cout << "Bread was being checked for price";
	return numOfPaidBread * basePrice;
	
}



