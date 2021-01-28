#include <iostream>
#include<string>
#include<vector>
#include"Song.h"
#include"Playlist.h"
using namespace std;
const string ADD_OPTION = "add";
const string LIST_OPTION = "list";
const string ADD_PLAYLIST_OPTION = "addp";
const string ADD_SONG_TO_PLAYLIST = "addsp";
const string LIST_PLAYLIST = "listp";
const string PLAY_OPTION = "play";
const string DELETE_PLAYLIST = "delp";
const string DELETE_SONG_FROM_PLAYLIST = "delsp";
const string DELETE_SONG_FROM_LIBRARY = "delsl";
const string OPTIONS_MENU = "options";
const string QUIT_PROGRAM = "quit";
const string FINISHED_ENTERING_SONGS = "STOP";

//function decleration

void OutputMenu();
string GetUserChoice();


int main() {
	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
	vector<Song*> songLibrary;
	vector<Playlist> playlists;
	string userChoice = "lul, this is super epic";


	while (true) {
		string userChoice = GetUserChoice();
		if (userChoice == QUIT_PROGRAM) {
			break;
		}
		

		if (userChoice == ADD_OPTION) {
			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
			while (true) {
				Song* songToAdd;
				string songName;
				string firstLine;
				cout << "Song Name: ";
				getline(cin, songName);
				if (songName == FINISHED_ENTERING_SONGS) {
					break;
				}
				cout << "Song's first line: ";
				getline(cin, firstLine);
				songToAdd = new Song(songName, firstLine);
				songLibrary.push_back(songToAdd);

				string testString = songLibrary.at(0)->GetFirstLine();


				


			}
			continue;
		} // end add

		if (userChoice == LIST_OPTION) {
			for (int i = 0; i < songLibrary.size(); i++) {
				cout << songLibrary.at(i)->GetName() << ": \"" << songLibrary.at(i)->GetFirstLine() << "\", " << songLibrary.at(i)->GetTimesPlayed() << " play(s)." << endl;
			}
			cout << endl;
			continue;
		} // end list songs

		if (userChoice == ADD_PLAYLIST_OPTION) {
			string playListName = "lul";
			cout << "Playlist name: ";
			getline(cin, playListName);
			Playlist newPlaylist(playListName);
			playlists.push_back(newPlaylist);
			cout << endl << endl;
			continue;
		} // end add playlist

		if (userChoice == LIST_PLAYLIST) {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			continue;
		} // end list playlists
		if (userChoice == PLAY_OPTION) {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number: ";
			int playListToPlay = -1;
			cin >> playListToPlay;
			cout << endl;
			cin.ignore();
			cout << endl << endl;
			cout << "Playing first lines of playlist: " << playlists.at(playListToPlay).GetName() << endl;
			playlists.at(playListToPlay).PlayPlaylist();
			cout << endl;
			continue;
		} // end play options

		if (userChoice == ADD_SONG_TO_PLAYLIST) {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number: ";
			int playlistToAddTo = -1;
			cin >> playlistToAddTo;
			cout << endl;
			
			
			for (int i = 0; i < songLibrary.size(); i++) {
				cout << i << ": " << songLibrary.at(i)->GetName() << endl;
			}

			cout << "Pick a song index number: ";
			int songToAdd = -1;
			cin >> songToAdd;
			cout << endl;
			playlists.at(playlistToAddTo).AddSong(songLibrary.at(songToAdd));

			continue;
		} // end add song to playlist

		if (userChoice == DELETE_PLAYLIST) {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
				

			}
			int playlistToDelete = -1;
			cout << "Pick a playlist index number to delete: " << endl;
			cin >> playlistToDelete;
			cout << endl;
			playlists.erase(playlists.begin()+ playlistToDelete);
			continue;
		}

		if (userChoice == DELETE_SONG_FROM_LIBRARY) {
			for (int i = 0; i < songLibrary.size(); i++) {
				cout << i << ": " << songLibrary.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: ";
			int songToErase = -1;
			cin >> songToErase;
			cout << endl;
			for (int i = 0; i < playlists.size(); i++) {
				for (int j = 0; j < playlists.at(i).GetLength(); j++) {
					if (songLibrary.at(songToErase) == playlists.at(i).GetSongAtIndex(j)) {
						//cout << "we found that it matched";  test if we were actually corectly comparing and finding.
						playlists.at(i).RemoveSong(j);
					}
				}
				
			} // removed each instance of song to remove from the playlists. now delete from main list and free up data  DELETING HERE <-------- #FreeTheMemory

			Song* songToDelete = songLibrary.at(songToErase);
			songLibrary.erase(songLibrary.begin() + songToErase);
			delete songToDelete;		
			continue;
		}// end delete song from library

		if (userChoice == DELETE_SONG_FROM_PLAYLIST) {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number: ";
			int playlistToDeleteFrom = -1;
			cin >> playlistToDeleteFrom;
			cout << endl;
			int indexToDelete = -1;
			for (int i = 0; i < playlists.at(playlistToDeleteFrom).GetLength(); i++) {
				cout << i << ": " << playlists.at(playlistToDeleteFrom).GetSongName(i) << endl;
			}
			cout << "Pick a song index number to delete: ";
			cin >> indexToDelete;
			cout << endl;
			playlists.at(playlistToDeleteFrom).RemoveSong(indexToDelete);
			continue;

		}
		OutputMenu();


	}// end main loop
	cout << "Goodbye!";

	for (int i = 0; i < songLibrary.size(); i++) {
		delete songLibrary.at(i);   //                   DELETING ALL SONGS <-------- #FreeTheMemory
	}
	return 0;

} // --------------------------END OF MAIN ------------------------------------------


void OutputMenu() {
	cout << ADD_OPTION<< "      Adds a list of songs to the library" << endl;
	cout << LIST_OPTION << "     Lists all the songs in the library" << endl;
	cout << ADD_PLAYLIST_OPTION << "     Adds a new playlist" << endl;
	cout << ADD_SONG_TO_PLAYLIST << "   Adds a song to a playlist" << endl;
	cout << LIST_PLAYLIST << "   Lists all the playlists" << endl;
	cout << PLAY_OPTION << "     Plays a playlist" << endl;
	cout << DELETE_PLAYLIST << "     Deletes a playlist" << endl;
	cout << DELETE_SONG_FROM_PLAYLIST << "    Deletes a song from a playlist" << endl;
	cout << DELETE_SONG_FROM_LIBRARY << "    Deletes a song from the library (and all playlists)" << endl;
	cout << OPTIONS_MENU << "  Prints this options menu" << endl;
	cout << QUIT_PROGRAM << "     Quits the program" << endl;


}

string GetUserChoice() {
	string userInput;
	cout << endl;
	cout << "Enter your selection now: ";
	cin >> userInput;
	cin.ignore();
	return userInput;

}