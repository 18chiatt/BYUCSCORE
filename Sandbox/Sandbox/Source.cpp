#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

	string string1;
	string stringYN;
	string stringYN2;
	string textInsert;
	int textPosition;
	string stringFindCopy;
	string substringToFind;
	string stringFDR;
	string replacementString;
	int stringCopyLength;
	int pastePosition;

	cout << "Welcome to the Simple Editor. Enter a string to be edited: " << endl;
	getline(cin, string1);
	cout << string1 << endl;

	cout << "Do you want to make this string a sentence (y/n)?" << endl;
	cin >> stringYN;
	cin.ignore();

	if (stringYN.at(0) == 'y') {
		string1.at(0) = toupper(string1.at(0));

		if ((string1.find('.') == string::npos) && (string1.find('?') == string::npos) && (string1.find('!') == string::npos)) {
			string1.push_back('.');
		}
		cout << string1 << endl;
	}

	cout << "Do you want to insert more text into your current text (y/n)?" << endl;
	cin >> stringYN;
	cin.ignore();

	if (stringYN.at(0) == 'y') {
		cout << "Enter text to be inserted: " << endl;
		getline(cin, textInsert);
		cout << "Enter position where text is to be inserted: " << endl;
		cin >> textPosition;
		cin.ignore();
		if ((textPosition >= 0) && (textPosition <= string1.length())) {
			cout << string1.insert(textPosition, textInsert) << endl;
		}
		else {
			cout << "No change made. Position must be non-negative and not exceed " << string1.length() << ", the length of the current text." << endl;
		}
	}

	cout << "If you would like to find/replace or copy/paste, enter find or copy: " << endl;
	cin >> stringFindCopy;
	cin.ignore();

	if (stringFindCopy.at(0) == 'f') {
		cout << "Enter substring to find: " << endl;
		getline(cin, substringToFind);
		cout << "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?" << endl;
		cin >> stringFDR;
		cin.ignore();
		if (stringFDR.at(0) == 'f') {
			if (string1.find(substringToFind) != string::npos) {
				cout << substringToFind << " was found at position " << string1.find(substringToFind) << "." << endl;
			}
			else if (string1.find(substringToFind) == string::npos) {
				cout << substringToFind << " was not found." << endl;
			}
		}
		else if (stringFDR.at(0) == 'd') {
			if (string1.find(substringToFind) != string::npos) {
				string1.replace(string1.find(substringToFind), substringToFind.length(), "");
			}
			else {
				cout << substringToFind << " was not found. No change made." << endl;
			}
		}
		else if (stringFDR.at(0) == 'r') {
			if (string1.find(substringToFind) == string::npos) {
				cout << substringToFind << " was not found. No change made." << endl;
			}
			else {
				cout << "Enter replacement string: " << endl;
				getline(cin, replacementString);
				string1.replace(string1.find(substringToFind), substringToFind.length(), replacementString);
			}
		}
	}

	else if (stringFindCopy.at(0) = 'c') {
		cout << "Enter position and length of text to be copied, and position for paste: " << endl;
		cin >> textPosition;
		cin >> stringCopyLength;
		cin >> pastePosition;
		if ((textPosition >= 0) && (textPosition < string1.length()) && (stringCopyLength > 0) && (stringCopyLength < (string1.length() - textPosition)) && (pastePosition >= 0) && (pastePosition < string1.length())) {
			string1.insert(textPosition, string1.substr(textPosition, stringCopyLength));
		}
		else {
			cout << "Values entered do not support copy/paste." << endl;
		}
	}

	cout << "Final text is " << endl;
	cout << string1;

	return 0;
}