#include "token.h"
#include<string>
#include<sstream>
#include<map>
#include<iostream>
#include"TokenTypes.h"
using namespace std;
Token::Token(TokenTypes theType, string value, int lineNum){
	this->theType = theType;
	this->value = value;
	this->lineNumber = lineNum;
	this->populateMap();
	return;

}

Token::Token(void){
	this->populateMap();

}

string Token::toString(void){
	stringstream toReturn;
	toReturn << "(";
	toReturn << convertTypeToString[theType];
	toReturn << ",\"" << value << "\"," << lineNumber << ")";
	return toReturn.str();

}

void Token::populateMap(void){
	//enum TokenTypes {COMMA,PERIOD,Q_MARK,LEFT_PAREN,RIGHT_PAREN,COLON,COLON_DASH,MULTIPLY,ADD,SCHEMES,FACTS,RULES,QUERIES,ID,STRING,COMMENT,UNDEFINED, END_OF_FILE };
	convertTypeToString[TokenTypes::COMMA] = "COMMA";
	convertTypeToString[TokenTypes::PERIOD] = "PERIOD";
	convertTypeToString[TokenTypes::Q_MARK] = "Q_MARK";
	convertTypeToString[TokenTypes::LEFT_PAREN] = "LEFT_PAREN";
	convertTypeToString[TokenTypes::RIGHT_PAREN] = "RIGHT_PAREN";
	convertTypeToString[TokenTypes::COLON] = "COLON";
	convertTypeToString[TokenTypes::COLON_DASH] = "COLON_DASH";
	convertTypeToString[TokenTypes::MULTIPLY] = "MULTIPLY";
	convertTypeToString[TokenTypes::ADD] = "ADD";
	convertTypeToString[TokenTypes::SCHEMES] = "SCHEMES";
	convertTypeToString[TokenTypes::FACTS] = "FACTS";
	convertTypeToString[TokenTypes::RULES] = "RULES";
	convertTypeToString[TokenTypes::QUERIES] = "QUERIES";
	convertTypeToString[TokenTypes::ID] = "ID";
	convertTypeToString[TokenTypes::STRING] = "STRING";
	convertTypeToString[TokenTypes::COMMENT] = "COMMENT";
	convertTypeToString[TokenTypes::UNDEFINED] = "UNDEFINED";
	convertTypeToString[TokenTypes::END_OF_FILE] = "EOF";

	

	return;


}
