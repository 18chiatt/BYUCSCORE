#include "SlipOnShoe.h"
#include "LacedShoe.h"

#include <vector>

#include <iostream>

using namespace std;

int main() {
	//a few slip on shoes...
	SlipOnShoe cowboyBoots("cowboy boots", "leather", "dense rubber", "brown", 10);//giddyup 
	SlipOnShoe usedToBeCool("Crocks", "foamy rubber", "foamy rubber", "green", 5);//still comfy
	SlipOnShoe toLookTall("1 inch heels", "plastic", "dense rubber", "black", 6);//I'm a bug... 1 inch is huge...

	cowboyBoots.Apply();
	usedToBeCool.Apply();
	toLookTall.Apply();

	toLookTall.Remove();
	cowboyBoots.Remove();

	//a few laced shoes...
	LacedShoe runningShoes("running shoes", "polyester", "soft rubber", "white", 8);
	LacedShoe sundayShoes("dress shoes", "genuine leather", "dense leather", "dark brown", 9);
	LacedShoe workShoes("Redwing boots", "leather", "dense rubber", "black", 15);
	
	

	runningShoes.Apply();
	sundayShoes.Apply();
	workShoes.Apply();

	system("Pause");

	runningShoes.Tie();
	sundayShoes.Tie();
	workShoes.Tie();
	sundayShoes.Untie();

	sundayShoes.Remove();
	runningShoes.Remove();

	//now let's try some polymorphism...
	vector<Footwear*> shoeList;
	shoeList.push_back(&cowboyBoots);
	shoeList.push_back(&usedToBeCool);
	shoeList.push_back(&toLookTall);
	shoeList.push_back(&runningShoes);
	shoeList.push_back(&sundayShoes);
	shoeList.push_back(&workShoes);

	for (unsigned int i = 0; i < shoeList.size(); i++) {
		cout << shoeList.at(i)->ToStr();
		if (shoeList.at(i)->OnFeet()) {
			shoeList.at(i)->Remove();
		}
	}
	system("Pause");
	return 0;
}
