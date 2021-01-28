#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int largePizzas;
	int mediumPizzas;
	int smallPizzas;
	int numGuests;
	int diameterLargePizza = 20;
	int diameterMediumPizza = 16;
	int diameterSmallPizza = 12;
	int totalArea;

	const double PI = 3.14159265;

	const double largePizzaArea = pow((0.5 * diameterLargePizza), 2.0) * PI;
	const double mediumPizzaArea = pow((0.5 * diameterMediumPizza), 2.0) * PI;
	const double smallPizzaArea = pow((0.5 * diameterSmallPizza), 2.0) * PI;
	double avgInches;
	double largePizzaCost = 14.68;
	double mediumPizzaCost = 11.48;
	double smallPizzaCost = 7.28;
	double userTip;
	double totalCost;

	cout << "Please enter the amount of guests you expect to have: " << endl;
	cin >> numGuests;
	int totalGuests = numGuests;

	largePizzas = numGuests / 7;
	numGuests = numGuests % 7;
	mediumPizzas = numGuests / 3;
	numGuests = numGuests % 3;
	smallPizzas = numGuests / 1;

	totalArea = (largePizzaArea * largePizzas + mediumPizzaArea * mediumPizzas + smallPizzaArea * smallPizzas);
	avgInches = (totalArea / totalGuests);


	cout << "You will need " << largePizzas << " large pizzas, " << mediumPizzas << " medium pizzas, and " << smallPizzas << " small pizzas.";
	cout << endl;

	cout << "A total of " << totalArea << " square inches of pizza will be ordered. " << avgInches << " inches per person." << endl;

	cout << "Please enter the tip as a percentage. (ex.10 = 10%) : " << endl;
	cin >> userTip;
	cout << endl;

	totalCost = ((largePizzas * largePizzaCost) + (mediumPizzas * mediumPizzaCost) + (smallPizzas * smallPizzaCost)) * userTip;
	cout << "Your total cost will be: " << totalCost << endl;


	return 0;
}
