#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include<string>
using namespace std;


char getSymbol(int toConvert) {
 if (toConvert == 0) {
	 return '_';
 }

 if (toConvert == 1) {
	 return 'X';
 }

}

//{ OPEN0, BLOCKED1, PATH2, EXIT3, TEMPORARY4 , LEFT5 , RIGHT6, UP 7, DOWN8, OUT9, IN 10, ALREADYTRIED}
string getCharToAppend(int toConvert) {
	if (toConvert == 0) {
		return "_";
	}
	

	if (toConvert == 3) {
		return "E";
	}

	if (toConvert == 4) {
		
		return "_";
	}

	if (toConvert == 11) {
		return "_";
	}

	if (toConvert == 5) {
		return "L";
	}

	if (toConvert == 6) {
		return "R";
	}
	if (toConvert == 7) {
		return "U";
	}

	if (toConvert == 8) {
		return "D";
	}

	if (toConvert == 9) {
		return "O";
	}

	if (toConvert == 10) {
		return "I";
	}


	return "X";

}


#endif // !HELPER_FUNCTIONS_H
