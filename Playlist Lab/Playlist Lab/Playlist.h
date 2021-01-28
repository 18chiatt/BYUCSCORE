#pragma once
#include "Song.h"
#include<vector>
#include<string>

#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist {
public:
	void AddSong(Song *songToAdd);
	void PlayPlaylist();
	Playlist(string nameOfPlaylist = "Default Name");	
	string GetName();
	int GetLength();
	void OutputAllSongs();
	string* GetSongFingerprint(int indexToCheck);
	void RemoveSong(int indexToRemove);
	Song* GetSongAtIndex(int indexToGet);
	string GetSongName(int indexToGet);

	



private:
	string nameOfPlaylist;
	vector<Song*> songsOnList;
};



#endif