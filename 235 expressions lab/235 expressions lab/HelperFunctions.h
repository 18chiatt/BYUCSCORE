#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include<string>
#include<stdbool.h>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;

bool isCloser(char toCheck) {
	string closers = "]})";
	if (closers.find(toCheck) != string::npos) {
		return true;
	}
	return false;
}

bool isOpener(char toCheck) {
	string openers = "({[";
	if (openers.find(toCheck) != string::npos) {
		return true;
	}
	return false;
}
bool isNumber(char toCheck) {
	if (toCheck > '9' || toCheck < '0') {
		return false;
	}
	return true;
}

int findWordCount(string baseString) {

	int alreadyFound = 0;
	int mostRecentIndex = 0;
	while (baseString.find(" ", mostRecentIndex) != string::npos) {
		mostRecentIndex = baseString.find(" ", mostRecentIndex + 1);
		alreadyFound++;


	}
	if (alreadyFound == 0) {
		return 0;
	}
	//output << alreadyFound;
	return alreadyFound-1;

}

string findNthWord(string baseString, int nthWord) {
	int numWords = findWordCount(baseString);

	if (nthWord == 0) {
		int firstSpaceIndex = baseString.find(" ");
		
		string toReturn = baseString.substr(0, firstSpaceIndex);
		return toReturn;

	}

	int indexBeginning = -1;
	if (nthWord == (numWords)) {
		//cout << "FInal word mode";
		for (int i = 0; i < numWords; i++) {
			indexBeginning = baseString.find(" ", indexBeginning + 1);

		}

		string toReturn = baseString.substr(indexBeginning + 1, baseString.length() - indexBeginning);
		return toReturn;



	}
	int currSpaceLocation = -1;

	for (int i = 0; i < nthWord; i++) {
		currSpaceLocation = baseString.find(" ", currSpaceLocation + 1);


	}
	int endSpaceLocation = baseString.find(" ", currSpaceLocation + 1);

	//output << "INdex of begining of nth word is " << currSpaceLocation << " end of nthWord is " << endSpaceLocation;
	int length = endSpaceLocation - 1 - currSpaceLocation;

	string toReturn = baseString.substr(currSpaceLocation + 1, length);
	return toReturn;






}

bool isBalanced(vector<string> toCheck) {
	stack<int>  toFind;
	string openersToFind = "([{";
	string closersToFind = ")]}";
	for (unsigned int i = 0; i < toCheck.size(); i++) {
		char theCharToCheck = toCheck.at(i).at(0); //we only care about the first char of each string

		if (openersToFind.find(theCharToCheck)!=string::npos) {
			toFind.push(openersToFind.find(theCharToCheck));
		}
		
		if (closersToFind.find(theCharToCheck) != string::npos) {
			//if we find a closer, check if top element is same
			int whichOne = closersToFind.find(theCharToCheck);
			if (toFind.empty() == false) {
				if (toFind.top() == whichOne) {
					toFind.pop();
				}
			}
			else {
				return false;
			}
		}

	}
	if (toFind.empty()) {
		return true;
	}
	return false;
}

string getErrorMessage(vector<string> toCheck) { //combination of the functions below
	bool previousWasNum = false; //the functions below check for each error where we want to check
	string acceptablePriorityIndicators = "(){}[]";// each input for error 
	string acceptableChars = "0123456789*%+-/()[]{}";
	int numOperands = 0;
	int numOperators = 0;


	for (unsigned int i = 0; i < toCheck.size(); i++) {
		char charToCheck = toCheck.at(i).at(0);
		if (previousWasNum == false) {
			if (!isNumber(charToCheck)) {
				
				if (acceptablePriorityIndicators.find(charToCheck) == string::npos) {
					return "Missing Operand";
				}
				
			}
		}
		
		if ((previousWasNum == false)) { //not a number
			//cout << "Previous was not number";
			//cout << "Current it : " << charToCheck;
		//cout << "Previous was not a number!";
			if (charToCheck > '9' || charToCheck < '0') {
				if (acceptablePriorityIndicators.find(charToCheck) == string::npos) {
					//cout << "THIS ERROR!";
					return "Missing Operand";
				}

			}

		}
		

		if (i == (toCheck.size() - 1)) {
			//cout << "Final character check!";
			if (!isNumber(charToCheck)) {
				if (!isCloser(charToCheck)) {
					return "Missing Operand";
				}
			}
		}
		if (previousWasNum == true) {
			if (isNumber(charToCheck)) {
				//cout << charToCheck;
				return "Missing Operator";
			}
		}

		if (isNumber(charToCheck)) {
			previousWasNum = true;
		}
		else {
			

			previousWasNum = false;
		}
			//end of adjacent operators check
		//check for illegal char
		if (acceptableChars.find(charToCheck) == string::npos) {
			
			return "Illegal Operator";
		}

		//check of too many operands
		
		if (isNumber(charToCheck)) {
			numOperands++;
		}
		else {
			if (acceptablePriorityIndicators.find(charToCheck) == string::npos) {
				numOperators++;
			}
			//numOperators++
		}

		if (isCloser(charToCheck)) {
			previousWasNum = true;
		}

	}

	if (numOperators + 1 != numOperands) {
		return "Missing Operator";
	}
	return "No Error"; //if I haven't exited, it means there is no error
}

int getPriority(char toGetPriorityOf) {
	string toCompareWith = "([{ +-  */%";
	if (toCompareWith.find(toGetPriorityOf) == string::npos) {
		return -1;
	}
	int position = toCompareWith.find(toGetPriorityOf);
	//cout << position / 4;
	//cout << "NOT BUGGED";
	return position/4;
}

