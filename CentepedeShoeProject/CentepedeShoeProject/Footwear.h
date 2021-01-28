#pragma once
#ifndef FOOTWEAR_H
#define FOOTWEAR_H

#include <string>

using namespace std;

class Footwear {
public:
	Footwear(string name, string upperMaterial, string soleMaterial, string primaryColor, int size) {
		this->name = name;
		this->size = size;
		this->upperMaterial = upperMaterial;
		this->soleMaterial = soleMaterial;
		this->primaryColor = primaryColor;
		onFeet = false;
	}

	string Name() {
		return name;
	}
	int Size() {
		return size;
	}
	string UpperMaterial() {
		return upperMaterial;
	}
	string SoleMaterial() {
		return soleMaterial;
	}
	bool OnFeet() {
		return onFeet;
	}
	string PrimaryColor() {
		return primaryColor;
	}
	string ToStr() {
		return "size " + to_string(size) + " " + primaryColor + " " + name + " with " + upperMaterial + " uppers and " + soleMaterial + " soles" + "\n";
	}

	virtual void Apply() = 0;
	virtual void Remove() = 0;


protected:

	string name;
	int size;
	string upperMaterial;
	string soleMaterial;
	string primaryColor;
	bool onFeet;

private:

};

#endif
