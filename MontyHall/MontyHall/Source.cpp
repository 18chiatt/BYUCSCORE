#include<iostream>
#include<random>
#include<time.h>
#include<vector>

using namespace std;

int chooseDoor(void);
int guessDoor(void);
int newGuess(int notThisDoor);

int main() {
	int NUM_SIMULATIONS = 10000;
	int numAttemptsNoSwitch = 0;
	int numSuccessNoSwitch = 0;
	int numAttemptsWithSwitch = 0;
	int numSuccessWithSwitch = 0;

	
	srand(time(NULL));
	
	

	for (int i = 0; i < NUM_SIMULATIONS; i++) {


		int guess = guessDoor();
		int theDoor = chooseDoor();

		if (theDoor == guess) {
			numSuccessNoSwitch++;
			numAttemptsNoSwitch++;

		}
		else {
			numAttemptsNoSwitch++;
		}// no switching

		//with switching


		//determine which door to reveal
		vector<int> numbers;

		numbers.push_back(0);
		numbers.push_back(1);
		numbers.push_back(2);

		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) == guess || numbers.at(i) == theDoor) {
				numbers.erase(numbers.begin() + i);
			}
		}



		int doorToReveal = numbers.at(0);

		int theNewGuess;

		theNewGuess = newGuess(doorToReveal);


		if (theNewGuess == theDoor) {
			numAttemptsWithSwitch++;
			numSuccessWithSwitch++;

		}
		else {
			numAttemptsWithSwitch++;
		}

	
		






	}

	
	
	double percantage = numSuccessNoSwitch*1.0 / numAttemptsNoSwitch*1.0;
	cout << "We tried " << numAttemptsNoSwitch << " times and suceeded " << numSuccessNoSwitch << " times for a percentage of " << percantage*100 << endl;

	cout << endl;

	cout << "---- below is with switching -----" << endl;
	cout << "We tried " << numAttemptsWithSwitch << " times and suceeded " << numSuccessWithSwitch << " times for a percentage of " << (numSuccessWithSwitch * 1.0 / numAttemptsWithSwitch * 1.0) * 100<< endl;


	return 0;
}

int guessDoor(void) {
	int number = rand() % 3;

	return number;
}

int newGuess(int notThisDoor){
	int newGuess = notThisDoor;

	while (newGuess == notThisDoor) {
		newGuess = rand() % 3;


	}
	return newGuess;
	

	
}

int chooseDoor(void) {
	int number = rand() % 3;

	return number;


}