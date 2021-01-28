#include<string>
#include<iostream>
#include "Set.h"
#include "HashMapInterface.h"
#include"HashMap.h"
#include<utility>
#include<fstream>


int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << "You're an idiot, more args please"; //berate the user for their incompetence
		return 1;
	}
	ofstream output;
	output.open(argv[2]);

	Set<string> mySet;
	HashMap<string, string> pokemon;
	HashMap<string, string> moves;
	HashMap<string, Set<string>> effectivities;
	HashMap<string, Set<string>> ineffectivities;

	ifstream input;
	input.open(argv[1]);
	string lineToProcess = "";
	while (getline(input, lineToProcess)) {
		output << lineToProcess;

		stringstream toProcess(lineToProcess);
		string command;
		toProcess >> command;
		if (command == "Set:") {
			output << endl;
			mySet.clear(); //clear set to ensure consistent results
			
			while (toProcess.eof() == false) {
				string toInsert;
				toProcess >> toInsert;
				mySet.insert(toInsert);
			}
			output << "  " <<"[" << mySet << "]" << endl;

		}

		if (command == "Pokemon:") {
			string pokemonName;
			string pokemonType;

			toProcess >> pokemonName;
			toProcess >> pokemonType;

			pokemon[pokemonName] = pokemonType; //add pokemon to pokedex

		}

		if (command == "Pokemon") {
			output <<  ":" << pokemon; //use friend insertion operator to output pokemon
		}

		if (command == "Move:") {
			string moveName;
			string moveType;
			toProcess >> moveName;
			toProcess >> moveType;

			moves[moveName] = moveType; //add move to move-dex

		}

		if (command == "Moves") {
			output << ":" << moves; //use friend insertion operator
		}

		if (command == "Effective:") {
			string attackType;
			toProcess >> attackType;

			while (toProcess.eof() == false) {
				string effectiveAgainst;
				toProcess >> effectiveAgainst;

				effectivities[attackType].insert(effectiveAgainst); //read in all
			}

		}

		if (command == "Ineffective:") {
			string attackType;
			toProcess >> attackType;

			while (toProcess.eof() == false) {
				string ineffectiveAgainst;
				toProcess >> ineffectiveAgainst;
				ineffectivities[attackType].insert(ineffectiveAgainst); //add each ineffectivity one at a time
			}

		}

		if (command == "Effectivities") {

			output << ":" << effectivities;
		}

		if (command == "Ineffectivities") {
			output << ":" << ineffectivities;
		}

		if (command == "Battle:") { //this code is quite heafty, it's just output statements, nothing much to it
			string firstPokemonName;
			string firstPokemonMove;
			string secondPokemonName;
			string secondPokemonMove;

			toProcess >> firstPokemonName;
			toProcess >> firstPokemonMove;
			toProcess >> secondPokemonName;
			toProcess >> secondPokemonMove;
			int damageFirstToSecond = effectivities[moves[firstPokemonMove]].count(pokemon[secondPokemonName])
				- ineffectivities[moves[firstPokemonMove]].count(pokemon[secondPokemonName]);

			int damageSecondToFirst = effectivities[moves[secondPokemonMove]].count(pokemon[firstPokemonName])
				- ineffectivities[moves[secondPokemonMove]].count(pokemon[firstPokemonName]);
			output << endl << "  " << firstPokemonName << " (" << firstPokemonMove << ") vs " << secondPokemonName << " (" << secondPokemonMove << ")" << endl;
		

			output << "  " << firstPokemonName << " is a " << pokemon[firstPokemonName] << " type Pokemon." << endl;
			output << "  " <<  secondPokemonName << " is a " << pokemon[secondPokemonName] << " type Pokemon." << endl;
			output << "  " << firstPokemonMove << " is a " << moves[firstPokemonMove] << " type move." << endl;
			output << "  " << secondPokemonMove << " is a " << moves[secondPokemonMove] << " type move." << endl;
			//first pokemon
			output << "  " << firstPokemonMove << " is super effective against [" << effectivities[moves[firstPokemonMove]] << "] type Pokemon." << endl;
			output << "  " << firstPokemonMove << " is ineffective against [" << ineffectivities[moves[firstPokemonMove]] << "] type Pokemon." << endl;
			output << "  " << firstPokemonName << "'s " << firstPokemonMove << " is ";

			if (effectivities[moves[firstPokemonMove]].count(pokemon[secondPokemonName]) == 1) {
				output << "super effective";
			}
			else if (ineffectivities[moves[firstPokemonMove]].count(pokemon[secondPokemonName] )== 1) {
				output << "ineffective";
			}
			else {
				output << "effective";
			}
			output << " against " << secondPokemonName << endl;
			//finished with first pokemon	
			output << "  " << secondPokemonMove << " is super effective against [" << effectivities[moves[secondPokemonMove]] << "] type Pokemon." << endl;
			output << "  " << secondPokemonMove << " is ineffective against [" << ineffectivities[moves[secondPokemonMove]] << "] type Pokemon." << endl;
			output << "  " << secondPokemonName << "'s " << secondPokemonMove << " is ";

			if (damageSecondToFirst == 1) {
				output << "super effective";
			}
			else if (damageSecondToFirst == 0) {
				output << "effective";
			}
			else {
				output << "ineffective";
			}
			output << " against " << firstPokemonName << endl;

			if (damageFirstToSecond == damageSecondToFirst) {
				output << "  The battle between " << firstPokemonName << " and " << secondPokemonName << " is a tie." << endl;
			}
			else {
				output << "  In the battle between " << firstPokemonName << " and " << secondPokemonName << ", ";
				if (damageFirstToSecond > damageSecondToFirst) {
					output << firstPokemonName;

				}
				else { //this outputs the name of the winning pokemon in the event of a non-tie
					output << secondPokemonName;
				}

				output << " wins!" << endl;

			}
			


		}


		output << endl;
	}
	

	return 0;
}

