#include "Song.h"






Song::Song(string songName, string firstLineOfSong, int numTimesPlayed)
{
	this->songName = songName;
	this->firstLineOfSong = firstLineOfSong;
	this->timesPlayed = numTimesPlayed;
	fingerPrintMemoryAdress = &songName;
}

void Song::PlaySong(){
	cout << firstLineOfSong << endl;
	timesPlayed++;
}

string Song::GetName(){
	return songName;
}

string Song::GetFirstLine(){
	return firstLineOfSong;
}

int Song::GetTimesPlayed(){
	return timesPlayed;
}

string* Song::GetFingerPrint(){
	return fingerPrintMemoryAdress;
}
