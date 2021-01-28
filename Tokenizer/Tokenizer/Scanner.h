#ifndef SCANNER_H
#define SCANNER_H

#include<string>
#include<vector>
#include<fstream>
#include"token.h"
#include<stdbool.h>
#include<map>
#include"TokenTypes.h"
using namespace std;

class Scanner {
public:
	Scanner(string fileName);
	void scan();
	void printTokens(void);
	void clearVector(void);

private:
	void createSingleCharToken(int toAppend, int lineNum);
	bool isSingleCharPunctuation(int toCheck);
	void populateMap(void);
	void createKeywordIdentifierToken(char currChar, int lineNum);
	int createStringToken(char currChar, int lineNum); //returns ending line number
	int createCommentToken(char currChar, int lineNum); //returns final line number
	void createUndefinedToken(char currChar, int lineNum);

	vector<Token*> tokens;
	ifstream toScan;
	map<string, TokenTypes> stringToType;
};

#endif // !SCANNER_H