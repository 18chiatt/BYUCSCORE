#ifndef TOKEN_H
#define TOKEN_H
#include<iostream>
#include<string>
#include"TokenTypes.h"
#include<map>
using namespace std;


class Token {
public:
	Token(TokenTypes theType, string value, int LineNum);
	Token(void);
	string toString(void);
private:
	void populateMap(void);
	TokenTypes theType;
	int lineNumber;
	string value;
	map<TokenTypes, string> convertTypeToString;





};

#endif // !TOKEN_H