#ifndef TRAIN_STATION_H
#define TRAIN_STATION_H

#include"Deque.h"
#include"Vector.h"
#include"Queue.h"
#include"Stack.h"
#include<string>
using namespace std;


class TrainStation {
private:
	Deque<unsigned int> turnTable;
	Stack<unsigned int> stack;
	Queue<unsigned int> queue;
	Vector<unsigned int> vector;
public:
	string addToStationTurntable(unsigned int toAdd) {
		if (turnTable.empty()) {
			turnTable.push_back(toAdd);
			return "OK";
		}
		return "Turntable occupied!";
	}

	string addToQueue(void) {
		if (turnTable.empty()) {
			return "Turntable empty!";
		}
		unsigned int toAddToQueue = turnTable.front();
		turnTable.pop_front();
		queue.push(toAddToQueue);
		return "OK";
	}

	string addToStack(void) {
		if (turnTable.empty()) {
			return "Turntable empty!";
		}
		unsigned int toAdd = turnTable.front();
		turnTable.pop_back();
		stack.push(toAdd);
		return "OK";
	}

	string RemoveFromTurntable(void) {
		if (turnTable.empty()) {
			return "Turntable empty!";
		}
		unsigned int toMoveToVector = turnTable.front();
		turnTable.pop_back();
		vector.push_back(toMoveToVector);
		return "OK";
	}

	string removeFromQueue(void) {
		if (queue.isEmpty()) {
			return "Queue empty!";
		}
		if (!turnTable.empty()) {
			return "Turntable occupied!";
		}
		unsigned int toAddToVector = queue.front();
		queue.pop();
		turnTable.push_back(toAddToVector);
		return "OK";
	}

	string removeFromStack(void) {
		if (stack.isEmpty()) {
			return "Stack empty!";
		}

		if (!turnTable.empty()) {
			return "Turntable occupied!";
		}
		unsigned int toAddToVector = stack.top();
		stack.pop();
		turnTable.push_back(toAddToVector);
		return "OK";
	}

	string topOfTurntable(void) {
		if (turnTable.empty()) {
			return "Turntable empty!";
		}
		return to_string(turnTable.front());
	}

	string topOfQueue(void) {
		if (queue.isEmpty()) {
			return "Queue empty!";
		}
		return to_string(queue.front());
	}

	string topOfStack(void) {
		if (stack.isEmpty()) {
			return "Stack empty!";
		}
		return to_string(stack.top());
	}

	string sizeOfQueue(void) {
		return to_string(queue.size());
	}

	string sizeOfStack(void) {
		return to_string(stack.size());
	}

	string outputVector(void) {
		ostringstream toReturn;
		for (int i = 0; i < vector.size(); i++) {
			toReturn << " " << to_string(vector.at(i));
		}
		return toReturn.str();
	}

	string find(unsigned int toFind) {
		if (turnTable.front() == toFind) {
			return "Turntable";
		}

		//search queue
		for (int i = 0; i < queue.size(); i++) {
			if (queue.at(i) == toFind) {
				return "Queue[" + to_string(i) + "]";
			}
		}


		//search stack
		for (int i = 0; i < stack.size(); i++) {
			if (stack.at(i) == toFind) {
				return "Stack[" + to_string(i) + "]";
			}
		}

		//search vector

		for (int i = 0; i < vector.size(); i++) {
			if (vector.at(i) == toFind) {
				return "Train[" + to_string(i) + "]";
			}
		}

		return "Not Found!";

	}

};



#endif // !TRAIN_STATION_H
