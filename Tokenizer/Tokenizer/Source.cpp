#include<iostream>
#include<fstream>
#include<string>
#include"Scanner.h"
#include<vector>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Usage is " << argv[0] << " filename.fileExtention";
	}
	


	Scanner myScanner(argv[1]);
	myScanner.scan();

	myScanner.printTokens();
	
	
	myScanner.clearVector();
	return 0;
}