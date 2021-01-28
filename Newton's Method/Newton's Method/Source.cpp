#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

double fOfX(double toFindOf) {
	double toReturn = 0;
	toReturn += pow(toFindOf, 4) * 3;
	toReturn -= pow(toFindOf, 3) * 8;
	toReturn += 2;
	return toReturn;
}

double fPrimeOfX(double toFindOf) {
	double toReturn = 0;
	toReturn += pow(toFindOf, 3) * 12;
	toReturn -= (toFindOf, 2) * 24;
	return toReturn;
}


int main() {
	string userString;
	double toProcess;
	double next = 0;
	int iterations = 0;
	
	while (true) {
		if (next == 0) {
			cin >> toProcess;
		}
		else {
			toProcess = next;
		}
		
		cout << setprecision(10);
		cout << iterations << endl;
		cout << "f of " << toProcess << " = " << fOfX(toProcess) << endl;
		cout << "f ' of " << toProcess << " = " << fPrimeOfX(toProcess) << endl;
		cout << "f of x - (f(x)-f'(x) = " << toProcess - (fOfX(toProcess) / fPrimeOfX(toProcess)) << endl;
		next = toProcess - (fOfX(toProcess) / fPrimeOfX(toProcess));
		iterations++;

		if (iterations == 400) {
			break;
		}
	}
	

}