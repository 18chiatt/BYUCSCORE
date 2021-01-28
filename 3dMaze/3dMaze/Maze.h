#ifndef MAZE_H
#define MAZE_H
#include"MazeInterface.h"
#include"HelperFunctions.h"
#include<cstdbool>
#include<iostream>
#include<fstream>
#include<istream>
#include<sstream>
#define currSpot height, width, depth
#define left height, width-1, depth
#define right height , width+1, depth


#define up height-1, width, depth
#define down height+1, width , depth

#define out height, width, depth-1
#define inMaze height, width , depth+1

using namespace std;
enum CellValue { OPEN, BLOCKED, PATH, EXIT, TEMPORARY , LEFT , RIGHT, UP , DOWN, OUT, IN, ALREADYTRIED};

class Maze : public MazeInterface {
private:
	int ***theMaze;
	int width;
	int height;
	int depth;

public:
	void createMaze(void) {


		theMaze = new int **[height];

		for (int i = 0; i < height; i++) {
			theMaze[i] = new int*[width];
			for (int j = 0; j < width; j++) {
				theMaze[i][j] = new int[depth];
			}
		}

	}

	Maze(void) {
		return;
	}

	void test() {
		if (theMaze[0][0][0] == OPEN) {
			cout << "OPEN!";
		}
		else {
			cout << "closed!";

			cout << theMaze[0][0][0];
		}

	}

	void populate(ifstream & input) {
		input >> this->height;
		input >> this->width;
		input >> this->depth;

		this->createMaze();
		for (int d = 0; d < depth; d++) {
			//for each depth

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {


					input >> theMaze[i][j][d];



				}

			}
		}


	}

	

	bool find_maze_path(void) {
		if (this->find_maze_path(0, 0, 0)) {
			return true;

			
		}
		return false;

	}

	bool find_maze_path(int height, int width, int depth) {		
		
		if ((height < 0) || (height == this->height)) {
			return false;

		}

		if ((width < 0) || (width == this->width)) {
			return false;
		}

		if ((depth < 0) || (depth == this->depth)) {
			return false;
		}

		if (theMaze[height][width][depth] != OPEN) {
			return false;
		}
		

		if ((depth == this->depth - 1) && (height == this->height - 1) && (width == this->width - 1)) {
			this->setValue(currSpot, EXIT);
			return true;
		}
		

		this->setValue(currSpot, TEMPORARY);

		if (find_maze_path(left)) {
			this->setValue(currSpot, LEFT);
			
			return true;
		}

		if (find_maze_path(right)) {
			this->setValue(currSpot, RIGHT);
			return true;
		}

		if (find_maze_path(up)) {
			this->setValue(currSpot, UP);
			return true;
		}

		if (find_maze_path(down)) {
			this->setValue(currSpot, DOWN);
			return true;
		}

		if (find_maze_path(out)) {
			this->setValue(currSpot, OUT);
			return true;
		}

		if (find_maze_path(inMaze)) {
			this->setValue(currSpot, IN);
			return true;
		}

		//we didn't find a solution along this path

		this->setValue(currSpot, ALREADYTRIED);
		return false;

		
	}

	string toString() const {
		//output maze
		ostringstream output;
		for (int d = 0; d < depth; d++) {
			output << "Layer " << d + 1 << endl;

			for (int i = 0; i < height; i++) {

				for (int w = 0; w < width; w++) {
					char toInsert = getSymbol(theMaze[i][w][d]);
					output << " " << toInsert;
				}
				output << endl;
			}

		}

		output << endl;

		return output.str();
	}






	Maze(int height, int width, int depth) {
		this->width = width;
		this->height = height;
		this->depth = depth;

		this->createMaze();
		return;
	}

	~Maze(void) {		
		this->clearData();
		return;		
	}

	void clearData(void) {
		if (theMaze == nullptr) {
			return;
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				delete[] theMaze[i][j];
			}
			
		}
		for (int i = 0; i < height; i++) {
			delete[] theMaze[i];
		}

		delete[] theMaze;
		return;

		this->height = 0;
		this->width = 0;
		this->depth = 0;
	}


	

	void setValue(int height, int width, int layer, int value) {
		//check if it is in bounds
		if (height > this->height - 1 || height < 0) {
			cerr << "OUT OF BOUNDS HEIGHT";
			return;
		}

		if (width > this->width - 1 || width < 0) {
			cerr << "OUT OF BOUNDS WIDTH!";
			return;
		}

		if (layer > depth - 1 || layer < 0) {
			cerr << "OUT OF BOUDS LAYER!";
			return;
		}

		theMaze[height][width][layer] = value;
		return;
	}

	string getSolvedMaze(void) {
		ostringstream output;
		output << endl;
		for (int d = 0; d < this->depth; d++) {
			output << "Layer " << d + 1 << endl;

			for (int h = 0; h < height; h++) {
				for (int w = 0; w < width; w++) {
					string toAppend = getCharToAppend(theMaze[h][w][d]);
					output << " " << toAppend;
				}
				output << endl;
			}
		}

		string toReturn = output.str().substr(0, output.str().length() - 1); //remove trailining endl

		return toReturn;





	}



};



#endif // !MAZE_H
