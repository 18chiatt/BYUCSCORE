#include<iostream>
#include <math.h> 
#include<vector>
#include<iomanip>
using namespace std;


int main() {

	vector<double> theNumbers;

	for (int i = 1; i < 100; i++) {	
		double theThing = i;
		theNumbers.push_back(1.0 / pow(theThing,5));
	}



	while(true) {
		double theCount = 0;
		int numNumbersWanted = 0;
		cin >> numNumbersWanted;

		for (int i = 0; i < numNumbersWanted; i++) {
			theCount += theNumbers.at(i);
		}
		cout << "S sub " << numNumbersWanted << " is " << setprecision(12) << theCount << endl;


	}

	return 0;

}