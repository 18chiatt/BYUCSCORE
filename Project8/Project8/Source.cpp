#include<iostream>
#include<string>
using namespace std;

int main() {

	int numNumbersToLoopThrough;
	int numberToPrint;

	cin >>numNumbersToLoopThrough;

	for (int i = 0; i < numNumbersToLoopThrough; ++i) {
		cin >> numberToPrint;
		for (int j = 0; j < numberToPrint; ++j) {
			cout << numberToPrint;
		}
		cout << endl;
	}
	//


	return 0;
}