bool isValid(vector<string> toCheck) {
	if (getErrorMessage(toCheck) == "No Error") {
		if (isBalanced(toCheck)) {
			return true;
		}
	}
	return false;
}



char convertToOpener(char toConvert) {
	string closerToOpener = ")]}([{";
	int position = closerToOpener.find(toConvert);
	return closerToOpener.at(position + 3);
}

bool isOperator(char toCheck) {
	string operators = "*/%+-";
	if (operators.find(toCheck) != string::npos) {
		return true;
	}
	return false;
}


int evaluateExpression(char theOperator, int firstOperand, int secondOperand) {
	if (theOperator == '/') {
		return firstOperand / secondOperand;
	}

	if (theOperator == '*') {
		return firstOperand * secondOperand;
	}
	
	if (theOperator == '%') {
		return firstOperand % secondOperand;
	}
	if (theOperator == '+') {
		return firstOperand + secondOperand;
	}
	if (theOperator == '-') {
		return firstOperand - secondOperand;
	}
	return -1;
}

int evaluatePostfix(string toEval) {
	stack<int> operands;
	int wordCount =  findWordCount(toEval)+1;
	
	
	for (int i = 0; i < wordCount; i++) {
		string toProcess = findNthWord(toEval, i);
		
		//see if it is number
		char charToAnalyze = toProcess.at(0);

		if (isNumber(charToAnalyze)) {
			//convert from string to number
			int toPush = 0;
			stringstream toGetFrom(toProcess);
			toGetFrom >> toPush;
			//cout << "PUSHING " << toPush;
			operands.push(toPush);
			continue;
		}

		if (isOperator(charToAnalyze)) {
			int secondValue = operands.top();
			operands.pop();
			int firstValue = operands.top();
			operands.pop();
			int toPush = evaluateExpression(charToAnalyze, firstValue, secondValue);
			operands.push(toPush);
		}



	}


	return operands.top();
}

string postfixToPrefix(string toConvert) {
	int wordCount = findWordCount(toConvert)+1;
	stack<string> expressions;
	//cout << "Beginning prefixing!" << endl;

	//cout << "Initial string " << toConvert;
	//cout << endl;

	for (int i = 0; i < wordCount; i++) {
		char charToProcess = findNthWord(toConvert, i).at(0);
		
		if (isOperator(charToProcess)) {
			//pop from stack and replace with new expression
			if (expressions.size() < 2) {
			}

			string firstValueString = expressions.top();
			//cout << endl << "POPPING " << expressions.top() << endl;
			expressions.pop();
			string secondValueString = expressions.top();
			//cout << endl << "POPPING " << expressions.top() << endl;
			expressions.pop();
			string operatorWithSpace = to_string(charToProcess) + ' ';
			string toPush = "";
			toPush.push_back(charToProcess);
			toPush.push_back(' ');
			toPush = toPush + secondValueString + firstValueString;
			//= operatorWithSpace + secondValueString  + firstValueString;
			//cout << "PUSHING" << toPush;
			expressions.push(toPush);
			continue;
		}

		if (isNumber(charToProcess)) {
			//cout << endl << "PUSHING " << findNthWord(toConvert, i) << endl;;
			string toPush = findNthWord(toConvert, i);
			toPush.push_back(' ');
			expressions.push(toPush);
		}

	}

	string toClip = expressions.top();
	//remove final space
	toClip = toClip.substr(0, toClip.size() - 1);

	return toClip;
}



string getExpressionArg(string lineToProcess) {

	//find the argument passed to expression
	
	//"Expression: " ->11 chars
	int lengthOfArg = lineToProcess.length() - 11;
	string toReturn = lineToProcess.substr(12, lengthOfArg);
	return toReturn;

}

//---------------------below are functions from when I checked for error conditions one at a time
//---------------------I eventually realized that you had to check for each at the same time
//---------------------Don't waste time writing useless functions

bool hasAdjacentOperators(vector<string> toCheck) {
	bool previousWasNum = false;
	string acceptablePriorityIndicators = "(){}[]";
	for (unsigned int i = 0; i < toCheck.size(); i++) {
		char charToCheck = toCheck.at(i).at(0);
		if ((previousWasNum == false)) { //not a number
			//cout << "Previous was not a number!";
			if (charToCheck > '9' || charToCheck < '0') {
				if (acceptablePriorityIndicators.find(charToCheck) == string::npos) {
					return true;
				}
				
			}
			
		}
		if (previousWasNum == false) {
			previousWasNum = true;
		}
		else {
			previousWasNum = false;
		}

		
	}
	return false;
}

bool hasIllegalOperator(vector<string> toCheck) {
	string acceptableChars = "0123456789*?%+-()[]{}";
	for (unsigned int i = 0; i < toCheck.size(); i++) {
		char charToCheck = toCheck.at(i).at(0);
		if (acceptableChars.find(charToCheck) == string::npos) {
			return true;
		}
		
	}

	return false;
}



bool tooManyOperands(vector<string> toCheck) {
	int numOperands = 0;
	int numOperators = 0;

	for (unsigned int i = 0; i < toCheck.size(); i++) {
		char charToCheck = toCheck.at(i).at(0);
		if (isNumber(charToCheck)) {
			numOperands++;
		}
		else {
			numOperators++;
		}
	}

	if (numOperators + 1 != numOperands) {
		return true;
	}
	return false;

}



#endif // !HELPER_FUNCTIONS_H
