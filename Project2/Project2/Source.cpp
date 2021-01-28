#include<vector>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

void SwapTwoValues(vector<string>& thingToSwitch);
bool PowerOfTwo(int numberToCheck);

int main() {
	vector<string> helpMe;

	helpMe.push_back("SUPER EPIC");
	helpMe.push_back("REALLY GAY");


	cout << "First Value Pre Swap : " << helpMe.at(0) << endl;
	

	SwapTwoValues(helpMe);

	cout << "First Value post Swap : " << helpMe.at(0) << endl;

	if (PowerOfTwo(1024)) {
		cout << "IS A POWER OF 8" << endl;
	} else{
		cout << "ISN'T A POWER OF 2" << endl;
	}
	cout << " 1%2 = " << 1 % 2;

	system("Pause");





}

void SwapTwoValues(vector<string> &thingToSwitch) {
	string tempVal = thingToSwitch.at(0);
	thingToSwitch.at(0) = thingToSwitch.at(1);
	thingToSwitch.at(1) = tempVal;

}

bool PowerOfTwo(int numberToCheck) {
	while (numberToCheck != 1) {
		if ((numberToCheck % 2) == 0) {
			numberToCheck = numberToCheck / 2;
		}
		else {
			return false;
		}
	}
	return true;
}


