#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;
template <typename T>
class Node {
public:
	Node* left;
	Node* right;
	T Data;

	Node(T data) {
		this->Data = data;
		left = nullptr;
		right = nullptr;

	}

};


#endif // !NODE_H

