#include<iostream>
#include<string>
#include<fstream>
#include"ExpressionManagerInterface.h"
#include"HelperFunctions.h"
#include"ExpressionManager.h"
using namespace std;


int main(int argc, char* argv[]) {

	ifstream input (argv[1]);
	ofstream output(argv[2]);
	string lineToProcess;
	ExpressionManger theExpression("hi");
	while (true) {
		string lineToProcess;
		getline(input, lineToProcess);
		string command = findNthWord(lineToProcess, 0);
		if (command == "Expression:") {
			output << endl;
		}
		output << lineToProcess;
		

		if (command == "Expression:") {
			string argOfExpression = getExpressionArg(lineToProcess);
			theExpression = ExpressionManger(argOfExpression);
		}

		if (command == "Infix:") {
			output <<" " << theExpression.infix();
		}

		if (command == "Postfix:") {
			output << " " << theExpression.postfix();
		}

		if (command == "Prefix:") {
			output << " " << theExpression.prefix();
		}

		if (command == "Value:") {
			output << " " << theExpression.value();
		}
		







		if (input.eof()) {
			break;
		}
		else {
			output << endl;
		}
	}

	

	
 }

