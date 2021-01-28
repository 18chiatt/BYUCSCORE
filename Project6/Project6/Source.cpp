#include<iostream>
#include<vector>
#include<string>

using namespace std;
void OutputVector(vector<string> wordSearch);

class CoordinatePair
{
public:
	int wordLocation;
	int letterLocation;
	bool hasOffset;
	int yOffset;
	int xOffset;

	CoordinatePair(int wordLocation, int letterLocation) {
		this->letterLocation = letterLocation;
		this->wordLocation = wordLocation;
		hasOffset = false;

	}
	CoordinatePair(int wordLocation, int letterLocation, int yOffset, int xOffset) {
		this->letterLocation = letterLocation;
		this->wordLocation = wordLocation;
		hasOffset = true;
		this->yOffset = yOffset;
		this->xOffset = xOffset;

	}


};

int main() {
	vector<string> wordSearch;
	vector<CoordinatePair> instancesOfLetter;
	vector<CoordinatePair> instancesOfNextLetter;
	string userInput = " ";
	int currLineNumber = 0;
	string END_IT_ALL = "-1";
	bool doneWithSearch = false;


	cout << "Welcome to the word search solver\n";
	cout << "Please enter each line of the puzzle to begin\n";
	cout << "Enter \"" + END_IT_ALL	+ "\" to end entry of lines\n";

	while (true) {
		cout << "Please Enter the number " + to_string(currLineNumber+1) + " line of the puzzle: ";
		getline(cin, userInput);

		//test if USERiNPUT is ENDITALL
		if (userInput == END_IT_ALL) {
			break;

		}
		// ensure consistent length

		if (currLineNumber > 0) {
			if (wordSearch.at(currLineNumber - 1).length() != userInput.length()) {
				cout << "Sorry, we found that your inputs weren't of consisentent length this program won't work";
				system("Pause");

			}

		}

		//all checks on data complete, push back the vector with the new string
		wordSearch.push_back(userInput);
		currLineNumber++;
	}

	cout << "ENTRY COMPLETE\n";
	OutputVector(wordSearch);



	while (true) { // search for a word
		cout << "Enter the word you would like to find: ";
		getline(cin, userInput);
		

		if (userInput == END_IT_ALL) {
			break;
		}
		//get first leter and find instances
		char userLetter = userInput.at(0);


		for (int i = 0; i < wordSearch.size(); i++) { // for each word
			for (int j = 0; j < wordSearch.at(i).length(); j++) { // for each letter
				if (wordSearch.at(i).at(j) == userLetter) {
					//found something that equals user Letter
					CoordinatePair newPair(i, j);
					instancesOfLetter.push_back(newPair); // make a list of all initial letters


				}

			}
		} // end of initial scan of letters

		int lettersChecked = 1;

		while (lettersChecked < userInput.size()) {
			char nextLetter = userInput.at(lettersChecked);
			//check for the next letter
			for (int i = 0; i < instancesOfLetter.size(); i++) {0
				if (instancesOfLetter.at(i).hasOffset == true) {
					// only check the offset
					if (wordSearch.at(instancesOfLetter.at(i).wordLocation + instancesOfLetter.at(i).yOffset).at(instancesOfLetter.at(i).letterLocation + instancesOfLetter.at(i).xOffset) == nextLetter) {
						CoordinatePair match(instancesOfLetter.at(i).wordLocation + instancesOfLetter.at(i).yOffset, instancesOfLetter.at(i).letterLocation + instancesOfLetter.at(i).xOffset, instancesOfLetter.at(i).yOffset, instancesOfLetter.at(i).xOffset);
						instancesOfNextLetter.push_back(match);

					}


				}
				else {
					// check all surrounding letters
					for (int xOffsetCheck = -1; xOffsetCheck < 2; xOffsetCheck++) {
						for (int yOffsetCheck = -1; yOffsetCheck < 2; yOffsetCheck++) {
							//check the current square for being 0,0 and see if there is a match for the next letter
							if (xOffsetCheck == 0 && yOffsetCheck == 0) {
								continue;
							}

							if (instancesOfLetter.at(i).wordLocation == 0 && yOffsetCheck == -1) {
								continue;

							}

							if (instancesOfLetter.at(i).wordLocation == wordSearch.size() && yOffsetCheck == 1) {
								continue;

							}

							if (instancesOfLetter.at(i).letterLocation == 0 && xOffsetCheck == -1) {
								continue;
							}
							if (instancesOfLetter.at(i).letterLocation == wordSearch.at(0).length() && xOffsetCheck == 1) {
								continue;
							}
							if (instancesOfLetter.at(i).wordLocation == wordSearch.size()-1 && yOffsetCheck == 1) {
								continue;

							}


							//not 00

							//cout << "Word Location is " << to_string(instancesOfLetter.at(i).wordLocation) << endl;
							//cout << "Word Offset to check is " << yOffsetCheck << endl;
							//cout << "letter location is " << to_string(instancesOfLetter.at(i).letterLocation) << endl;
							//cout << "offset to check is " << xOffsetCheck << endl;

							if (wordSearch.at(instancesOfLetter.at(i).wordLocation + yOffsetCheck).at(instancesOfLetter.at(i).letterLocation+xOffsetCheck) == nextLetter) {
								CoordinatePair match(instancesOfLetter.at(i).wordLocation + yOffsetCheck, instancesOfLetter.at(i).letterLocation + xOffsetCheck, yOffsetCheck, xOffsetCheck);
								instancesOfNextLetter.push_back(match);
								

							}


						}


					}


				}

				


			}
			// done searching

			instancesOfLetter.clear();
			for (int i = 0; i < instancesOfNextLetter.size(); i++) {

				instancesOfLetter.push_back(instancesOfNextLetter.at(i));
			}
			instancesOfNextLetter.clear();
			lettersChecked++;
		}

		if (instancesOfLetter.size() != 0) {
			// found a match??????

			cout << "WE FOUND A MATCH" << endl;
			//follow match back up to source, output.

			//FIXME only assuming one match

			int finalLetterWordLocation = instancesOfLetter.at(0).wordLocation;
			int finalLetterLetterLocation = instancesOfLetter.at(0).letterLocation;





		}




	} // -- end of search loop
	


	







	system("Pause");
}


void OutputVector(vector<string> wordSearch) {
	cout << "This should be the data you entered\n";

	for (int i = 0; i < wordSearch.size(); i++) {
		cout << wordSearch.at(i) << endl;


	}
	cout << endl;

}