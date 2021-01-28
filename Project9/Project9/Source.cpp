#include<iostream>
#include<ostream>
#include<fstream>

using namespace std;


void printInt(int toPrint) {

	toPrint = toPrint / 2;
	cout << toPrint;

}

int printAndDivideByTwo(int toDivide) {
	int toReturn = toDivide / 2;

	return toReturn;
}

int main() {

	

	int five = 5;
	int returned = printAndDivideByTwo(five);
	
	cout << endl << returned;
	cout << endl;

	cout << five;

	return 0;
}