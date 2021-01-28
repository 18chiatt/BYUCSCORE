#include "Scanner.h"
#include<string>
#include<fstream>
#include<stdbool.h>
#include<set>
#include <ctype.h>
#include<sstream>
#include<iostream>

using namespace std;


void Scanner::scan(){
	int nextChar = 0;
	string theValue = "";
	int currLine = 1;
	Token * toAddToVector;

	while (nextChar != -1) {
		nextChar = toScan.get();

		if (nextChar == '\n') {
			//new line
			currLine++;
			continue;
		}
		if (isSingleCharPunctuation(nextChar)) {
			this->createSingleCharToken(nextChar,currLine);
			continue;
		}


		if (nextChar == ':') {
			//check if next char is-
			int nextNextChar = toScan.peek();
			if (nextNextChar == '-') {
				toScan.get();
				//create :- token
				toAddToVector = new Token(TokenTypes::COLON_DASH, ":-", currLine);
				tokens.push_back(toAddToVector);
				continue;
			}else {
				//create : token and continue
				toAddToVector = new Token(TokenTypes::COLON, ":", currLine);
				tokens.push_back(toAddToVector);
				continue;

			}
		}

		if (isalpha(nextChar)) {
			//create id or keyword token
			createKeywordIdentifierToken(nextChar, currLine);
			continue;

		}

		if (isspace(nextChar)) {
			continue;
		}

		if (nextChar == '\'') {
			currLine = createStringToken(nextChar, currLine);
			continue;

		}

		if (nextChar == '#') {
			//comment mode
			currLine = createCommentToken(nextChar, currLine);
			continue;
		}
		if (isspace(nextChar)) {
			continue;
		}
		//not in one of these categories means it is undefined
		if (nextChar == -1) {
			break;
		}

		char nextCharAsChar = nextChar;
		createUndefinedToken(nextCharAsChar, currLine);

		


		
	}

	toAddToVector = new Token(TokenTypes::END_OF_FILE, "", currLine);
	tokens.push_back(toAddToVector);

}

Scanner::Scanner(string fileName){
	toScan.open(fileName);
	this->populateMap();
}

void Scanner::printTokens(void){
	for (unsigned int i = 0; i < tokens.size(); i++) {
		cout << tokens.at(i)->toString() << endl;;
			
	}

	cout << "Total Tokens = " << tokens.size() << endl; 

}

void Scanner::clearVector(void){
	

	for (unsigned int i = 0; i < tokens.size(); i++) {
		delete tokens[i];
	}
	return;
}

bool Scanner::isSingleCharPunctuation(int toCheck) {
	set<char> punctuation{ ',','.','?','(',')','*','+' };
	char charToCheck = toCheck;
	if (punctuation.count(charToCheck)) {
		return true;
	}
	return false;
}

void Scanner::populateMap(void){
	stringToType["Rules"] = TokenTypes::RULES;
	stringToType["Queries"] = TokenTypes::QUERIES;
	stringToType["Facts"] = TokenTypes::FACTS;
	stringToType["Schemes"] = TokenTypes::SCHEMES;
}

void Scanner::createKeywordIdentifierToken(char currChar, int lineNum){
	stringstream currWord("");
	char nextChar = toScan.peek();
	currWord << currChar;

	while (isalnum(nextChar)) {
		nextChar = toScan.get();
		currWord << nextChar;
		nextChar = toScan.peek();
	}

	if (stringToType.count(currWord.str()) == 1) {
		//keyword
		TokenTypes theType = stringToType.at(currWord.str());
		Token* toAppend = new Token(theType, currWord.str(), lineNum);
		tokens.push_back(toAppend);
		return;
	}
	//is identifier
	Token* toAppend = new Token(TokenTypes::ID, currWord.str(), lineNum);
	tokens.push_back(toAppend);
	return;

}

