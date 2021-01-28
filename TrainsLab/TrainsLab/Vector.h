#ifndef VECTOR_H
#define VECTOR_H
#include"Deque.h"
template <typename T>
class Vector {


private:
	Deque<T> vector;

public:
	void push_back(T value) {
		vector.push_back(value);
	}
	T& at(size_t index) {
		return vector.at(index);
	}
	void pop_back(void) {
		vector.pop_back();
	}
	bool isEmpty(void) {
		return vector.empty();
	}
	int size(void) {
		return vector.size();
	}
	string toString(void) {
		return vector.toString();
	}
	T at(int index) {
		return vector.at(index);
	}


};

#endif // !VECTOR_H
