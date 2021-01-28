#ifndef DEQUE_H
#define DEQUE_H
#include"DequeInterface.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;



template <typename T> 
class Deque  {
	T * theData;
	size_t frontIndex;
	size_t rearIndex;
	size_t capacity;
	size_t currElements;

public:
	Deque() {
		theData = new T[DEFAULT_CAPACITY]; //initialize deque to length 5
		frontIndex = 0;
		capacity = DEFAULT_CAPACITY;
		rearIndex = capacity-1;
		currElements = 0;

	}
	~Deque() {
		delete[] theData;
	}

	bool empty(void) const {
		if (currElements == 0) {
			return true;
		}
		return false;
	}
	size_t size(void) const {
		return currElements;
	}

	void push_back(const T& value) {
		if (currElements + 1 == capacity) {
			reallocate();
		}
		rearIndex = (rearIndex + 1) % capacity;
		theData[rearIndex] = value;
		currElements++;
	}

	string toString(void) const {
		stringstream toAppendTo;
		
		for (int i = frontIndex; i != rearIndex+1; i = (i + 1) % capacity) {
			toAppendTo << theData[i] << " ";
		}
		string withoutFollowingSpace = toAppendTo.str().substr(0, toAppendTo.str().length() - 1); //remove following space
		return withoutFollowingSpace;
	}

	void push_front(const T& value) {
		if (currElements + 1 ==  capacity) {
			reallocate();
		}

		if (frontIndex == 0) {
			frontIndex = capacity - 1;
		}
		else {
			frontIndex--;
		}
		theData[frontIndex] = value;
		currElements++;

	}

	void pop_front(void) {
		currElements--;
		frontIndex = (frontIndex + 1) % capacity;

	}
	T& back(void) {
		return theData[rearIndex];
	}
	T& front(void) {
		return theData[frontIndex];
	}
	T& at(size_t index) {
		size_t indexToReturn;
		indexToReturn = (frontIndex + index) % capacity;
		return theData[indexToReturn];
	}

	void reallocate(void) {
		size_t newCapacity = capacity * 2; //ensure amortized constant time
		T * newData = new T[newCapacity];
		size_t old = frontIndex;
		for (int i = 0; i < currElements; i++ ) {
			newData[i] = theData[old];
			old = (old + 1) % capacity;
		}
		swap(newData, theData);
		delete[] newData;

		capacity = capacity * 2;
		rearIndex = currElements - 1;
	}

	void pop_back(void) {
		currElements--;

		if (rearIndex == 0) {
			rearIndex = capacity - 1;
		} else {
			rearIndex--;
		}


	}


};


#endif // !DEQUE_H

