#pragma once
#ifndef SLIPONSHOE_H
#define SLIPONSHOE_H

#include "Footwear.h"
#include <iostream>
#include<string>

using namespace std;

class SlipOnShoe :public Footwear {
public:
	SlipOnShoe(string name, string upperMaterial, string soleMaterial, string primaryColor, int size) : Footwear(name, upperMaterial,soleMaterial, primaryColor,size){


	}
	void Apply() {
		onFeet = true;
		cout << name << " applied" << endl;
	}
	void Remove() {
		onFeet = false;
		cout << name << " removed" << endl;

	}

private:

};
#endif
