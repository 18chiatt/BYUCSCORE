#ifndef QUEUE_H
#define QUEUE_H
#include"Deque.h"

template <typename T>
class Queue {
private:
	Deque<T> queue;
public:
	void push(T value) {
		queue.push_back(value);
	}
	void pop(void) {
		queue.pop_front();
	}
	T front(void) {
		return queue.front();
	}
	int size(void) {
		return queue.size();
	}
	bool isEmpty(void) {
		return queue.empty();
	}
	string toString(void) {

		return queue.toString();
	}
	T at(int index) {
		return queue.at(index);
	}


};
#endif // !QUE_H