int Scanner::createStringToken(char currChar, int lineNum){
	stringstream theString("");
	int initialLineNum = lineNum;
	theString << currChar;
	TokenTypes theType = TokenTypes::STRING;
	
	while (true) {
		int nextChar = toScan.get();
		if (nextChar == -1) {
			theType = TokenTypes::UNDEFINED;
			break;
		}
		if (nextChar == '\'') {
			int nextNextChar = toScan.peek();
			if (nextNextChar == '\'') {
				toScan.get();
				theString << '\'';
				continue;
			}
			//end of string
			theString << "'";
			break;
		}
		if (currChar == '\n') {
			lineNum++;
			theString << "\n";
			continue;
		}
		char nextCharAsChar = nextChar;
		theString << nextCharAsChar;

		


	}

	Token* toAppend = new Token(theType, theString.str(), initialLineNum);
	tokens.push_back(toAppend);

	return lineNum;
}

int Scanner::createCommentToken(char currChar, int lineNum){
	int nextChar = toScan.peek();
	stringstream theComment("");
	if (nextChar == '|') {
		//block comment
		toScan.get();
		int initialLineNum = lineNum;
		theComment << "#|";
		while (true) {
			nextChar = toScan.get();
			if (nextChar == -1) {
				//invalid comment, undefined type
				Token* toAppend = new Token(TokenTypes::UNDEFINED, theComment.str(), initialLineNum);
				tokens.push_back(toAppend);
				return lineNum;
			}
			if (nextChar == '\n') {
				char charAsChar = nextChar;
				theComment << charAsChar;
				lineNum++;
				continue;
			}

			if (nextChar == '|') {
				int nextNextChar = toScan.peek();
				if (nextNextChar == '#') {
					//end of comment
					theComment << "|#";
					Token* toAppend = new Token(TokenTypes::COMMENT, theComment.str(), initialLineNum);
					tokens.push_back(toAppend);
					return lineNum;
				}
				char charInChar = nextChar;
				theComment << charInChar;
				continue;
			}
			char charDataTypeOfNextChar = nextChar;
			theComment << charDataTypeOfNextChar;
		}
		
		return -1;
	}
	else {
		theComment << "#";
		while (true) {
			nextChar = toScan.get();
			if (nextChar == -1 || nextChar == '\n') {
				//end of comment
				Token* toAppend = new Token(TokenTypes::COMMENT, theComment.str(), lineNum);
				tokens.push_back(toAppend);
				return lineNum + 1;

			}
			else {
				char nextCharInChar = nextChar;
				theComment << nextCharInChar;
			}

		}
		return lineNum;
	}
	return -1;
}

void Scanner::createUndefinedToken(char currChar, int lineNum){
	stringstream toUseAsString;
	toUseAsString << currChar;
	Token* toAppend = new Token(TokenTypes::UNDEFINED, toUseAsString.str(), lineNum);
	tokens.push_back(toAppend);
	return;
}











void Scanner::createSingleCharToken(int toAppend, int lineNum) {
	char charToAppend = toAppend;
	Token* toAddToVector = nullptr;
	

	switch (charToAppend) {
	case'.':
		toAddToVector = new Token(TokenTypes::PERIOD, ".", lineNum);
		tokens.push_back(toAddToVector);
		return;

	case',':
		toAddToVector = new Token(TokenTypes::COMMA, ",", lineNum);
		tokens.push_back(toAddToVector);
		return;
	case'?':
		toAddToVector = new Token(TokenTypes::Q_MARK, "?", lineNum);
		tokens.push_back(toAddToVector);
		return;
	case'(':
		toAddToVector = new Token(TokenTypes::LEFT_PAREN, "(", lineNum);
		tokens.push_back(toAddToVector);
		return;
	case')':
		toAddToVector = new Token(TokenTypes::RIGHT_PAREN, ")", lineNum);
		tokens.push_back(toAddToVector);
		return;
	case'*':
		 toAddToVector= new Token(TokenTypes::MULTIPLY, "*", lineNum);
		tokens.push_back(toAddToVector);
		return;
	case'+':
		toAddToVector = new Token(TokenTypes::ADD, "+", lineNum);
		tokens.push_back(toAddToVector);
		return;
	default:
		cerr << "This function was called in error";
		return;

	}

}


