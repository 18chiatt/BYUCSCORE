#pragma once
#ifndef LACEDSHOE_H
#define LACEDSHOE_H

#include "Footwear.h"

#include <iostream>

using namespace std;

class LacedShoe :public Footwear {
public:
	LacedShoe(string name, string upperMaterial, string soleMaterial, string primaryColor, int size) : Footwear(name, upperMaterial, soleMaterial, primaryColor, size) {
		this->isTied = false;
	}
	bool AreTied() {
		return isTied;
	}
	void Tie() {
		this->isTied = true;
		cout << "tied " << name << endl;

	}
	void Untie() {
		cout << "untied " << name << endl;
		this->isTied = false;

	}

	void Remove() {
		if (AreTied()) {
			Untie();

		}
		this->onFeet = false;
		cout << name << " removed" << endl;

	}

	void Apply() {
		this->onFeet = true;
		cout << name << " applied" << endl;


	}
private:
	bool isTied;

};

#endif
