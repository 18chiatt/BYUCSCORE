#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;

#ifndef SONG_H
#define SONG_H
// code body	

class Song {
public:
	Song(string songName = "default song name", string firstLineOfSong = "default first line of song", int numTimesPlayed = 0);
	void PlaySong();
	string GetName();
	string GetFirstLine();
	int GetTimesPlayed();
	string* GetFingerPrint();
private:
	string songName;
	string firstLineOfSong;
	int timesPlayed;
	string* fingerPrintMemoryAdress;

};




#endif // !SONG_H

