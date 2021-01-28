#include "Playlist.h"

void Playlist::AddSong(Song * songToAdd)
{
	songsOnList.push_back(songToAdd);
}

void Playlist::PlayPlaylist(){
	for (int i = 0; i < songsOnList.size(); i++) {
		songsOnList.at(i)->PlaySong();
	}
}

Playlist::Playlist(string nameOfPlaylist){
	this->nameOfPlaylist = nameOfPlaylist;
}

string Playlist::GetName(){
	return nameOfPlaylist;
}

int Playlist::GetLength(){
	return songsOnList.size();
}

void Playlist::OutputAllSongs(){
	for (int i = 0; i < songsOnList.size(); i++) {
		cout << i << ": " << songsOnList.at(i)->GetName() << endl;
	}
}

string * Playlist::GetSongFingerprint(int indexToCheck){
	return songsOnList.at(indexToCheck)->GetFingerPrint();
}

void Playlist::RemoveSong(int indexToRemove){
	songsOnList.erase(songsOnList.begin() + indexToRemove);
}

Song * Playlist::GetSongAtIndex(int indexToGet){
	return songsOnList.at(indexToGet);
}

string Playlist::GetSongName(int indexToGet){
	return songsOnList.at(indexToGet)->GetName();
}


