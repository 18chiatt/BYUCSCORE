#include <iostream>
// FIXME include vector library
#include<vector>

using namespace std;



void outputMenu() {

	cout << "MENU" << endl;
	cout << "a - Add player" << endl;
	cout << "d - Remove player" << endl;
	cout << "u - Update player rating" << endl;
	cout << "r - Output players above a rating" << endl;
	cout << "o - Output roster" << endl;
	cout << "q - Quit"<< endl << endl;
	cout << "Choose an option: ";


}

int main() {

	vector<int> jerseyNumbers(5);
	vector<int> playerRatings(5);

	for (int i = 0; i < 5; ++i) {
		cout << "Enter player " << i + 1 << "'s jersey number: ";
		cin >> jerseyNumbers.at(i);
		cout << endl <<  "Enter player " << i + 1 << "'s rating: ";
		cin >> playerRatings.at(i);


	}
	cout << endl;
	// roster
	cout << "ROSTER" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << playerRatings.at(i) << endl;

	}
	char userInput = 'c';
	while (true) { //loop body
		
		cin >> userInput;

		if (userInput == 'q') {
			outputMenu();
			return 0;
		}
		if (userInput == 'o') {
			cout << "ROSTER" << endl;
			for (int i = 0; i < jerseyNumbers.size(); ++i) {
				// output roster
				cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << playerRatings.at(i) << endl;;

			}
		}
		if (userInput == 'a') {
			//add player
			cout << "Enter another player's jersey number: ";
			jerseyNumbers.resize(jerseyNumbers.size() + 1);
			cin >> jerseyNumbers.at(jerseyNumbers.size() - 1);
			cout << endl << "Enter another player's rating: ";
			playerRatings.resize(playerRatings.size() + 1);
			cin >> playerRatings.at(playerRatings.size() - 1);
			cout << endl;
			outputMenu();

		}
		if (userInput == 'd') {
			//delete player
			int jerseyToDelete = -1;
			cout << "Enter a jersey number: ";
			cin >> jerseyToDelete;

			//find index
			int indexToDelete = -1;

			for (int i = 0; i < jerseyNumbers.size(); ++i) {
				if (jerseyNumbers.at(i) == jerseyToDelete) {
					indexToDelete = i;
				}
			}
			//delete index
			jerseyNumbers.erase(jerseyNumbers.begin() + indexToDelete);
			playerRatings.erase(playerRatings.begin() + indexToDelete);
			outputMenu();
			
		}
		if(userInput == 'u'){// update
			int jerseyToUpdate = -1;
			int newRating = -1;
			cout << "Enter a jersey number : ";
			cin >> jerseyToUpdate;
			cout << endl << "Enter a new rating for player: ";
			cin >> newRating;

			int indexToChange = -1;

			for (int i = 0; i < jerseyNumbers.size(); ++i) {
				if (jerseyToUpdate == jerseyNumbers.at(i)) {
					indexToChange = i;

				}


			}
			playerRatings.at(indexToChange) = newRating;

			outputMenu();


		
		}// end user update

		if(userInput == 'r'){//begin output above certain rating
			cout << "Enter a rating: ";
			int filterRating = -1;
			cin >> filterRating;
			cout << endl;
			cout << endl;
			cout << "ABOVE " << filterRating << endl;

			for (int i = 0; i < jerseyNumbers.size(); ++i) {
				if (playerRatings.at(i) > filterRating) {
					cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << playerRatings.at(i) << endl;
				}

			}
		
		} // end output above certain rating

		
	}




	return 0;
}