#include"Maze.h"
#include"MazeInterface.h"
#include<iostream>
#include<fstream>
#include<string>
#include<istream>


using namespace std;

int main(int argc, char* argv[]) {
	ifstream input;
	ofstream output;
	output.open(argv[2]);
	input.open(argv[1], ios_base::in);
	Maze myMaze;
	myMaze.populate(input);

	output << "Solve Maze:" << endl;
	output << myMaze.toString();

	if (myMaze.find_maze_path()) {
		output << "Solution:";
		output << myMaze.getSolvedMaze();
	}
	else {
		output << "No Solution Exists!";
	}
	


	
	return 0;
}
