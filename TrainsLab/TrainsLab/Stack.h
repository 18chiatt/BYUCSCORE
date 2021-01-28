#ifndef STACK_H
#define STACK_H
#include"Deque.h"
template <typename T>
class Stack {
private:
	Deque<T> stack;
public:
	void push(T value) {
		stack.push_back(value);

	}
	void pop(void) {
		stack.pop_back();
	}
	T& top(void) {
		return stack.back();
	}
	string toString(void) {
		return stack.toString();
	}
	int size(void) {
		return stack.size();
	}
	bool isEmpty(void) {
		return stack.empty();
	}
	T at(int index) {
		return stack.at(index);
	}


};

#endif // !STACK_H
