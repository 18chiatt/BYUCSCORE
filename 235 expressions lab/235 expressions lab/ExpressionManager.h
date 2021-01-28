#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
#include"ExpressionManagerInterface.h"
#include"HelperFunctions.h"
#include<string>
#include<vector>
#include<stdbool.h>
#include<sstream>
using namespace std;


class ExpressionManger : public ExpressionManagerInterface {
private:
	vector<string> theExpression;
public:
	ExpressionManger(string expression) {
		int numThings = findWordCount(expression)+1;
		for (int i = 0; i < numThings; i++) {
			theExpression.push_back( findNthWord(expression, i));
			
		}
	}


	int value(void)  {
		if (!isValid(theExpression)) {
			return -1;
		}

		string expressionInPostfix = this->postfix();
		int toReturn = evaluatePostfix(expressionInPostfix);
		return toReturn;
	}

	string toString(void) const {
		string toReturn;
		for (unsigned int i = 0; i < theExpression.size()-1; i++) {
			toReturn = toReturn + theExpression.at(i);
			toReturn.push_back(' ');
		}
		toReturn = toReturn + theExpression.at(theExpression.size()-1);
		return toReturn;
	}

	string postfix(void)  {
		if (!isValid(theExpression)) {
			return "Expression not valid!";
		}
		stringstream toReturn;
		stack<char> operators;

		for (unsigned int i = 0; i < theExpression.size(); i++) {
			char toAnalyze = theExpression.at(i).at(0);
			if (isNumber(toAnalyze)) {
				toReturn << " " << theExpression.at(i);
				continue;
			}
			//not a number
			if (isOpener(toAnalyze)) {
				operators.push(toAnalyze);
				continue;
			}
			if (isCloser(toAnalyze)) {
				while (convertToOpener(toAnalyze) != operators.top()) {
					toReturn << " " << operators.top();
					operators.pop();
				}
				operators.pop();
				continue;
			}
			if (operators.empty()) {
				operators.push(toAnalyze);
				continue;
			}
			int incomingPriority = getPriority(toAnalyze);
			int topPriority = getPriority(operators.top());

			if (incomingPriority > topPriority) {
				operators.push(toAnalyze);
				continue;
			}
			//stack isn't empty
			//thing on stack has at least equal priority
			while (true) {
				toReturn << " " << operators.top();
				operators.pop();
				if (operators.empty()) {
					operators.push(toAnalyze);
					break;
				}
				topPriority = getPriority(operators.top());
				if (incomingPriority > topPriority) {
					operators.push(toAnalyze);
					break;
				}

			}




		}



		while (!operators.empty()) {
			toReturn << " " << operators.top();
			operators.pop();
		}
		string realToReturn = toReturn.str().substr(1, toReturn.str().length() - 1);
		return realToReturn;

	}

	string infix(void) {
		
		
		try {
			if (!(isBalanced(theExpression))) {
				string toThrow = "Unbalanced";
				throw toThrow;
			}
			string potentialErrorMessage = getErrorMessage(theExpression);
			if (potentialErrorMessage != "No Error") { //if the message returned is No Error it means there is no error
				//if getErrorMessage finds an error, we throw it
				throw potentialErrorMessage;
			}
		}
		catch (string error) {
			return error;
		} //finished handling eronius input
		
		
		return this->toString();
	}

	string prefix(void) {
		//get postfix

		string toConvert = this->postfix();
		string toReturn = postfixToPrefix(toConvert);
		return toReturn;

	}

	string returnHi(void);

}; 




#endif // !EXPRESSION_MANAGER_H

