
#include<string>
using namespace std;
#include<iostream>

void printSpacesFollowedByNum(int i) {

	
}


int main() {
	int userN;
	cin >> userN;

	for (int counter = 0; counter < userN; counter++) {
		for (int j = 0; j < counter; j++) {
			cout << " ";
		}
		cout << counter << endl;
	}
	
}